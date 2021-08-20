David:
This file contains the entire auto-detect logic from the QNG driver.
It first tests for a valid device on some port without using interrupt,
then tests to see if an interrupt is enabled for it.  If not, the driver
will operate in polling mode.

The driver assumes that only one QNG device is attached, and will operate
with only one.  If the device triggers more than one interrupt, this will be
flagged.

The code for interrupt testing includes a complete example of setting up
and removing an interrupt routine.  I didn't include the routines that we
use for the actual data path in the driver, since they do the same
thing and these are easier to understand.


; ******************************************************************
; Init procedure begins here-- this is the last device driver procedure
; All code from here on is cleared after init is done  PART 2
Initdata:							;data section just for init
lpts		dw		0				;pointer to LPT addresses- temp
lpta		dw		3	dup(?)		;3 lpt address words
lptrate		dw		3	dup(?)		;3 lpt rate counters
lptlast		dw		3	dup(0)		;last lpt status- byte 0 only
lastchg		dw		3	dup(0)		;direc of last ACK change- byte 0
sumtim0n	dw		3	dup(0)		;n data changes during ack lo
sumtim1n	dw		3	dup(0)		;n data changes during ack hi
timval		dw		0				;timer value for wait loops
timcnt		db		0				;counter to count 19 loops
xx			dw		0
clocktiml	dw		0				;accum for avg clock time
clocktimh	dw		0				;hi bits
clocktimx	dw		0				;max
diset		db		0				;1 if D or I set manually
; variables for serial correlation measurement
lastt0		dw		3				;last nibble, saved, in bit7-4 (rest=0)
lptxor		dw		3	dup(?)		;cumulative T factor for correl
lptnn		dw		3	dup(?)		;cumulative n/4 for correl
serials		dw		3	dup(0)		;serial correlation values
cscloops	db		1				;repetition counter
badchans	db		1
; variables for interrupt routine testing
intcnt5		dw		0				;n interrupts in inthand5
intcnt7		dw		0				;n interrupts in inthand7
intcntd		dw		0				;n clocks on device
intrise5	dw		0				;n int5's on rising edge
intfall5	dw		0
intrise7	dw		0
intfall7	dw		0
orgseg5		dw		0				;original segment, offset for int5
orgoff5		dw		0
orgseg7		dw		0				;original segment, offset for int7
orgoff7		dw		0
orgmask		db		0				;PIC mask for 5 & 7
; constants
k37			dw		37
k50			dw		50
sdbuf		dw		10	dup(?)

; INIT procedure
Init		proc	near
			push	es
			push	di

; find the CPU type- 86, 286, 386- set up 'cputype'
			pushf                   ;save flags
            push	sp				;first the 8086 test
			pop		ax				;is 86 if SP decrements before a
			cmp		sp,ax			;value is pushed
			jne		cput_x			;if 86, 186- 'cputype' is already =0
			pushf					;not 86-- now the 286 test
			pop		ax				;bit 14 in the flags reg can't be set
			or		ax,4000h
			push	ax
			popf         			;set flags reg
			pushf					;now read flags
			pop		ax
			test	ax,4000h
			mov		cputype,2
			jz		cput_x   		;if 286
			mov		cputype,3		;if 386 or higher
cput_x:		popf

; is this the 386 version? and are we running in <386? trouble--
			IFE		ver-3
			cmp		cputype,3
			jae		ok386			;if ok
			mov		dx,offset Idbad386a
			call	showstr			;print message
		    mov		dx,offset Idbad386b
			call	showstr
		    mov		dx,offset Idbad386c
			call	showstr
            jmp		badexit
ok386:
            ENDIF

; Is there a fixed device/interrupt# we should install at?
; look at command tail from DEVICE= command line
; should see D=xxx I=x		(device code in hex, I=3..7)
; if either D or I has been set, go into manual mode
; also look for other options: V !
			les		di,[RHPtr]		;ES:DI pts to Request header
			mov		ax,es:[di+rhtailseg]
            mov		di,es:[di+rhtailoffs]
			mov		es,ax
; loop to get 1 parameter setting, es:di is char pntr
fixskip:	inc		di				;skip over device name
			mov		al,es:di		;by skipping all print chars (not sp)
			cmp 	al,20h
			ja		fixskip
			jmp		fixloop
fixlinc:	inc		di
fixloop:	call	scanblks		;skip white space
			jz		fixlinc			;if this is wht sp
			cmp		al,0Ah 			;if 0A or 0D or null, quit
			jz      fixlx
			cmp		al,0Dh
			jz		fixlx
			cmp		al,0
			jnz		fixl2
fixlx:		jmp		fixeol			;eol, no more specs given
fixl2:      call	toupper			;next is command letter, get u.c.
			inc		di   			;get past it
			cmp		al,'V'			;look for single-char commands
			jnz     fixnv
			mov		verbose,1		;V - set verbose mode
			jmp		fixloop
fixnv:		cmp		al,'!'
			jnz		fixnex
			mov		verbose2,1		;! - set extreme verbose mode
			jmp 	fixloop
fixnex:		mov		cl,es:[di]		;get the '=' after command
			inc		di				;points to arg
			cmp		al,'D'
            jnz		fix2
			cmp		cl,'='
			jnz		fixbadf
			call	scanhex			;D, set up device- gets dev code in DX
			mov		devcode,dx      ;will test for 0 later
			inc		diset			;set flag: D setting seen
			jmp		fixloop			;next specifier
fix2:		cmp		al,'I'
            jnz		fix99
			cmp		cl,'='
			jnz		fixbadf
			call	scanhex			;I, get intrr no.
			inc		diset
			cmp		dx,0
			jz		fixiok
			cmp		dx,3			;must be 3..7 or 0
			jb		fixbadf
			cmp		dx,7
			ja		fixbadf
fixiok:		mov		intrrno,dl		;5 or 7
			mov		cl,dl
			mov		al,1
			shl		al,cl			;get mask, 20h or 80h
			mov		intrrmx,al
			add		dl,8
			mov		intrrcd,dl		;0D or 0F
			jmp 	fixloop
; bad format seen in command tail- quit here, don't load driver
fixbadf:	mov		dx,offset Idbadfmt
			call	showstr
			jmp		badexitm
; unknown command char, skip over
fix99:		jmp 	fixlinc
; end of command tail scan
; if D or I was set, do manual device code setup
fixeol:		cmp		diset,0
			jz		fixdend			;no D or I
			mov		dx,devcode
			cmp		dx,0			;manual setting: is devcode valid
			jz		fixbadf			;no
			mov		al,0FFh			;yes, turn on power to dev
			out		dx,al
			add		dx,2			;and turn intrr off
			mov		al,0
			out		dx,al
			jmp		idisset			;then skip auto-detect
fixdend:

; Auto-detect logic
; How many parallel interface cards are enabled?
; Check the 3 BIOS words at 40:8,  40:A,  40:C
; for each installed port, try to activate a QNG device on that port
; (power up, wait, look at data rate)
			mov		dx,offset Idports
			call	showstr			;print "parallel ports Installed at..
			mov		ax,40h			;look at 40:8 40:A 40:C
			mov		es,ax 			;first copy all 3 wds into local space
			mov		ax,es:[8]
			mov		lpta,ax
			mov		ax,es:[0Ah]
			mov		lpta+2,ax
			mov		ax,es:[0Ch]
			mov		lpta+4,ax
			mov		[lpts],0		;pointer to scan list

piloop:		mov		bx,[lpts]
			cmp		lpta[bx],word ptr 0	;get contents of BIOS word
			jz		pinoc			;if no code here
			mov		dx,lpta[bx]		;if there is a code
			mov		al,0FFh			;turn power on to device
			out		dx,al
			add		dx,2			;turn off interrupt to device
			mov		al,0			;(at code+2)
			out		dx,al
pinocx:		mov		ax,lpta[bx]		;now show code on screen
			call	showhex 		;erases ax,bx,dx

pinoc:		add		[lpts],2
			cmp		[lpts],6		;when it's 6, you went too far
			jl		piloop

; now wait 1 second for device(s) to start operating, see which have data
; also in this loop, find out how long the clock tick takes (avg & max)
			mov		cl,0
			mov		clocktiml,0
			mov		clocktimh,0
			mov		clocktimx,0
			mov		bx,0FFFFh
wait1s:		mov		al,0			;look at system timer 0
			out		43h,al			;latch counter 0
			in		al,40h			;get low byte
			mov		ah,al
			in		al,40h			;get hi byte
			xchg	al,ah			;get full word: 'this' value
			xchg	ax,bx			;put this into last
			sub		ax,bx			;compare with last timer
			jae		wait1s			;if it went down, just save & go on
			cmp		ax,clocktimx	;new tick: have time diff
			jb		wsslo			;maintain max value
			mov		clocktimx,ax
wsslo:		add		clocktiml,ax	;maintain sum (32b)
			adc		clocktimh,0
			inc		cl				;if it rose, this is a new tick
			cmp		cl,37			;timer wraps around every 25ms
			jb		wait1s			;if not there yet

; Now wait 1/2 second and count the data rate from all ports
; In this loop we look for 4 things:
; 1-3. an ACK transition on any of the 3 ports
; 4. a timer rollover (52ms)- after the right no seen, quit
; on a positive ACK transition, measure both data rate & serial correlation
; max rate: 65K nibbles in 1/2 sec  =512K bits/sec
; BX scans lpt code words, CL counts time, DX used for dev codes
			mov		timcnt,0
			mov		timval,0FFFFh
waithss:	mov		bx,0			;go thru the device codes first
waiths:		mov		dx,lpta[bx]		;get contents of BIOS word
			test	dx,dx
			jz		pinoc2			;if no code here
			inc		dx				;use code+1
			in		al,dx
			xchg	al,byte ptr lptlast[bx]	;maintain last
			xor		al,byte ptr lptlast[bx]	;did it change
			test	al,040h			;look at bit 6
			jz		pinoc2			;no change
			inc		lptrate[bx]		;yes, count up the rate (on both edges)
			test	lptlast[bx],40h
			jz		pinoc2			;neg transition
			call	accserial		;positive transition, accum correl.
pinoc2:
			add		bl,2			;bh stays at 0
			cmp 	bl,6
			jl		waiths			;do the next code
			mov		al,0			;now look at system timer 0
			out		43h,al			;latch counter 0
			in		al,40h			;get low byte
			mov		ah,al
			in		al,40h			;get hi byte
			xchg	al,ah			;get full word
			cmp		ax,timval		;compare with last timer
			mov		timval,ax		;and replace
			jb		waithss			;if it went down, go back to loop
newtk2:								;if it went up, count a tick
			inc		timcnt
			cmp		timcnt,1		;special case: if cl was 0, this is
			jnz		notfst			;first tick- clear accums
			xor		ax,ax
			xor		bx,bx
newtk0:		mov     lptrate[bx],ax	;loop: clear 3 of everything
			mov		lptnn[bx],ax
			mov		lptxor[bx],-1
			mov		lastt0[bx],ax
			add		bl,2
			cmp		bl,6
			jl		newtk0
notfst:		cmp		timcnt,19
			jae		showresu
			jmp		waithss			;if not there yet

; Show the results on screen, for devices that have nonzero code
; first show data rates
showresu:	mov		dx,offset Idrate
			call	showstr
			mov		bx,0
psrloop:	mov		ax,lpta[bx]		;get contents of BIOS word
			test	ax,ax
			jz		psrnoc			;if no code here
			push	bx
			mov		ax,lptrate[bx]
			mov		dx,0
			shl		ax,1			;mpy by 4 to get bit rate
			rcl		dx,1
			shl		ax,1
			rcl		dx,1
			call	showdec
			pop		bx
psrnoc:		add		bx,2
			cmp		bx,6			;when it's 6, you went too far
			jl		psrloop
			call	showcr
; then show serial correlation info
			cmp		verbose,0
			jz		noshows
			call	showserial
noshows:

; Test all devices to see which ones qualify as QNG
; clear the local BIOS words for devices that don't qualify as QNG
; Also turn off power to all but the first device
; first, weed out the ones with bad data rate
			mov		bx,0
pscloop:	mov		ax,lpta[bx]		;get contents of BIOS word
			test	ax,ax
			jz		pscnoc			;if no code here
			cmp		lptrate[bx],MINRATE	;now see if rate qualifies as QNG
			jae		pscnoc			;yes, keep it
			mov		dx,0			;no, clear its code
			xchg 	dx,lpta[bx]
			mov		al,0 			;and turn off power to it
			out		dx,al			;is now out of the system
pscnoc:		add		bx,2
			cmp		bx,6			;when it's 6, you went too far
			jl		pscloop

; then look at the serial correlations
; you may have to do the sampling over again if any result is bad
			mov		cscloops,2		;do 2x if needed
cscchk:		mov		bx,0			;loop to do 1 iteration of sampling
			mov		badchans,bl		;in this loop we will count bad channels
cscloop:	mov		ax,lpta[bx]		;loop to go thru devices
			test	ax,ax
			jz		cscnext			;if no code here
			call	calserial		;see if serial corr qualifies
			cmp		cl,0
			jnz		cscbadc			;if overflow
			cmp		ax,MINSERIAL	;must be 2..65530 (/10000)
			jb		cscbadc			;too small
			cmp		ax,MAXSERIAL
			ja		cscbadc			;too big
			mov		serials[bx],ax	;if good, store in 'serials'
cscbadc:    cmp		serials[bx],0	;now, do we have a value for this ch
			jnz		cscnext			;yes
			inc		badchans		;no
cscnext:	add		bx,2
			cmp		bx,6
			jl		cscloop

; if there are still devices w/good data rate and bad correlation,
; repeat the sampling process again, try to pick up good values
			cmp		badchans,0
			jz      csgotll			;all good, go on
			dec		cscloops		;bad value- can we try again
			jz		csgotll			;no, that's it- go on
			call	samserial		;yes, do the sampling over again
			cmp		verbose,0
			jz		noshows2
			call	showserial		;show the value(s)
noshows2:	jmp		cscchk

; now clear BIOS words & kill power to devices that don't have good corr
csgotll:	mov		bx,0
csgloop:	mov		ax,lpta[bx]		;loop to go thru devices
			test	ax,ax
			jz		csgnext			;if no code here
			cmp		serials[bx],0	;was there ever a good serial corr value
			jnz		csgnext			;yes
			mov		dx,0			;no, clear its code
			xchg 	dx,lpta[bx]
			mov		al,0 			;and turn off power to it
			out		dx,al			;is now out of the system
csgnext:	add		bx,2
			cmp		bx,6
			jl		csgloop

; Choose which of the remaining devices will be the primary device
; that will be the last that is still in the list
; (i.e. it has data rate=ok and serial corr=ok)
; if more than one, power others down but leave them in the list
			mov		bx,4			;work backwds
selloop:	mov		dx,lpta[bx]		;loop to go thru devices
			test	dx,dx
			jz		selnext			;if no code here
			cmp		devcode,0		;ok, good code- is it the first seen
			jz		selfst			;yes, save it as primary device
			mov		al,0			;no, turn power off
			out		dx,al			;but leave it in the list
			jmp		selnext
selfst:		mov		devcode,dx		;first QNG device seen- save dev code
selnext:	sub		bx,2
			jge		selloop

; At this point there should be a valid (nonzero) dev code
; if not, exit now & don't load driver
			cmp		devcode,0			;was there a nonzero dev code
			jnz		devcdok				;yes
			mov		dx,offset Idnone	;no, complain
			call	showstr
badexitm:	mov		dx,offset Idnoneb	;print "driver not loaded"
			call	showstr
badexit:	pop		di					;error- set up for exit
            pop		es
			mov		word ptr es:[di+14],offset Header	;set up address
			mov		word ptr es:[di+16],cs				;for end of code
            mov		byte ptr es:[di+13],0				;N units
            and		hattr,7FFFh							;clear char dev bit
			xor		ax,ax
			ret
devcdok:

; find out which interrupt is active- 5, 7
; (everything up to here has been done w/o interrupt)
; set up temporary handlers for both interrupts, take data for 1/2 sec
; count the no of interrupts you get
; here, power is still on only to the primary device
			push	ds				;get old int5 vector
			mov     ah,GetIntVect   ;dos command code => AH
			mov     al,IRQ5         ;interrupt number => AL
			int     21h				;get current vector (in ES:BX) and
			pop		ds
			mov     orgoff5,bx	    ; save it for
			mov     orgseg5,es	    ; later return
			push	ds				;set new int5 vector (DS:DX)
			mov		dx,offset inthand5
			mov     ah,SetIntVect   ;dos command code => AH
			mov     al,IRQ5         ;interrupt number => AL
			int     21h             ;make it so number one
; set up temorary IRQ7 handler
			mov     ah,GetIntVect       ;get old int7 vector
			mov     al,IRQ7             ;interrupt number => AL
			int     21h					;get current vector (in ES:BX) and
			pop		ds
			mov     orgoff7,bx	        ; save it for
			mov     orgseg7,es	        ; later return
			push	ds					;set new int7 vector (DS:DX)
			mov		dx,offset inthand7
			mov     ah,SetIntVect       ;dos command code => AH
			mov     al,IRQ7             ;interrupt number => AL
			int     21h                 ;make it so number one
			pop		ds
;unmask irq7 and irq5 in PIC
			mov		dx,21h				;get address of PIC
			IN    	AL,dx        		; get contents
			mov   	orgmask,al   		; save old contents
			AND   	AL, not 0A0H   		; set off the bit for IRQ7 & 5
			OUT   	DX, AL        		; send it to the controller
;enable interrupt in the device
			mov		dx,devcode			;enable intrrs
			add		dx,2				;37A
			mov		al,10h
			out		dx,al
; wait 1/4 second, counting the transitions we see on device
; let both interrupt routines count interrupts at the same time
			mov		ch,0			;CH: counts to 9 timer wraparounds
			mov		intcntd,0
			mov		intrise5,0
			mov		intfall5,0
			mov		intrise7,0
			mov		intfall7,0
			mov		bx,0FFFFh		;BX: last timer value
			mov		dx,devcode
			inc		dx				;DX: device code
			in		al,dx
			mov		cl,al			;CL: last device input byte
iwaiths:    in		al,dx			;first, has device transitioned
			xchg	al,cl			;save this, get last
			xor		al,cl			;was there a change in bit 6
			test	al,040h
			jz      noxqs			;no
			inc		intcntd			;yes
noxqs:		mov		al,0			;look at system timer 0
			out		43h,al			;latch counter 0
			in		al,40h			;get low byte
			mov		ah,al
			in		al,40h			;get hi byte
			xchg	al,ah			;get full word
			cmp		ax,bx			;compare with last timer
			mov		bx,ax			;(doesnt affect carry)
			jb		iwaiths			;if it went down, just replace
			inc		ch
			cmp		ch,9
			jb		iwaiths			;if not there yet
; finally disable interruptds and restore both interrupt handlers
			mov		dx,devcode			;disable intrr in device
			add		dx,2
			mov		al,0
			out		dx,al
; mask irq5 & irq7 in the PIC
			MOV   	DX, 21H       	;address of the PIC
			in		al,dx			;get present contents
			mov		ah,orgmask
			and		ah,0A0h			;get only 2 bits from original mask
			or		al,ah
			OUT  	DX, AL        	;set it
; restore IRQ5 and IRQ7 vectors
			push	ds				;restore old int5 vector
			mov		dx,orgoff5	    ;get the original vector
			mov		ax,orgseg5
			mov     ds,ax
			mov     ah,SetIntVect   ;dos command code => AH
			mov     al,IRQ5         ;interrupt number => AL
			int     21h		        ;set original vector
			pop		ds
			push	ds				;restore old int7 vector
			mov		dx,orgoff7	    ;get the original vector
			mov		ax,orgseg7
			mov     ds,ax
			mov     ah,SetIntVect   ;dos command code => AH
			mov     al,IRQ7         ;interrupt number => AL
			int     21h		        ;set original vector
			pop		ds
; show the counts on 5 and 7
			shr		intcntd,1
			cmp		verbose,0
			jz		noshowi
			mov		dx,offset Idintrr	;"interrupt"
			call	showstr
			mov		ax,intcntd		;device
			call	showdeca
			mov		dx,offset Iditot
			call	showstr
			mov		ax,intcnt5		;int5
			call	showdeca
			mov		dx,offset Idirise
			call	showstr
			mov		ax,intrise5		;also rising/falling stats
			call	showdeca
			mov		dx,offset Idifall
			call	showstr
			mov		ax,intfall5
			call	showdeca
			mov		dx,offset Iditot
			call	showstr
			mov		ax,intcnt7		;int7
			call	showdeca
			mov		dx,offset Idirise
			call	showstr
			mov		ax,intrise7		;also rising/falling stats
			call	showdeca
			mov		dx,offset Idifall
			call	showstr
			mov		ax,intfall7
			call	showdeca
			call	showcr
; choose which interrupt to use (if any)
noshowi:	mov		ax,intcnt5		;now, which intrr do we choose
			sub		ax,intcntd  	;get abs(count5 - count)
			jae		i5big
			neg		ax
i5big:		cmp		ax,ICMATCH		;is it within 8 counts
			ja		i5no			;no
			mov		intrrno,5
			mov		intrrcd,IRQ5	;code
			mov		intrrmx,020h	;mask for PIC
i5no:		mov		ax,intcnt7		;now do the same for int7
			sub		ax,intcntd  	;get abs(count7 - count)
			jae		i7big
			neg		ax
i7big:		cmp		ax,ICMATCH		;is it within 8 counts
			ja		i7no			;no
			cmp		intrrno,0		;yes- has it already been set
			jz		i7yes
			mov		dx,offset Idintboth
			call	showstr			;"both interrupts active"
i7yes:		mov		intrrno,7
			mov		intrrcd,IRQ7
			mov		intrrmx,080h
i7no:

; Show final choice of device code & interrupt
; also set up the interr vector if intrr is used
; note: enter here if Dev, Intrr are set manually
;	set up: devcode (!=0), intrrno, intrrcd, intrrmx,
;	turn on power to dev, turn off intrr in dev
idisset:	cmp		intrrno,0		;see if neither intrr is active
			jnz		i57ok
			mov		dx,offset Idintnone
			call	showstr				;say "polling mode"
			mov		pollmode,1			;was loaded =0
i57ok:		mov		dx,offset Iddevc	;"device"
			call	showstr
			mov		ax,devcode			;dev code
			call	showhex
			mov		dx,offset Iddevi	;"Interrupt"
			call	showstr
			mov		dl,intrrno			;interrupt no
			cmp		dl,0
			jz		nosetvect
			call	setintvct			;set up the intrr vector
nosetvect:  mov		dl,intrrno
			add		dl,'0'
			call	showc
			call	showcr

; show logon message on the screen- "QNG driver loaded"
			cmp		verbose,0
			jz		noshowa
			mov		dx,offset Ident
			call	showstr
			mov		ax,cs
			call	showhex			;tell us where it loaded
			mov		ax,offset inthand
			call	showhex			;(offset is to interrupt handler)
			mov		dx,offset Idcputype
			call	showstr			;also tell CPU type
			mov		al,cputype
			mov		ah,0
			call	showdeca
			call	showcr
noshowa:

; misc. jobs
			mov		ax,zlimit		;set up zlimit2
			shl		ax,1
			mov		zlimit2,ax

; lastly, fiddle with the BIOS parallel port control words
; to remove this port from the list of printers
; if user manually specs a dev code that isn't in list, do nothing
			mov		ax,40h
			mov		es,ax
			mov		dx,devcode		;look for devcode in the list
            mov		cl,es:[11h]		;get equipment word, hi byte
			rol		cl,1			;get n parallel ports, into bit 0,1
            rol		cl,1
            and		cl,3
            jz		fxportx			;if 0 (shouldn't happen)
            shl		cl,1			;count*2
            mov		bx,0
fxportl:	cmp		es:[8][bx],dx	;loop to search for devcode
			jz		fxportf			;if found
            add		bx,2			;not found, go to next
            cmp		bl,cl
            jb		fxportl
            jmp		fxportx			;if not in list (shouldn't happen)
fxportf:    sub		cl,2			;new count is 2 less
fxportg:	cmp		bl,cl			;does BX still pt to valid slot
			jae		fxporth			;no, quit
			mov		ax,es:[8+2][bx]	;yes, shuffle rest of list down
            mov		es:[8][bx],ax
            add		bx,2
            jmp		fxportg
fxporth:	mov		word ptr es:8[bx],0		;clear new end slot
            sub		byte ptr es:[11h],40h	;adjust count in equip wd
fxportx:

; set up address for end of code, and return
			pop		di
			pop		es
			mov		word ptr es:[di+14],offset initdata	;set up address
			mov		word ptr es:[di+16],cs				;for end of code

			xor		ax,ax
			ret
Init		endp

; ----------- setintvct -- set up final interrupt vector (done once)
; uses global: 'intrrcd' (interrupt code)
setintvct:	push	ds				; get previous interrupt vector,
			mov		al,intrrcd      ; save it locally
			mov     ah,GetIntVect   ;dos command code => AH
			int     21h				;get current vector (in ES:BX) and
			pop		ds
			mov     word ptr old_intv,bx	    ; save it for
			mov     word ptr old_intv+2,es	    ; later info

;set new interrupt vector to use our int handler
; note- int vector passed in DS:DX, DS is already set (=CS)
			mov		dx,offset inthand	;get offset
			push	ds
;			mov     ax,SEG _TEXT
;			mov     ds,ax			;passed in DS:DX
			mov     ah,SetIntVect   ;dos command code => AH
			mov     al,intrrcd      ;interrupt number => AL
			int     21h             ;make it so number one
			pop		ds
			retn

; Device interrupt  routine for testing INT5
inthand5   PROC
		;--- save machine state ---
		cli	        				;disable interrputs
		push	ax					;note: only AX,DX pushed
		push	dx
		push    ds
		;--- load DS with data segment for this block of data ---
		push	cs
		pop		ds
		;-- incr the interrupt count
		inc		intcnt5
		;-- did this intrr happen on rise or fall of ACK?
		mov		dx,devcode
		inc		dx
		in		al,dx				;look at ACK
		test	al,40h
		jnz		int5hi				;is hi
		inc		intfall5			;is lo
		jmp		int5ex
int5hi:	inc		intrise5
int5ex:
		;--- acknowledge the interrupt ---
		mov     al,EOI             	;eoi to interrupt controller
		out     OCR,al          ;
		;--- restore machine state ---
		pop   	ds       			;restore registers
		pop		dx
		pop		ax
		sti             			;restore interrupt
		iret
inthand5 endp

; Device interrupt  routine for testing INT7
inthand7   PROC
		;--- save machine state ---
		cli	        				;disable interrputs
		push	ax
		push	dx
		push    ds
		;--- load DS with data segment for this block of data ---
		push	cs
		pop		ds
		;-- incr the interrupt count
		inc		intcnt7
		;-- did this intrr happen on rise or fall of ACK?
		mov		dx,devcode
		inc		dx
		in		al,dx				;look at ACK
		test	al,40h
		jnz		int7hi				;is hi
		inc		intfall7			;is lo
		jmp		int7ex
int7hi:	inc		intrise7
int7ex:
		;--- acknowledge the interrupt ---
		mov     al,EOI             	;eoi to interrupt controller
		out     OCR,al          ;
		;--- restore machine state ---
		pop    	ds       			;restore registers
		pop		dx
		pop		ax
		sti             			;restore interrupt
		iret
inthand7 endp

; SAMSERIAL -- wait 1/2 second sampling for serial correlation
samserial:
			mov		timcnt,0
			mov		timval,0FFFFh
samshss:	mov		bx,0			;go thru the device codes
samshs:		mov		dx,lpta[bx]		;get contents of BIOS word
			test	dx,dx
			jz		samoc2			;if no code here
			inc		dx				;use code+1
			in		al,dx
			xchg	al,byte ptr lptlast[bx]	;maintain last
			xor		al,byte ptr lptlast[bx]	;did it change
			test	al,040h			;look at bit 6
			jz		samoc2			;no change
			test	lptlast[bx],40h
			jz		samoc2			;neg transition
			call	accserial		;positive transition, accum correl.
samoc2:
			add		bl,2			;bh stays at 0
			cmp 	bl,6
			jl		samshs			;do the next code
			mov		al,0			;look at system timer 0
			out		43h,al			;latch counter 0
			in		al,40h			;get low byte
			mov		ah,al
			in		al,40h			;get hi byte
			xchg	al,ah			;get full word
			cmp		ax,timval		;compare with last timer
			mov		timval,ax		;and replace
			jb		samshss			;if it went down, go back to loop
									;if it went up, count a tick
			inc		timcnt
			cmp		timcnt,1		;special case: if cl was 0, this is
			jnz		snotfst			;first tick- clear accums
			xor		ax,ax
			xor		bx,bx
snewtk0:							;loop: clear 3 of everything
			mov		lptnn[bx],ax
			mov		lptxor[bx],-1
			mov		lastt0[bx],ax
			add		bl,2
			cmp		bl,6
			jl		snewtk0
snotfst:	cmp		timcnt,19
			jae		samresu
			jmp		samshss			;if not there yet
samresu:	retn

; ACCSERIAL -- accumulate serial correlation info
; bx: index to device words, must be saved
; lptlast[bx] contains last data byte read
accserial:
			mov		al,byte ptr lptlast[bx]	;get byte
			mov		ah,al
			and		al,0B8h			;clear bit 6
			and		ah,038h			;get just lower 3
			add		al,ah			;shift lower 3 left 1, next to bit 7
			mov		ah,al			;2 copies of current nibble
			mov		ch,byte ptr lastt0[bx]	;get last
			mov		byte ptr lastt0[bx],ah	;replace last
			mov		cl,4
			shr		ch,cl			;shift R 4
			and		ch,08h			;msb only, please
			or		ah,ch			;add last into ah
			shl		ah,1			;AH has older bits in new position
			xor		al,ah			;now, how many changed
			cmp		lptnn[bx],0		;first, is this first nibble
			jnz		acbits			;no
			and		al,0E0h			;yes, disable lsb of change
acbits:		xor		cx,cx
acbitc:		shl		al,1			;do a bit count on AL
			adc		cl,0			;if there was a carry, add it to CL
			test	al,al			;repeat until AL=0
			jnz		acbitc
			shl		cx,1			;result x2
			sub		cx,4			;subtract constant n=4
			add		lptxor[bx],cx	;add it into the T accum
			jno		acbit2			;no ovflow
			sub		lptxor[bx],cx	;overflow, undo the operation
acbit2:
			inc		lptnn[bx]		;increment n/4
			retn

; CALSERIAL -- calculate a serial correlation
; bx: pointer to device words, must be saved
; returns result in AX (ten-thousandths) 0..65535
; note- this returns CL=0 if ok, 1 if overflow
calserial:
			cmp		lptnn[bx],0		;is N=0?
			jnz		csvalid			;no
			mov		ax,0			;yes, return 0 result- special case
			retn
csvalid:	mov		ax,lptxor[bx]	;start with the 'T' term
			test	ax,ax			;first take abs val
			jns		cspos
			neg		ax				;if neg
cspos:		cmp		ax,1310			;now test overflow limit 65536/50
			jbe		csilim			;if ok
csovflo:	mov		cl,1    		;illegal, return ovflo flag
			retn					;(this means it won't fit in 32b)
; find 2 factors: T*50 and T*50- each is a single precision value
; the product of them will be T^2 *10000, double precision
; because T is already scaled x2
csilim:		mul		k50				;find T*50
			mov		cx,ax			;save result
			mul		cx				;now get T^2 *10000 in DX:AX
			mov		cx,lptnn[bx]	;add N/2 for rounding
			shr		cx,1
			add		ax,cx			;double pr. add
			adc		dx,0			;DX:AX now has dividend
			cmp		dx,lptnn[bx]	;now, will result be > 65535
			jae		csovflo			;yes, overflow error
			div		lptnn[bx]		;divide by N/4
			mov		cl,0			;overflow =0
csdivz:		retn

; SHOWSERIAL -- show serial correlation results
showserial:
			mov		dx,offset Idcorr
			call	showstr
			mov		bx,0
ssrloop:	mov		ax,lpta[bx]		;get contents of BIOS word
			test	ax,ax
			jz		ssrnoc			;if no code here
			call	calserial		;ok, get serial corr, in AX
			cmp		cl,0			;overflow?
			jz		ssnov			;no, ok
			mov		dx,offset Idssov
			call	showstr
			jmp		ssrnoc
ssnov:		call	showdec5		;show corr value
ssrnoc:		add		bx,2
			cmp		bx,6			;when it's 6, you went too far
			jl		ssrloop
			call	showcr
			retn

