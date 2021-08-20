; TESTS.ASM -- assembly module for test & diagnostic programs
; "B2" version, with bit transition counting
; link this module with test program in C
; all routines here are FAR routines
; note: requires 286 or higher, uses 16 interrupt system

; Options and modes
XXB2		EQU		0				;compute alternate B2,B23-B27 sums
FORCEDAT	EQU		0				;include code to force test data str
EXACT		EQU		0  				;exact nibble testing
INTTIMES	EQU		0				;measure time between interrupts
PSEUDO		EQU		0				;enable forcing pseudo random data
FASTINT5	EQU		0				;use streamlined INT5 handler
B237		EQU		0				;take data on B23-B27
AUTOCORR	EQU		0				;take auto correlation 1-8
BTRANS		EQU		1				;Bit transitions are 1's, 0's (Princeton)
MONKTEST	EQU		0
ENTEST		EQU		0				;enable entropy test
ENBITS		EQU		14				;n bits for entropy test, <=14
ENINITP		EQU		5				;n complete cycles to init
ENTESTP		EQU		64				;n complete cycles to test
									;MUST BE power of 2 and >= 4

			.286
			.MODEL	large
			.DATA
_devcodes	dw		12	dup(0)		;dev codes to test
_ndevs		dw		0				;no of dev codes
			public _devcodes,_ndevs
; variables for clock testing
eventiml	dw		0
eventimh	dw		0
evennn		dw		0
oddtiml		dw		0
oddtimh		dw		0
oddnn		dw		0
clocktimt	dw		37				;clock timer, length of test
_clocktime	dw		0				;result (mean)
_clocktimx	dw		0				;max
kp419		dw		27460			;0.419 * 65536
			public	_clocktime,_clocktimx

; variables for rate measurement
ndevbs		dw		0				;ndevs *2 (n bytes)
lpts		dw		0				;pointer to LPT addresses- temp
_lptrate	dw		12	dup(0)		;3 lpt rate counters
lptlast		dw		12	dup(0)		;last lpt status- byte 0 only
timval		dw		0				;timer value for wait loops
timcnt		dw		0				;counter to count 19 loops
_nthrul		dw		0				; n times thru the sampling loop (d.p.)
nthruh		dw		0
public 		_lptrate,_nthrul

; variables for serial correlation measurement
lastt0		dw		12	dup(0)		;last nibble, saved, in bit7-4 (rest=0)
_lptxor		dw		12	dup(?)		;cumulative T factor for correl
_lptnn		dw		12	dup(?)		;cumulative n/4 for correl
cscloops	db		1				;repetition counter
badchans	db		1
			public	_lptnn,_lptxor

; variables for interrupt routine testing
; note: if you change 'intnos', also change intvect, intnews, intnewo,
;		new_msk,
_nints		dw		4				;no of interrupts in basic list
_intnos		dw		3,4,5,7,10,11,12,15					;outside "int no"
intvect		dw		0Bh,0Ch,0Dh,0Fh,72h,73h,74h,77h		;vector no
intnews		dw      seg inthand3,seg inthand4			;new intrr addr- segment
			dw		seg inthand5,seg inthand7
intnewo		dw		offset inthand3,offset inthand4		;new intrr addr- offset
			dw		offset inthand5,offset inthand7
sawnews		dw      seg sawhand3,seg sawhand4			;new intrr addr- segment
			dw		seg sawhand5,seg sawhand7
sawnewo		dw		offset sawhand3,offset sawhand4		;new intrr addr- offset
			dw		offset sawhand5,offset sawhand7
intolds		dw		10	dup(0)  	;old seg
intoldo		dw		10  dup(0)		;old offset
_intcnts	dw		10	dup(0)		;n counts seen during tests
_intrise	dw		10	dup(0)		;(ints on rising edge) - (ints on fall)
new_msk		db		0B8h			;PIC mask for 3, 4, 5, 7
old_msk		db		0				;original PIC mask
_devactive	dw		0				;dev code of active device (from caller)
EOI         equ     20h             ;non-specific EOI
OCR         equ     20h             ;Location of 8259 #1 operational register
SetIntVect  equ     25h             ;BIOS function
GetIntVect  equ     35h             ;BIOS function
ReadIRR		equ		0Ah				;outpt this to 20h to read from 20h
ReadISR		equ		0Bh				;same (8259 commands)
public 		_nints,_intnos,_intcnts,_intrise,_devactive

; variables for long-term interrupt (SAW) handlers
; note: indexed variables must all be of size 2, indexed by interrupt#
; they are 16 bit values and will overflow easily
; use "getidat()" regularly to clean them out and rezero
thisdat		dw		0				;latest data nibble
_overflow	dw		0				;1= overflow has occurred
ilasts		dw		10	dup(0)		;last 16 bits, msb is latest
icount		dw		10	dup(0)		;intrr count (not bit cnt, as in 'saw')
ib2			dw		10	dup(0)		;sum of 0's & 1's for nibble
ib23		dw		10	dup(0)		;sum of 0's & 1's for bit 3
ib24		dw		10	dup(0)		;sum of 0's & 1's for bit 4
ib25		dw		10	dup(0)		;sum of 0's & 1's for bit 5
ib27		dw		10	dup(0)		;sum of 0's & 1's for bit 7
icor1		dw		10	dup(0)		;serial corr accum 1
icor2		dw		10	dup(0)		;serial corr accum 2
icor3		dw		10	dup(0)		;serial corr accum 3
icor4		dw		10	dup(0)		;serial corr accum 4
icor5		dw		10	dup(0)		;serial corr accum 5
icor6		dw		10	dup(0)		;serial corr accum 6
icor7		dw		10	dup(0)		;serial corr accum 7
icor8		dw		10	dup(0)		;serial corr accum 8
_idevco		dw		10	dup(0)		;dev code for each interrupt
tables_ok	db		0				;1= tables have been init'd
			public	_idevco,_overflow

; variables set up by "getidat", for 1 device
_icount		dw		0				;external copy of icount
_ib2		dw		5	dup(0)		;external copies of ib2, ib23..ib27
_icor		dw		8	dup(0)		;external copies of icor1..icor8
public _icount,_ib2,_icor

; lookup tables for fast data accumulation
addb23		db		16	dup(?)		;add to ib23: +1 or -1
addb24		db		16	dup(?)		;add to ib24: +1 or -1
addb25		db		16	dup(?)		;add to ib25: +1 or -1
addb27		db		16	dup(?)		;add to ib27: +1 or -1
addb2		db		16	dup(?)		;add to ib2: -4 to +4
bitfix		db		256	dup(?)		;table to fix up bits 3-5,7
addcor1		db		256	dup(?)		;add to serial corr 1, -4 to +4
addcor2		db		256	dup(?)		;add to serial corr 2
addcor3		db		256	dup(?)		;add to serial corr 3
addcor4		db		256	dup(?)		;add to serial corr 4
addcor56	db		4096 dup(?)		;add to 5 (lo bits) and 6 (hi bits)
addcor78	db		4096 dup(?)		;add to 7 (lo bits) and 8 (hi bits)
zbitcnt		db		256	dup(?)		;zero bit count of 8-bit byte
addb2tr		db		0,-1,1,0,-1,-2,0,-1,1,0,2,1,0,-1,1,0
addntr		db		0,1,1,0,1,2,2,1,1,2,2,1,0,1,1,0

; variables for monkey testing
; note: main prog must allocate bitmaps before setting monkactive[]
_monkactive	dw		10	dup(0)		;1= taking data, 2=done
nibcnt		dw		10	dup(0)		;counts 4 nibbles in 16b 'keystroke'
_keycnt		dw		10	dup(0)		;counts n 'keystrokes' in 'word'
_keycnth	dw		10	dup(0)		;hi bits
monksave	dw		10	dup(0)		;keys being saved to make word
_bitmapno	dw		10	dup(-1)		;what bitmap it's using
bitmasks	db		1,2,4,8,10h,20h,40h,80h
_monkbits	dd		0				;n blank bits returned from monk_sum
_mbank		dd		5	dup(0)		;5 mem banks for bitmaps
_nmbanks	dw		0				;no of banks allocated
_mtestno	dw		2				;which test: 2-3-4-5
			public	_mbank,_monkbits,_monkactive,_nmbanks,_bitmapno,_mtestno
			public	_keycnt,_keycnth

; variables for entropy test
_entactive	dw		10	dup(0)		;1= taking data, 2=done
_entcnt		dw		10	dup(0)		;counts n blocks in average
_entcnth	dw		10	dup(0)		;hi bits
_ebitmapno	dw		10	dup(-1)		;what bitmap it's using
entacum		dw		10	dup(0)		;48 bit accumulators- lo bits
_entacuma	dw		10	dup(0)		;midd
_entacumb	dw		10	dup(0)		;hi
_ebank		dd		5	dup(0)		;5 mem banks for bitmaps
_nebanks	dw		0				;no of banks allocated
_enttestn	dd		ENTESTP shl ENBITS	;no of complete cycles for test
_entin		dd		0
_entout		dd		0
_entouthi	dw		0				;1 more wd
intpart		dw		0				;integer part of log2
ratio		dw		0
			public	_entactive,_entacuma,_entacumb
			public	_entcnt,_entcnth,_enttestn
			public	_entin,_entout,_entouthi,_ebank,_nebanks,_ebitmapno
			INCLUDE	ilog2.asm		;has constants & tables

; variables for pseudo-random generator testing
; note: buffer is allocated by C program, will be far
; note: buffer contains bytes, only low 4bits used of each
_ranbuf		dd		0				;pointer to buffer of 2048 bytes
_ranin		dw		0				;no of next in
_ranout		dw		0				;no of next out
_randoit	dw		0				;0=inactive, else is buffer wrap mask
			public	_ranbuf,_ranin,_ranout,_randoit

; variables for missed-samples testing
lsttimer	dw		12	dup(0)		;timer value at last sample
_stimes		dw		32	dup(0)		;array of times
stimenn		dw		0				;ptr to next to fill
			public	_stimes
; variables for exact-nibble testing
exactn		db		0				;next nibble expected, in B3-0
_exactseq	dw		0				;sequence no of error report
_exactdat	dw		0				;lo: nibble expected  hi: seen
			public	_exactseq,_exactdat

; variables for general testing
testseq		db		0fh,0fh,0fh,0fh,01fh		;test seq
testsn		dw		0				;nibble count (nibbles packed hi-lo)
testsp		dw		0				;working nibble #
_tblin		dw		0				;input, output to table lookups
_tblout		dw		0
_xb2		dd		0				;alternate B2, B23-B27
_xb23		dd		0
_xb24		dd		0
_xb25		dd		0
_xb27		dd		0
_timhist	dw		500	dup(0)		;intrr interval histogram
_t1			dw		0
_t2			dw		0
_t3			dw		0
_t4			dw		0
_t5			dw		0
_t6			dw		0
_t7			dw		0
_t8			dw		0
			public	_tblin,_tblout,_t1,_t2,_t3,_t4,_t5,_t6,_t7,_t8
			public	_timhist
			public	_xb2,_xb23,_xb24,_xb25,_xb27

; variables for normal distribution generator routine
normu		dw		3	dup(0)		;current U value (full 3w)
normx		dw		3	dup(0)
normu2		dw		3	dup(0)		;second U value if needed (full 3w)
normsign	db		0				;hi byte of U
normi		dw		0				;'I' value (note: 16 bits!)
normk		db		0				;'K' value
normt		dw		3	dup(0)		;'T' value
normv		dw		3	dup(0)		;'V' value
normr		dw		3	dup(0)		;'R' value
normc		dw		0				;C for V/T test
normconc	dw		7B47h, 0147h, 0	;constants for algorithm
normcond	dw		1829h, 0DCAAh, 1
_ux			dd		0				;uniform distr arg
_udx		dd		0				;increment for ux
_ucount		dd		0				;count of unif no's used
_ucounthi	dw		0
umpyo		dw		4	dup(0)		;result array
umpyi		dw		3	dup(0)		;temp. input val
recipnc		db		0				;n left shifts to normalize arg
recipdl		dw		0				;divisor lo
recipdh		dw		0				;divisor hi
recipql		dw		0				;quotient lo
recipqh		dw		0				;quotient hi
			public	_ux,_udx,_ucount,_ucounthi
			db		200				;y for I=-1

; constants

			.CODE
; *********** CLOCK_TEST -- measure clock interrupt latency ***********
; wait a preset amount of time, by counting clock rollovers
; "clocktimt" contains no of half cycles (@ 27.5 ms) to wait
; also in this loop, find out how long the clock tick takes (avg & max)
; input parameter: 'clocktimt' value
; return clocktime: mean,   clocktimx: max,  both in microseconds
			public	_clock_test
_clock_test	proc	far
			ARG		nloops:word
			push	bp
			mov		bp,sp
			mov		cx,nloops
			mov		clocktimt,cx
			mov		ax,0
			mov		eventiml,ax
			mov		eventimh,ax
			mov		evennn,ax
			mov		oddtiml,ax
			mov		oddtimh,ax
			mov		oddnn,ax
			mov		_clocktimx,ax
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
;			mov ax,bx				;'inttime' uses these
;			neg ax
			cmp		ax,_clocktimx	;new tick: have time diff
			jb		wsslo			;maintain max value
			mov		_clocktimx,ax
wsslo:      test	cl,1			;is this odd or even cycle
			jz		wsseven			;even, accum into 'eventiml'
			add		oddtiml,ax		;odd, accum into 'oddtiml'
			adc		oddtimh,0
			inc		oddnn
			jmp		wssboth
wsseven:	add		eventiml,ax		;maintain sum (32b)
			adc		eventimh,0
			inc		evennn
wssboth:	dec		cl				;timer wraps around every 25ms
			jnz		wait1s			;if not there yet
; now reduce both sums to means, choose the larger mean
			mov		dx,eventimh
			mov		ax,eventiml
			cmp		evennn,0
			jz		wssevz  		;don't divide by 0
			div		evennn
wssevz:		mov		cx,ax			;save 'even' result
			mov		dx,oddtimh
			mov		ax,oddtiml
			cmp		oddnn,0
			jz		wssodz
			div		oddnn
wssodz:		cmp		ax,cx			;is 'odd' bigger
			jbe		wss22			;no
			mov		cx,ax			;yes, use it
wss22:		mov		ax,kp419		;finally mpy by .838/2
; lastly, scale the max and mean correctly: div by 2, mpy by 0.838
			mul		cx				;result will be in DX
			mov		_clocktime,dx
			mov		ax,kp419
			mul		_clocktimx
			mov		_clocktimx,dx
;			mov ah,48h
;			mov bx,2048
;			int 21h
;			mov _t1,0
;			rcl _t1,1
;			mov _t2,ax
;			mov _t3,bx
			pop		bp
			ret
_clock_test	endp

; ********* RATE_TEST -- test data rate and serial correlation ***********
; (in polling mode) wait 1/2 second and count the data rate from all ports
; input: 1 + no of half-cycles to wait- must be odd
; In this loop we look for 4 things:
; 1-3. an ACK transition on any of the 3 ports
; 4. a timer rollover (27.47ms)- after the right no seen, quit
; on a positive ACK transition, measure both data rate & serial correlation
; BX scans lpt code words, CL counts time, DX used for dev codes
; return results: 'lptxor[]' is sum of the xor's of bits, -constant
;		'lptnn[]' is the nibble count (sample count/4)
;		'lptrate[]' is no of transitions of sq wave (2 x freq)
			public	_rate_test
_rate_test	proc	far
			ARG		nloop2:word
			push	bp
			mov		bp,sp
			mov		ax,nloop2		;get loop count
			mov		clocktimt,ax
			mov		ax,_ndevs		;get ndevs*2 for loop testing
			shl		ax,1
			mov		ndevbs,ax
			mov		timcnt,0
			mov		timval,0FFFFh
waithss:	mov		bx,0			;go thru the device codes
waiths:		mov		dx,_devcodes[bx]	;get dev code
			test	dx,dx
			jz		pinoc2			;if no code here
			inc		dx				;use code+1
			in		al,dx
			xchg	al,byte ptr lptlast[bx]	;maintain last
			xor		al,byte ptr lptlast[bx]	;did it change
			test	al,040h			;look at bit 6
			jz		pinoc2			;no change
			inc		_lptrate[bx]	;yes, count up the rate (2X)
			test	lptlast[bx],40h
			jz		pinoc2			;neg transition
			call	accserial		;positive transition, accum correl.
pinoc2:
			add		bx,2			;bh stays at 0
			cmp 	bx,ndevbs
			jl		waiths			;do the next code
			add		_nthrul,1		;count times thru the loop
			adc		nthruh,0
			mov		al,0			;look at system timer 0
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
			xor		bx,bx			;clear locs indexed by device
newtk0:		mov     _lptrate[bx],ax	;loop: clear n of everything
			mov		_lptnn[bx],ax
			mov		_lptxor[bx],-1
			mov		lastt0[bx],ax
			add		bx,2
			cmp		bx,ndevbs
			jl		newtk0
			xor		bx,bx			;clear locs indexed by intrrupt #
newtk1:		mov		_intcnts[bx],ax
			mov		_intrise[bx],ax
			add		bx,2
			cmp		bx,10*2
			jb		newtk1
			mov		_nthrul,ax
			mov		nthruh,ax
notfst:		mov		ax,timcnt
			cmp		ax,clocktimt
			jae		showresu
			jmp		waithss			;if not there yet
showresu:
			pop		bp
			ret
_rate_test	endp

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
			cmp		_lptnn[bx],0	;first, is this first nibble
			jnz		acbits			;no
			and		al,0E0h			;yes, disable lsb of change
acbits:		xor		cx,cx
acbitc:		shl		al,1			;do a bit count on AL
			adc		cl,0			;if there was a carry, add it to CL
			test	al,al			;repeat until AL=0
			jnz		acbitc
			shl		cx,1			;result x2
			sub		cx,4			;subtract constant n=4
			add		_lptxor[bx],cx	;add it into the T accum
			jno		acbit2			;no ovflow
			sub		_lptxor[bx],cx	;overflow, undo the operation
acbit2:
			inc		_lptnn[bx]		;increment n/4
			retn

; *********** SETINTS routine -- set up interrupt vectors ************
; goes thru the basic list of interrupts available, sets them all up
; saves old interrupt pointers locally
; also enables the interrupt in the PIC chip(s)
; DOES NOT enable the interrupt FF in the device
; if arg=1, enables the basic interrupt handlers
; if arg=2, enables the SAW interrupt handlers
; note- after calling setints, you **MUST** call unsetints to undo
; in this routine, BX is index into the basic interrupt list
			public	_setints
_setints	PROC	far
			ARG		itype:word
			push	bp
			mov		bp,sp
; init the lookup tables if not already done
			cmp		tables_ok,0
			jnz		setint2
			call	inittables
			inc		tables_ok
setint2:	mov		bx,0
; get previous interrupt vector, save it locally
setloop:	push	bx
			mov		ax,intvect[bx]
			mov     ah,GetIntVect   ;dos command code => AH
			int     21h				;get current vector (in ES:BX) and
			mov		ax,bx			;offset
			pop		bx
			mov     intoldo[bx],ax    ; save it for
			mov     intolds[bx],es    ; later return
;			mov _t1,es
;			mov _t2,ax

;set new interrupt vector to use our int handler
; note- int vector passed in DS:DX,
; there can be more than 1 type of int handler
			mov		ax,itype
			mov		dx,intnewo[bx]	;offset for type 1
			mov     cx,intnews[bx]	;segment
			cmp		ax,1
			jz		segt
			mov		dx,sawnewo[bx]	;offset for type 2
			mov     cx,sawnews[bx]	;segment
			cmp		ax,2
			jnz		setexit			;illegal type
segt:		cmp		cx,0
			jz		setexit			;don't do unimplemented handlers
			mov     ax,intvect[bx]  ;interrupt number => AL
			mov     ah,SetIntVect   ;dos command code => AH
;			mov _t3,ax
;			mov _t4,cx
;			mov _t5,dx
			push	ds				;done with DS here
			mov     ds,cx			;passed in DS:DX
			int     21h             ;make it so number one
			pop		ds

; move BX up to next, add 2 for each loop
setexit:	add		bx,2
			mov		ax,_nints
			shl		ax,1
			cmp		bx,ax
			jb		setloop

;unmask the intrrs that were set up in this loop
			MOV   	DX, 21H       	; address of PIC
			IN    	AL, DX        	; get contents
			mov   	old_msk,al   	; save old contents
			mov		ah,new_msk		; get new mask bits
			xor		ah,0FFh			; complement
			AND   	AL, ah		   	; set off the bit for IRQ7
			OUT   	DX, AL        	; send it to the controller

			pop		bp
			ret
_setints	ENDP

; *********** UNSETINTS routine -- restore all interrupt vectors **********
; restores old interrupt pointer from local mem
; also disables the interrupt in the PIC chip(s)
;
			public	_unsetints
_unsetints	PROC	far

; reset the pic masks first:
			MOV   	DX, 21H       	;address of the PIC
			in		al,dx			;get present contents
			mov		ah,old_msk
			and		ah,new_msk		;select the mask bits to use
			or		al,ah			;re-mask any bits that were masked before
			OUT   	DX, AL        	;set it

			mov		bx,0
; restore old intrr vectors
unsloop:	mov		dx,intoldo[bx]	;get the original vector
			mov		cx,intolds[bx]
			mov     ax,intvect[bx]  ;interrupt number => AL
			mov     ah,SetIntVect   ;dos command code => AH
;			mov _t6,ax
;			mov _t7,cx
;			mov _t8,dx
			push	ds
			mov     ds,cx
			int     21h		        ;set original vector
			pop		ds

unsexit:	add		bx,2
			mov		ax,_nints
			shl		ax,1
			cmp		bx,ax
			jb		unsloop

			ret
_unsetints	ENDP

; SHOWC -- show single char on screen- from DL (note***)
showc:		mov		ah,6
			int		21h
			retn


; ************* BASIC INTERRUPT HANDLERS - FOR PRELIMINARY TESTING ********
; Device interrupt  routine for testing INT3
inthand3:
		cli	        				;disable interrputs
		push	bx
		mov		bx,0*2				;index for INT3
		jmp		inthan

; Device interrupt  routine for testing INT4
inthand4:
		cli	        				;disable interrputs
		push	bx
		mov		bx,1*2				;index for INT4
		jmp		inthan

; Device interrupt  routine for testing INT5
inthand5:
		cli	        				;disable interrputs
		push	bx
		mov		bx,2*2				;index for INT5
		jmp		inthan

; Device interrupt  routine for testing INT7
; This routine is complete; the others jump into this after setting index
inthand7   PROC
		;--- save machine state ---
		cli	        				;disable interrputs
		push	bx
		mov		bx,3*2				;index to basic list for INT7
inthan:	push	ax    				;common entry point
		push	dx					;here, b: index to basic intrr list
		push    ds
		;--- load DS with data segment for this block of data ---
		mov		ax,DGROUP
		mov		ds,ax
;		mov dl,'I'
;		call showc
		;-- incr the interrupt count
		inc		_intcnts[bx]
		;-- did this intrr happen on rise or fall of ACK?
		mov		dx,_devactive
		test	dx,dx
		jz		int7ex				;no op if dev code not set
		inc		dx
		in		al,dx				;look at ACK
		test	al,40h
		jnz		int7hi				;is hi
		dec		_intrise[bx]		;is lo
		jmp		int7ex
int7hi:	inc		_intrise[bx]
int7ex:
		;--- acknowledge the interrupt ---
		mov     al,EOI             	;eoi to interrupt controller
		out     OCR,al          ;
		;--- restore machine state ---
		pop    	ds       			;restore registers
		pop		dx
		pop		ax
		pop		bx
		sti             			;restore interrupt
		iret
inthand7 endp

sawhand3:	cli
			pusha
			mov		di,0*2
			jmp		sawhan
sawhand4:	cli
			pusha
			mov		di,1*2
			jmp		sawhan
			IFE		FASTINT5
sawhand5:	cli						;if using regular int5
			pusha
			mov		di,2*2
			jmp		sawhan
			ENDIF
bogus7:		push	ds
			jmp		saw7ex

;************* 'SAW' INTERRUPT HANDLERS- FOR LONG TERM TESTING **********
; Device interrupt  routine for testing INT7
; This routine is complete; the others jump into this after setting index
; note: this handler does math with 16-bit values, which will overflow
;	in a short time; use "getidat" to clean out accums regularly
; note: you MUST set up idevco[] before enabling this handler
; note: uses 286 instructions
sawhand7   PROC
		;--- save machine state ---
		cli	        				;disable interrputs
		pusha
		mov		di,3*2				;index to basic list for INT7
		mov		al,ReadISR			;test for bogus interrupt
		out		20h,al
		in		al,20h				;bit 7=1 if ok
		test	al,80h
		jz		bogus7				;no, skip
sawhan:								;common entry point
		push    ds
		;--- load DS with data segment for this block of data ---
		mov		ax,DGROUP
		mov		ds,ax
		;-- incr the interrupt count
		inc		icount[di]
		;-- find time elapsed since last, put into histogram
		IF INTTIMES
		mov		al,0			;look at system timer 0
		out		43h,al			;latch counter 0
		in		al,40h			;get low byte
		mov		ah,al
		in		al,40h			;get hi byte
		xchg	al,ah			;get full word: 'this' value
		xchg	ax,lsttimer[di]	;put this into last
		sub		ax,lsttimer[di]	;compare with last timer
		shr		ax,1			;units of .8 us
		mov		bx,ax
		cmp		bx,500			;size of table
		jb      sawhist
		mov		bx,499
sawhist: shl		bx,1			;index to histo of words
		inc		_timhist[bx]
		jnz		sawhistn
		dec		_timhist[bx]
sawhistn:
		mov		bx,stimenn
		mov		_stimes[bx],ax
		add		bx,2
		and		bx,63			;32 elements
		mov		stimenn,bx
		ENDIF
		;-- get the data nibble, clean up bits, maintain history
		mov		dx,_idevco[di]
		inc		dx
		in		al,dx
		mov		ah,al
		and		al,0B8h			;clear bit 6
		and		ah,038h			;get just lower 3
		add		al,ah			;shift lower 3 left 1, next to bit 7
		;-- force test data if desired
		IF 		FORCEDAT
		cmp		testsn,0
		jz		notests			;no
		mov		bx,testsp		;yes, get no. of next nibble
		shr		bx,1			;get byte no, carry=0/1
		mov		al,testseq[bx]	;get byte
		jnc		tshib
		shl		al,4			;if c=0, use upper nibble
tshib:  inc		testsp			;then push pointer up
		mov		bx,testsp
		cmp		bx,testsn
		jb		notests
		mov		testsp,0		;if wrap, clear it
		ENDIF
		; -- force data from pseudo-random number gen if desired
		IF		PSEUDO
		cmp		di,2*2			;only on intrr 5
		jnz		nopseudo
		cmp		_randoit,0		;only after C program says go
		jz		nopseudo
		push	es
		les		bx,_ranbuf		;get pointer to buffer
		add		bx,_ranout		;offset + index to nextout
		mov		al,es:[bx]
		pop		es
		shl		al,4			;put in bits 7..3 for use
		mov		bx,_ranout
		inc		bx
		and		bx,_randoit		;wrap
		mov		_ranout,bx
nopseudo:
		ENDIF
		;-- now use the data nibble
notests: and		ax,0F0h			;now in upper 4b of AL
		mov		thisdat,ax			;used only by XXB2
		;--- test for expected nibble if "exact" is on
		IF		EXACT
		cmp		di,3*2				;do this only for int7
		jnz		exacno
		mov		cl,al
		shr		cl,4				;get it in lo bits
		cmp		cl,exactn			;is it what's expected
		jz		exacok
		inc		_exactseq			;error- save error info
		mov		ch,cl
		xchg	cl,exactn			;re-sync to this value
		mov		_exactdat,cx		;save both values
exacok:	dec		exactn				;incr 'expected' to next
		and		exactn,0Fh			;4 bits only please
exacno:
		ENDIF
		;--- combine with last 3 nibbles to get 16bit composite
		xchg	ah,al				;now in b15..12 of AX
		mov		bx,ilasts[di]		;'or' this into 'lasts'
		shr		bx,4
		or		bx,ax
		mov		ilasts[di],bx		;re-stash new 12 bit value
		inc		nibcnt[di]			;count nibbles added to 'keystroke'
		;-- do table lookups that use the last 12 bits as arg
		shr		bx,4
;		mov 	_tblin,bx			;save 12 bit arg for debug
		IF		AUTOCORR
		mov		al,addcor56[bx]		;note: ser corr 5 & 6 combined in 1 table
		mov		cl,al
		and		al,0Fh				;ser corr 5
		sub		al,4        		;range 0..8, make it -4 .. +4
		cbw
		add		icor5[di],ax
		mov		al,cl				;ser corr 6
		shr		al,4
		sub		al,4
		cbw
		add		icor6[di],ax
		mov		al,addcor78[bx]		;note: ser corr 7 & 8 combined in 1 table
		mov		cl,al
		and		al,0Fh				;ser corr 7
		sub		al,4        		;range 0..8, make it -4 .. +4
		cbw
		add		icor7[di],ax
		mov		al,cl				;ser corr 8
		shr		al,4
		sub		al,4
		cbw
;		mov _tblout,ax			;save result for debug
		add		icor8[di],ax
        ENDIF
		;-- do table lookups that use the high 8 bits as arg
		shr		bx,4
        IF		AUTOCORR
		mov		al,addcor1[bx]		;ser corr 1
		cbw
		add		icor1[di],ax
		mov		al,addcor2[bx]		;ser corr 2
		cbw
		add		icor2[di],ax
		mov		al,addcor3[bx]		;ser corr 3
		cbw
		add		icor3[di],ax
		mov		al,addcor4[bx]		;ser corr 4
		cbw
		add		icor4[di],ax
        ENDIF
		;-- do table lookups that use the high (latest) 4 bits as arg
		shr		bx,4
		;-- maintain sums of 1's and 0's
        IF		B237
		mov 	al,addb23[bx]   	;B23
		cbw
		add		ib23[di],ax
		mov 	al,addb24[bx]		;B24
		cbw
		add		ib24[di],ax
		mov 	al,addb25[bx]		;B25
		cbw
		add		ib25[di],ax
		mov 	al,addb27[bx]		;B27
		cbw
		add		ib27[di],ax
        ENDIF
        IF		BTRANS
        mov		al,addntr[bx]		;get actual n 'bits'
        cbw                			;and put it in ib23 for now
        add		ib23[di],ax
        mov		al,addb2tr[bx]		;BTRANS- b2 is sum of transitions
        ELSE
		mov 	al,addb2[bx]		;normal: b2 is sum of 1's - 0's
        ENDIF
		cbw
		add		ib2[di],ax			;add sum of 4
		jno		saw7no
		sub		ib2[di],cx			;don't let it overflow
		mov		_overflow,1
saw7no:
		IF MONKTEST
		;--- monkey tests: is it time to process a 16 bit 'keystroke'
		;--- the latest 16 bits are always in 'ilasts[di]'
		test	_monkactive[di],1	;are we sampling on this interrupt
		jz		jsawno				;no (either done or inactive)
		test	nibcnt[di],3
		jnz		jsawno				;not time yet
		mov		ax,ilasts[di]		;ok, get latest 16 bits
		;-- process a monkey 'keystroke'- in 16 bits of AX
		test	_mtestno,2			;2-letter or 4-letter
		jz		mkey4				;4-letter (4 or 5)
		test	_mtestno,1			;use hi or lo
		jnz		mkey2a				;testno odd=use lo, even=use hi
		shr		ax,6				;use upper 10
		jmp		mkey2b
mkey2a: and		ax,3FFh				;use lower 10
mkey2b:	mov		bx,ax
		xchg	monksave[di],ax		;save in last
		mov		cx,_keycnt[di]		;do we use this key or not
		cmp		cx,2				;special action for keycnt=lo or hi
		jae		monkkc				;ok, use
		mov		dx,_keycnth[di]		;get cx: lo count,  dx: hi count
		mov		ch,dl				;get ch: top 5b,  cl:bottom 8b
		cmp		cx,01
		jb		jmonc				;if first 1 keystroke, don't use
		cmp		cx,2001h			;if no. 2M+1, quit here !!
		jb		monkkc
		mov     _monkactive[di],2	;set flag to 2=done
jsawno: jmp     sawnom
monkkc:	mov		dx,bx				;ax: old, bx: new
		and		dx,1Fh				;DX will have 5b
		and		bx,3E0h				;AX combines other 5 w previous
		shl		bx,5
		or		ax,bx
		jmp		mkey42
; 4-letter test
mkey4:	test	_mtestno,1			;use hi or lo
		jnz		mkey4a				;testno odd=use lo, even=use hi
		shr		ax,11				;use upper 5
		jmp		mkey4b
mkey4a: and		ax,1Fh				;use lower 5, now in AX
mkey4b: mov		bx,monksave[di]		;last 3 keystrokes
		mov		cx,bx
		shl		cx,5
		or		ax,cx
		and		ax,7FFFh			;Ax now has newest 3 keystrokes
		mov		monksave[di],ax
		shr		bx,10				;BX has oldest
		and		bx,1Fh				;5bits
		mov		cx,_keycnt[di]		;do we use this key or not
		cmp		cx,4				;special action for keycnt=lo or hi
		jae		monkkc4				;ok, use
		mov		dx,_keycnth[di]		;get cx: lo count,  dx: hi count
		mov		ch,dl				;get ch: top 5b,  cl:bottom 8b
		cmp		cx,03
jmonc:	jb		monknc				;if first 1 keystroke, don't use
		cmp		cx,2003h			;if no. 2M+1, quit here
		jb		monkkc4
		mov     _monkactive[di],2	;set flag to 2=done
		jmp     sawnom
monkkc4:	mov		dx,bx				;ax: old, bx: new
mkey42:	mov		bx,_bitmapno[di]
		call	monk_test			;put into the bit map
monknc:	inc		_keycnt[di]			;count keystrokes
		jnz		sawnom     			;in double precision
		inc		_keycnth[di]
sawnom:
		ENDIF
		IF ENTEST
		;--- entropy test- process a 14 bit block
		;--- the latest 16 bits are always in 'ilasts[di]'
		test	nibcnt[di],3
		jnz		sawne				;not time yet
		test	_entactive[di],1	;are we sampling on this interrupt
		jz		sawne				;no (either done or inactive)
		mov		ax,ilasts[di]		;ok, get latest 16 bits
		mov		bx,_ebitmapno[di]
		call	ent_test			;put into the bit map
		inc		_entcnt[di]			;count keystrokes
		jnz		sawne     			;in double precision
		inc		_entcnth[di]
		jnz		sawnez				;2 special cases:
		xor		ax,ax				;A. if count=0:0, clear accums
		mov		entacum[di],ax
		mov		_entacuma[di],ax
		mov		_entacumb[di],ax
		jmp		sawne
sawnez: mov		ax,word ptr _enttestn+2		;hi 16b
		cmp		_entcnth[di],ax
		jl		sawne				;B. if terminal count, set flag
		mov		_entactive[di],2
sawne:
		ENDIF
		;--- compute sums another way for testing
		IF		XXB2
		cmp		di,3*2				;do this for int7 only (DI=3*2)
		jnz		saw7nox
		mov		bx,thisdat
		shr		bx,3				;new bits now in bits 4..1 of DX
		mov		ax,bx				;get B23 (lsb)
		and		ax,2				;is now 0 or 2
		dec		ax           		;is now -1 or +1
		mov		cx,ax				;keep sum too
		cwd
		add		word ptr _xb23,ax
		adc		word ptr _xb23+2,dx
		shr		bx,1				;get B24
		mov		ax,bx
		and		ax,2
		dec		ax
		add		cx,ax
		cwd
		add		word ptr _xb24,ax
		adc		word ptr _xb24+2,dx
		shr		bx,1				;get B25
		mov		ax,bx
		and		ax,2
		dec		ax
		add		cx,ax
		cwd
		add		word ptr _xb25,ax
		adc		word ptr _xb25+2,dx
		shr		bx,1				;get B27
		mov		ax,bx
		and		ax,2
		dec		ax
		cwd
		add		word ptr _xb27,ax
		adc		word ptr _xb27+2,dx
		add		ax,cx				;get B2 sum
		cwd
		add		word ptr _xb2,ax
		adc		word ptr _xb2+2,dx
saw7nox:
		ENDIF
saw7ex:
		;--- acknowledge the interrupt ---
		mov     al,EOI             	;eoi to interrupt controller
		out     OCR,al          ;
		;--- restore machine state ---
		pop    	ds       			;restore registers
		popa
		sti             			;restore interrupt
		iret
sawhand7 endp

; ---- SPECIAL STREAMLINED INTERR HANDLER FOR INT 5 -------------
		IF		FASTINT5
nibtab	dw		offset nib0
		dw		offset nib1
		dw		offset nib2
		dw		offset nib3
		dw		offset nib4
		dw		offset nib5
		dw		offset nib6
		dw		offset nib7
		dw		offset nib8
		dw		offset nib9
		dw		offset niba
		dw		offset nibb
		dw		offset nibc
		dw		offset nibd
		dw		offset nibe
		dw		offset nibf
sawhand5   PROC
		;--- save machine state ---
		cli	        				;disable interrputs
		push	ax
		push	bx
		push	cx
		push	dx
		push    ds
		;--- load DS with data segment for this block of data ---
		mov		ax,DGROUP
		mov		ds,ax
		;--- acknowledge the interrupt ---
		mov     al,EOI             	;eoi to interrupt controller
		out     OCR,al          ;
		;-- incr the interrupt count
		inc		icount[4]
		;-- get the data nibble, clean up bits, maintain history
		mov		dx,279h			;fixed dev code
		in		al,dx
		mov		bx,offset bitfix
		xlatb					;fix up bits 3-5,7
		;-- now use the data nibble
		;--- combine with last 3 nibbles to get 16bit composite
		shl		ax,8				;now in b15..12 of AX
		mov		bx,ilasts[4]		;'or' this into 'lasts'
		shr		bx,4
		or		bx,ax
		mov		ilasts[4],bx		;re-stash new 12 bit value
;		inc		nibcnt[4]			;count nibbles added to 'keystroke'
		;-- do table lookups that use the last 12 bits as arg
		shr		bx,4
		mov		al,addcor56[bx]		;note: ser corr 5 & 6 combined in 1 table
		mov		cl,al
		and		al,0Fh				;ser corr 5
		sub		al,4        		;range 0..8, make it -4 .. +4
		cbw
		add		icor5[4],ax
		mov		al,cl				;ser corr 6
		shr		al,4
		sub		al,4
		cbw
		add		icor6[4],ax
		mov		al,addcor78[bx]		;note: ser corr 7 & 8 combined in 1 table
		mov		cl,al
		and		al,0Fh				;ser corr 7
		sub		al,4        		;range 0..8, make it -4 .. +4
		cbw
		add		icor7[4],ax
		mov		al,cl				;ser corr 8
		shr		al,4
		sub		al,4
		cbw
		add		icor8[4],ax
		;-- do table lookups that use the high 8 bits as arg
		shr		bx,4
		mov		al,addcor1[bx]		;ser corr 1
		cbw
		add		icor1[4],ax
		mov		al,addcor2[bx]		;ser corr 2
		cbw
		add		icor2[4],ax
		mov		al,addcor3[bx]		;ser corr 3
		cbw
		add		icor3[4],ax
		mov		al,addcor4[bx]		;ser corr 4
		cbw
		add		icor4[4],ax
		;-- do table lookups that use the high (latest) 4 bits as arg
;		shr		bx,3				;nibble *2
;		mov		cx,nibtab[bx]
;		jmp		cx
		shr		bx,4
		;-- maintain sums of 1's and 0's
		mov 	al,addb23[bx]   	;B23
		cbw
		add		ib23[4],ax
		mov 	al,addb24[bx]		;B24
		cbw
		add		ib24[4],ax
		mov 	al,addb25[bx]		;B25
		cbw
		add		ib25[4],ax
		mov 	al,addb27[bx]		;B27
		cbw
		add		ib27[4],ax
		mov 	al,addb2[bx]
		cbw
		add		ib2[4],ax			;add sum of 4
		jno		saw7no5
		sub		ib2[4],cx			;don't let it overflow
		mov		_overflow,1
saw7no5:
		;--- restore machine state ---
		pop    	ds       			;restore registers
		pop		dx
		pop		cx
		pop		bx
		pop		ax
		sti             			;restore interrupt
		iret
sawhand5 endp

nib0:	dec		word ptr ib23+4
		dec		word ptr ib24+4
		dec		word ptr ib25+4
		dec		word ptr ib27+4
        sub		word ptr ib2+4,4
        jmp		nibx
nib1:	inc		word ptr ib23+4
		dec		word ptr ib24+4
		dec		word ptr ib25+4
		dec		word ptr ib27+4
        sub		word ptr ib2+4,2
        jmp		nibx
nib2:	dec		word ptr ib23+4
		inc		word ptr ib24+4
		dec		word ptr ib25+4
		dec		word ptr ib27+4
        sub		word ptr ib2+4,2
        jmp		nibx
nib3:	inc		word ptr ib23+4
		inc		word ptr ib24+4
		dec		word ptr ib25+4
		dec		word ptr ib27+4
        jmp		nibx
nib4:	dec		word ptr ib23+4
		dec		word ptr ib24+4
		inc		word ptr ib25+4
		dec		word ptr ib27+4
        sub		word ptr ib2+4,2
        jmp		nibx
nib5:	inc		word ptr ib23+4
		dec		word ptr ib24+4
		inc		word ptr ib25+4
		dec		word ptr ib27+4
        jmp		nibx
nib6:	dec		word ptr ib23+4
		inc		word ptr ib24+4
		inc		word ptr ib25+4
		dec		word ptr ib27+4
        jmp		nibx
nib7:	inc		word ptr ib23+4
		inc		word ptr ib24+4
		inc		word ptr ib25+4
		dec		word ptr ib27+4
        add		word ptr ib2+4,2
        jmp		nibx
nib8:	dec		word ptr ib23+4
		dec		word ptr ib24+4
		dec		word ptr ib25+4
		inc		word ptr ib27+4
        sub		word ptr ib2+4,2
        jmp		nibx
nib9:	inc		word ptr ib23+4
		dec		word ptr ib24+4
		dec		word ptr ib25+4
		inc		word ptr ib27+4
        jmp		nibx
niba:	dec		word ptr ib23+4
		inc		word ptr ib24+4
		dec		word ptr ib25+4
		inc		word ptr ib27+4
        jmp		nibx
nibb:	inc		word ptr ib23+4
		inc		word ptr ib24+4
		dec		word ptr ib25+4
		inc		word ptr ib27+4
        add		word ptr ib2+4,2
        jmp		nibx
nibc:	dec		word ptr ib23+4
		dec		word ptr ib24+4
		inc		word ptr ib25+4
		inc		word ptr ib27+4
        jmp		nibx
nibd:	inc		word ptr ib23+4
		dec		word ptr ib24+4
		inc		word ptr ib25+4
		inc		word ptr ib27+4
        add		word ptr ib2+4,2
        jmp		nibx
nibe:	dec		word ptr ib23+4
		inc		word ptr ib24+4
		inc		word ptr ib25+4
		inc		word ptr ib27+4
        add		word ptr ib2+4,2
        jmp		nibx
nibf:	inc		word ptr ib23+4
		inc		word ptr ib24+4
		inc		word ptr ib25+4
		inc		word ptr ib27+4
        add		word ptr ib2+4,4
nibx:   jmp		saw7no5
		ENDIF

;************* MONK_TEST -- accum a value into the monkey test bit map
; input: 15 bits in lo AX, 5 bits in lo DX- bits may be in any order
; BX: bitmap number to use: 0-1-2-3
; sets the bit in the bit map corresponding to this 20bit value
; note: we work upward from offset 0 of each segment
monk_test:	push	es
			shl		bx,2			;bitmap no, 0-4-8-12
			mov		bx,word ptr _mbank+2[bx]	;base segment addr
			mov		cx,dx			;first set up bank in ES
			and		cx,18h			;from top 2 bits of the 5
			shl		cx,8			;now 0-800-1000-1800
			add		bx,cx			;add to base seg val
			mov		es,bx
			mov		bx,dx			;now get bit mask
			and		bx,7
			mov		cl,bitmasks[bx]
			mov		bx,ax			;now get offset
			or		es:[bx],cl		;set the bit
			pop		es
			retn

;************* MONK_INIT -- initialize for a monkey test *************
; clear the bitmap memory, set up mode
; sets 'monkactive[]' flag, will start taking data
; clears 'keycnt[]' and 'keycnth[]'
; sets bitmapno[] to the bitmap this intrr is using
_monk_init	proc	far
			public	_monk_init
			ARG		intno:word,buffno:word
			push	bp
			mov		bp,sp
; first adjust the pointers to bitmap memory banks
; if any offset is nonzero, incr the segment till offset=0
; NOTE: for now, we assume offset will be <16, so just inc segment once
			IF 0
			mov		bx,0   			;BX= 0-4-8-12
monkadj:	cmp		word ptr _mbank[bx],0
			jz		monkadjn		;offset=0, done
			inc		word ptr _mbank+2[bx]	;offset not 0, incr segmt
			mov		word ptr _mbank[bx],0	;and clear offset
monkadjn:	add		bx,4
			cmp		bx,16
			jb		monkadj
			ENDIF
; now clear the memory bank
			mov		ax,0
			mov		bx,buffno		;0-1-2-3
			shl		bx,2			;0-4-8-12
			mov		es,word ptr _mbank+2[bx]	;segment value is at +2
			mov		bx,0			;BX= 0..65534
monklr:
			mov		es:[bx],ax
			add		bx,2			;next word
			jnz		monklr
			mov		cx,es			;repeat the same for upper half
			add		cx,1000h		;which is 65K higher
			mov		es,cx
			mov		bx,0			;BX= 0..65534
monklr2:
			mov		es:[bx],ax
			add		bx,2			;next word
			jnz		monklr2
			mov		bx,intno		;which intrr are we initializing
			shl		bx,1
			mov		_keycnt[bx],0	;clear key counter (32 bits)
			mov		_keycnth[bx],0
			mov		ax,buffno		;set up the bitmap no.
			mov		_bitmapno[bx],ax
			mov		_monkactive[bx],1 ;lastly, set init'd flag
			pop		bp				  ;this starts data collection
			ret
_monk_init	endp

;************ MONK_SUM -- get sum of bits in bitmap array, all banks
; returns sum in _monkbits (long integer)
_monk_sum	proc	far
			public	_monk_sum
			ARG		buffno:word
			push	bp
			mov		bp,sp
			push	si
			mov		si,0h			;SI= 0..65535
			mov		dx,0
			mov		cx,dx			;DX:CX is master accum
			mov		bx,buffno		;0-1-2-3
			shl		bx,2			;0-4-8-12
			mov		es,word ptr _mbank+2[bx] 	;segment values
			mov		bh,0
monkadd:	mov		bl,es:[si]		;actual byte, bh=0
			mov		al,zbitcnt[bx]	;get zero bit count
			cbw
			add		cx,ax			;now add the 4 into big total
			adc		dx,0
			inc		si				;next byte
			jnz		monkadd
			mov		ax,es			;segment values
			add		ax,1000h
			mov		es,ax
			mov		bh,0
monkadd2:	mov		bl,es:[si]		;actual byte
			mov		al,zbitcnt[bx]
			cbw
			add		cx,ax			;now add the 4 into big total
			adc		dx,0
			inc		si				;next byte
			jnz		monkadd2
			mov		word ptr _monkbits,cx
			mov		word ptr _monkbits+2,dx
			pop		si
			pop		bp
			ret
_monk_sum	endp

;************* ENT_INIT -- initialize for an entropy test *************
; clear the array memory, set up mode  note: assume offset is alloc to 0
; sets 'entactive[]' flag, will start taking data
; clears 'entcnt[]' and 'entcnth[]' to - (init period value)
; sets entmapno[] to the array this intrr is using
_ent_init	proc	far
			public	_ent_init
			ARG		intno:word,buffno:word
			push	bp
			mov		bp,sp
; clear the memory bank
			mov		bx,buffno		;0-1-2-3
			shl		bx,2			;0-4-8-12
			mov		es,word ptr _ebank+2[bx]	;segment value is at +2
			mov		bx,0			;BX= 0..49152-2
			mov		ax,0C000h ;-((1 shl ENBITS) *ENINITP) and 0ffffh ;get -(2^14 *5) for init
			mov		dx,0FFFEh ;-((1 shl ENBITS) *ENINITP) shr 16
entclr:
			mov		es:[bx],ax 		;low 16
			mov		es:2[bx],dl		;hi 8
			add		bx,3			;next 24 bits
			cmp		bx,16384*3
			jb		entclr
			mov		bx,intno		;which intrr are we initializing
			shl		bx,1
			mov		_entcnt[bx],ax	;clear key counter (32 bits)
			mov		_entcnth[bx],dx	;clear to -start val
			mov		ax,buffno		;set up the bitmap no.
			mov		_ebitmapno[bx],ax
			mov		_entacuma[bx],0	;needed only for debugging
			mov		_entacumb[bx],0
			mov		_entactive[bx],1 ;lastly, set init'd flag
			pop		bp				  ;this starts data collection
			ret
_ent_init	endp


;************* GETIDAT -- retrieve data from 'saw' intrr accumulators
; and clear them to 0 at the same time
; argument: the interrupt no. (index to basic list) to get data from
; leaves the data in _icount, _ib2[5], _icor[8] (note: indexes are X2)
_getidat	proc	far
			public	_getidat
			arg		which:word
			push	bp
			mov		bp,sp
			mov		bx,which
			shl		bx,1			;byte pointer
			xor		ax,ax			;icount
			cli						;no interrupts during this
			xchg	ax,icount[bx]
			mov		_icount,ax
			xor		ax,ax			;ib2
			xchg	ax,ib2[bx]
			mov		_ib2,ax
			xor		ax,ax			;ib23
			xchg	ax,ib23[bx]
			mov		_ib2[2],ax
			xor		ax,ax			;ib24
			xchg	ax,ib24[bx]
			mov		_ib2[4],ax
			xor		ax,ax			;ib25
			xchg	ax,ib25[bx]
			mov		_ib2[6],ax
			xor		ax,ax			;ib27
			xchg	ax,ib27[bx]
			mov		_ib2[8],ax
			xor		ax,ax			;icor1
			xchg	ax,icor1[bx]
			mov		_icor[0],ax
			xor		ax,ax			;icor2
			xchg	ax,icor2[bx]
			mov		_icor[2],ax
			xor		ax,ax			;icor3
			xchg	ax,icor3[bx]
			mov		_icor[4],ax
			xor		ax,ax			;icor4
			xchg	ax,icor4[bx]
			mov		_icor[6],ax
			xor		ax,ax			;icor5
			xchg	ax,icor5[bx]
			mov		_icor[8],ax
			xor		ax,ax			;icor6
			xchg	ax,icor6[bx]
			mov		_icor[10],ax
			xor		ax,ax			;icor7
			xchg	ax,icor7[bx]
			mov		_icor[12],ax
			xor		ax,ax			;icor8
			xchg	ax,icor8[bx]
			sti						;restore interrupts
			mov		_icor[14],ax
			pop		bp
			ret
_getidat	endp

;*********** INITTABLES -- init the lookup tables for SAW handlers
inittables:
; first loop: init the tables of 16
; note: to use this table, BX contains 4 bit value (no more)
;	then MOV AL,ADDB23[BX]  gets amount to add to ib23
;	then use CBW to extend to word
			xor		bx,bx
itt16:		mov		al,bl			;index is the argument
			shl		al,1			;bit 0 to addb23
			and		al,2            ;will be +1 or -1
			dec		al
			mov		cl,al
			mov		addb23[bx],al
			mov		al,bl			;bit 1 to addb24
			and		al,2
			dec		al
			add		cl,al
			mov		addb24[bx],al
			mov		al,bl			;bit 2 to addb25
			shr		al,1
			and		al,2
			dec		al
			add		cl,al
			mov		addb25[bx],al
			mov		al,bl			;bit 3 to addb27
			shr		al,2
			and		al,2
			dec		al
			add		cl,al
			mov		addb27[bx],al
			mov		addb2[bx],cl	;sum to addb2, will be -4 .. +4
			inc		bx
			cmp		bx,16
			jb		itt16
; second loop: init the tables of 256, BX= 0..255
			xor		bx,bx
itt256: 	mov		ax,bx			;BX is argument: 8bits, MSB is latest
			shl		ax,1			;old bits in new position
			xor		ax,bx			;results in B7..4; 0=same, 1=diff
			mov		ch,0			;bit counter
			mov		cl,4			;bit count for 4 bits
itt2561:	shl		al,1
			adc		ch,0			;increments ch if bit was 1
			dec		cl     			;do just 4 times
			jnz		itt2561
			shl		ch,1			;n*2
			neg		ch				;-n*2
			add		ch,4			;4-n*2 = (N 0's) - (N 1's)
			mov		addcor1[bx],ch
			mov		ax,bx			;Do addcor2
			shl		ax,2
			xor		ax,bx
			mov		ch,0
			mov		cl,4
itt2562:	shl		al,1
			adc		ch,0
			dec		cl
			jnz		itt2562
			shl		ch,1
			neg		ch
			add		ch,4
			mov		addcor2[bx],ch
			mov		ax,bx			;Do addcor3
			shl		ax,3
			xor		ax,bx
			mov		ch,0
			mov		cl,4
itt2563:	shl		al,1
			adc		ch,0
			dec		cl
			jnz		itt2563
			shl		ch,1
			neg		ch
			add		ch,4
			mov		addcor3[bx],ch
			mov		ax,bx			;Do addcor4
			shl		ax,4
			xor		ax,bx
			mov		ch,0
			mov		cl,4
itt2564:	shl		al,1
			adc		ch,0
			dec		cl
			jnz		itt2564
			shl		ch,1
			neg		ch
			add		ch,4
			mov		addcor4[bx],ch
			mov		ax,bx				;do zero bitcnt
			mov		ch,0
			mov		cl,8
itt256b:	shl		al,1
			cmc
			adc		ch,0
			dec		cl
			jnz		itt256b
			mov		zbitcnt[bx],ch
			mov		ax,bx			;put the entry in 'bitfix'
			mov		ah,al
			and		al,0B8h			;clear bit 6
			and		ah,038h			;get just lower 3
			add		al,ah			;shift lower 3 left 1, next to bit 7
			mov		bitfix[bx],al
			inc		bx					;"next" bx
			cmp		bx,256
			jae		itt3
			jmp		itt256
; third loop: init the tables of 4096
itt3:		xor		bx,bx
itt4096:	mov		ax,bx			;BX is argument: 12bits, MSB is latest
			shl		ax,5			;old bits in new position
			xor		ax,bx			;results in B11..8; 0=same, 1=diff
			shr		ax,4			;now in B7..4
			mov		ch,0			;bit counter
			mov		cl,4			;bit count for 4 bits
itt40961:	shl		al,1
			adc		ch,0			;increments ch if bit was 1
			dec		cl     			;do just 4 times
			jnz		itt40961
			shl		ch,1			;n*2
			neg		ch				;-n*2
			add		ch,8			;4-n*2 +4 = (N 0's) - (N 1's) +4
			mov		ax,bx			;Do addcor6
			shl		ax,6
			xor		ax,bx
			shr		ax,4
			mov		dh,0
			mov		cl,4
itt40962:	shl		al,1
			adc		dh,0
			dec		cl
			jnz		itt40962
			shl		dh,1
			neg		dh
			add		dh,8 			;want range 0..8 for storing, so add 4
			shl		dh,4			;combine the 2, MS4B is addcor6
			or		ch,dh			;LS4B is addcor5
			mov		addcor56[bx],ch
			mov		ax,bx			;do addcor7
			shl		ax,7
			xor		ax,bx
			shr		ax,4
			mov		ch,0
			mov		cl,4
itt40963:	shl		al,1
			adc		ch,0
			dec		cl
			jnz		itt40963
			shl		ch,1
			neg		ch
			add		ch,8
			mov		ax,bx			;Do addcor8
			shl		ax,8
			xor		ax,bx
			shr		ax,4
			mov		dh,0
			mov		cl,4
itt40964:	shl		al,1
			adc		dh,0
			dec		cl
			jnz		itt40964
			shl		dh,1
			neg		dh
			add		dh,8
			shl		dh,4
			or		ch,dh
			mov		addcor78[bx],ch
			inc		bx
			cmp		bx,4096
			jae		itt4
			jmp		itt4096
itt4:		retn

;			mov		ah,48h
;			mov		bx,256			;no of paragraphs
;			int		21h				;allocate mem, AX will have segment
;			jc		error

; Entropy test
			.386
_getlog2	proc	far				;test procedure
			public	_getlog2
			mov		eax,_entin		;integer, 0- 2meg
			call getlog2
			mov		_entout,eax
			ret
_getlog2	endp

getlog2:        					;get arg from eax, result in eax (x65k)
			bsr		ecx,eax			;which bit is msb
			mov		intpart,cx		;power of 2- save for end
;			mov _t1,cx
			neg		cl				;now normalize in EAX
			add		cl,32			;shift left (32-msb)
			shl		eax,cl			;this dumps msb- don't need it
			mov		ecx,eax			;now find out which table to use
			shr		ecx,16			;this is 16 bit base in CX
;			mov _t2,cx
			mov		bx,offset ilog2	;scan index for correct base
glogsc:		cmp		cx,[bx]			;look for a base <= ours
			jae		glogbb
			add		bx,6
			jmp		glogsc
glogbb:     mov		cx,[bx]			;get base from table, subtract it
			shl		ecx,16			;from working value
			sub		eax,ecx			;(is relative in table)
			mov		cx,2[bx]		;get n select bits
;			mov _t3,cx
			mov		bx,4[bx]		;get offset to table
			neg		cl				;now shift arg R 16-nselbits
			add		cl,16
			shr		eax,cl			;selector is in upper EAX, frac in AX
;			mov _t5,ax
			mov		ecx,eax
			shr		ecx,16			;selector in CX (x2)
;			mov _t4,cx
			shl		ecx,1			;note- 2 shifts are necessary
			add		bx,cx			;bx now points to Y0 value
			mov	cx,2[bx]			;y1
;			mov _t6,cx
			mov	cx,4[bx]			;y2
;			mov _t7,cx
; now do the actual interpolation; AX=frac, BX points to Y0
			mov		ratio,ax
			test	ax,ax			;do we use left or right half of block
			js		gloghi			;right
			jnz		glognz
			mov		dx,2[bx]		;special case for frac=0, just use y1
			jmp		glogjoin
glognz:		mov		dx,4[bx]
			sub		dx,2[bx]
			add		dx,0[bx]
			sub		dx,2[bx]		;y2 +y0 -2y1   signed small value
            shl		dx,2			;scale *4
			call	mpyax			;mpy by r (in ax)
			mov		cx,4[bx]		;add y2 -y0
			sub		cx,0[bx]
            shl		cx,2			;scale *4
            add		dx,cx
			call	mpyr			;mpy by r (in mem)
            sar		dx,2			;unscale
			inc		dx				;round:
			sar		dx,1			;divide val by 2
			add		dx,2[bx]		;finally add y1
			mov		ax,0
glogjoin:	add		ax,intpart		;put the result together and return it
			shl		eax,16			;int part
			mov		ax,dx			;frac part
;			mov _t8,dx
			retn
gloghi:		mov		dx,2[bx]		;High side: get y1-y3
			sub		dx,6[bx]
            shl		dx,2			;scale *4
			neg		ax				;*(1-r)
			call	mpyax			;should div by 2 after this
			mov		cx,dx			;store temp (scaled *8)
			mov		dx,2[bx]		;get y1-y2
			sub		dx,4[bx]
            shl		dx,3			;scale *8
			call	mpyr			;*r
			add		cx,dx			;combine & stash
			mov		dx,4[bx]		;get (y2-y1) *2
			sub		dx,2[bx]
			shl		dx,4
			add		dx,cx			;combine all 3 terms
			call	mpyr			;*r
            sar		dx,2			;unscale and round
            inc		dx
            sar		dx,1
			add		dx,2[bx]		;finally add y1
			mov		ax,0
			adc		ax,0			;put carry into ax
			jmp		glogjoin

; *********** MPYR and MPYAX -- multiply integer in DX by fraction
; returns resulting (smaller) integer in DX; handles pos/neg
mpyr:		mov		ax,ratio		;loads AX for you
mpyax:		test	dx,dx			;is integer part + or -
			js		mpyam			;-
			mul		dx				;+, just mul and quit
			retn					;result already in DX
mpyam:		neg		dx
			mul		dx
			neg		dx
			retn

;************* ENT_TEST-- accum a value into the entropy test acum
; input: 14 bits in lo AX, bits may be in any order
; BX: bitmap number to use: 0-1-2-3   DI: interrupt pointer
; note: we work upward from offset 0 of each segment
ent_test:	push	es
			shl		bx,2			;bitmap no, 0-4-8-12
			mov		bx,word ptr _ebank+2[bx]	;base segment addr
			mov		es,bx
			and		ax,3FFFh
			mov		bx,ax			;get value
			shl		bx,1			;mpy by 3, use to index table
			add		bx,ax
			mov		ax,_entcnt[di]	;get time reading now, into dl:ax
			mov		dx,_entcnth[di]
			mov		cx,ax			;also copy into dh:cx
			mov		dh,dl
			xchg	ax,es:[bx]		;exch lo 16b into table
			xchg	dl,es:2[bx]		;now have old value in dl:ax
			sub		cx,ax			;get new - old (dh:cx - dl:ax)
			sbb		dh,dl
			mov		al,dh			;now put all in EAX
			cbw
			shl		eax,16
			mov		ax,cx
			call	getlog2			;get log2
			mov		edx,eax
			shr		edx,16
			add		entacum[di],ax	;accum the whole val into entacum (48b)
			adc		_entacuma[di],dx
			adc		_entacumb[di],0
			pop		es
			retn

;**************** UMPY -- unsigned fixed pt multiply *******************
; arg1 is in CX.DX:AX  (CX is integer part)
; arg2 is in 3 words pointed to by SI (least signif first) (4[di] is intgr)
; DI: pointer to 3 words, result will be stored there, unchanged on exit
; result goes into umpyo, 4 words, least sig first.  last is integer part
; also returns result in registers: CX.DX:AX
; --OR-- enter at umpybx with BX: offset to arg1
; --OR-- enter at umpysame to use destination as arg1
partmpy		macro	arg1,arg2,disp
			mov		ax,arg1
			mul		word ptr arg2
			add		umpyo+disp,ax
			adc		umpyo+2+disp,dx
			endm

umpysame:	mov		bx,di
umpybx:		mov		ax,0[bx]		;load registers from BX
			mov		dx,2[bx]
			mov		cx,4[bx]		;then fall thru into umpy
umpy:
			push	di				;save result pointer
            mov		di,cx			;integer part
            mov		cx,dx			;fraction, hi
            mov		bx,ax			;fraction, lo
			mov		dx,0			;first clear result array
			mov		umpyo,dx
			mov		umpyo+2,dx
			mov		umpyo+4,dx
			mov		umpyo+6,dx
			mul		word ptr 0[si]	;2L x 1L: arg is in AX already
			shl		ax,1			;round up, ax will be lost
			adc		dx,0
			mov		umpyo,dx
			partmpy	bx,2[si],0		;2L x 1M
			adc		umpyo+4,0
			partmpy cx,0[si],0		;2M x 1L
			adc		umpyo+4,0
			mov		ax,umpyo		;round up into umpyo+2, umpyo will be
			shl		ax,1     		;thrown away
			adc		umpyo+2,0
			adc		umpyo+4,0
			partmpy	bx,4[si],2		;2L x 1H
			adc		umpyo+6,0
			partmpy cx,2[si],2		;2M x 1M
			adc		umpyo+6,0
			partmpy	di,0[si],2		;2H x 1L
			adc		umpyo+6,0
			partmpy	cx,4[si],4		;2M x 1H
			partmpy	di,2[si],4		;2H x 1M
			mov		ax,di			;2H x 1H
			mul		word ptr 4[si]
			add		umpyo+6,ax		;dx is 0
            mov		ax,umpyo+2
            mov		dx,umpyo+4
            mov		cx,umpyo+6
            pop		di
            mov		0[di],ax
            mov		2[di],dx
            mov		4[di],cx
			retn


;************* RECIP -- reciprocal of 32 bit fraction ********************
; arg in .DX:AX   result in CL.DX:AX
; DO NOT call with arg=0, infinite loop
recip:
			mov		cl,0
recipnorm:	test 	dx,dx
			js		recipno			;when sign bit=1, quit
			shl		ax,1			;shift L 1, count shifts
			rcl		dx,1
			inc		cl
			jmp		recipnorm
recipno:	mov		recipnc,cl		;save norm count
			mov		recipdh,dx		;stash divisor
			mov		bx,ax
			mov		ax,0			;set up dividend
			mov		dx,ax
			mov		ch,1
			mov		recipqh,ax		;set up quotient
			mov		recipql,ax
			mov		cl,33			;loop count
reciploop:	sub		ax,bx			;subt divisor from dividend
			sbb		dx,recipdh
			sbb		ch,0
			cmc						;C=1 if it went in
			jc		recipok			;if it went in
			add		ax,bx			;if it didnt go in, add back
			adc		dx,recipdh
			adc		ch,0
			clc
recipok:	rcl		recipql,1			;slurp carry into the quotient
			rcl		recipqh,1
			shl		ax,1			;also shif div L 1
			rcl		dx,1
			rcl		ch,1
			dec		cl
			jnz		reciploop		;do 33X
			mov		ax,recipql		;done, get quo into CL.DX:AX
			mov		dx,recipqh
			mov		cl,1			;implicit '1'
			cmp		recipnc,0		;finally, do we need to shift
			jz		recipdone
recipshl:	shl		ax,1
			rcl		dx,1
			rcl		cl,1
			dec		recipnc
			jnz		recipshl
recipdone:	retn

			END
