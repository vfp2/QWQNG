; DOS Device driver for QNG- Quantum Number Generator
; To assemble/install this driver:
;	TASM /M2 DRIVER.ASM, DRIVER0					=86 version
;	TLINK @DRIVER.LNK  (=TLINK DRIVER)
;	EXE2BIN DRIVER.EXE \QNGDRV.SYS
;	TASM /M2 /Dver=3 DRIVER.ASM, DRIVER3			=386 version
;	"config.sys" must contain "DEVICE=QNGDRV.SYS"

		name		QNGdrive
		%PAGESIZE	44

_TEXT	segment		byte public 'CODE'

		assume		cs:_TEXT,ds:_TEXT,es:NOTHING

		org 0
;******************* Definitions *********************************
			IFNDEF	ver
ver			equ		0				;if version not defined, it is plain 86
			ENDIF
            IFE		ver-3			;set 86 or 386 mode
            .386P
			ENDIF
STATOUT		equ		1				;1= output hdw status bits
MINRATE		equ		2300			;data rate must be at least this
MINSERIAL	equ		2				;min serial corr: 2/10000
MAXSERIAL	equ		65530			;max serial corr: 6.5530
TIMOUT		equ		40000			;no-data timeout: n loops
ICMATCH		equ		20				;reqd match betw poll, intrr rate
NWTEST		equ		6250			;n words in test block
NBADBL		equ		3				;err if 3 or more bad blks seen
MaxCmd		equ		24				;max command code allowed
cr			equ		0Dh
lf			equ		0Ah
eom			equ		'$'				;end of message signal
; definitions for request header
rhdataseg	equ		10h
rhdataoffs	equ		0Eh
rhcount		equ		12h
rhtailoffs	equ		12h				;command tail- init only
rhtailseg	equ		14h
; definitions for interrupt structure
SetIntVect  equ     25h             ;DOS function
GetIntVect  equ     35h             ;DOS function
IRQ5		equ		0Dh				;interrupt no for hardware IRQ5
IRQ7        equ     0Fh             ;interrupt number for hardware IRQ7
intmask2    equ     11111011B       ;PIC mask for INT 2- not used now
intmask7    equ     01111111B       ;PIC mask for INT 7
EOI         equ     20h             ;non-specific EOI
OCR         equ     20h             ;Location of 8259 operational register
BUFFSZ		equ		512				;size of buffer in words- power of 2!

;**************** DOS device driver header ***********************
Header:								;Device driver header
			dd		-1				;link words
Hattr		dw		0C840h			;device attribute word
			dw		Strat			;strategy entry point
			dw		Intr			;"interrupt" entry point
			db		'QNG     '		;logical device name- 8 char


;******************* Options ***********************************
neg_only 	dw		0				;negative normal results only
tail_only 	dw		0				;generate values in tail only

;**************** DATA area ***************************************
RHPtr		dd		?				;pointer to request header
xfrcount	dw 		0
fileopen	db		0
pollmode	db		0				;1= operate w/o interrupts
; data for numeric processing on READ
rstate		dw		-1
argu		dw		0				;temps for conversion to decml
argu2		dw		0
argu3		dw		0
cbuf		db		40	dup(?)		;char buffer for converted values
cbufb		dw		0				;no of first char in buffer
cbufe		dw		0				;no of last char in buffer +1
dtestcnt	db		0
errmsg		db		'ERROR 1',cr,lf
ERRMSL		equ		9				;length of errmsg
ERRDIG		equ		6				;position of digit in str (can change)
; Data returned on an IOCTL read
; all data is here, in order, is copied to caller
iorbuf:								;NOTE: devcode, intrrno must be first
devcode		dw		0				;device code for device in use
intrrno		db		0				;interrupt no- 5, 7
intrrcd		db		0				;interrupt code- IRQ5 or IRQ7
icount		dw		0				;intrr (word) count
b2save		dw		0				;last results of block test
s4save		dw		0
IOR_SIZ		equ		10				;n bytes returned by IOCTL read
; data for interrupt structure (note: 'devcode' is under IOCTL read)
intrrmx		db		0				;mask for PIC
old_off		dw		0				;old offset & segment-
old_seg		dw		0				;currently just 1 interrups saved
old_intv	dd		0				;old interrupt vector
old_msk		db		0
wordtmp		dw		0				;word accumulator
									;note: MSB is latest bit recvd
c4			db		4				;counts 4 nibbles
xorcnt		db		0				;alternating counter in xor mode
xorlast		db 		0				;last nibble in xor mode
buffin		dw		0				;displacements: input to buff
statbits	db		0				;hdw status bits for debug
buffout		dw		0				; "  out
obcount		db		0				;count of bytes generated
buff		dw		BUFFSZ dup(?)	;intrr buffer
; data for 1/0 balance and correl testing
; note: for z limit, 1 SD is sqrt(nbits) /2 or 158 for 100k
b2			dw		0				;B2 balance
s4			dw		0				;serial corrs
consecbad	dw		0				;n consec bad blocks seen
last16b		dw		0
zlimit		dw		474				;z score limit =3 SD
zlimit2		dw		0				;set to 2x zlimit on init
NWDSC		equ		3				;n words to clear
; data for option & mode processing
dmode		dw		88h				;main driver mode
verbose		db		0				;1= tell info on bootup -option V
verbose2	db		0				;show opens, reads, closes -option !
dmodeac		dw		0				;acum for dmode settings
dmoden		db		0				;nchars seen
pollast		db		0				;saves bits in poll mode
showopn		db		'{O}',eom		;debug messages for verbose2 mode
showclo		db		'{C}',eom
showrd		db		'{R',eom
showwr		db		'{W}',eom
; variables for normal distribution generator routine
whcall		dw		0				;for debug
whstep		dw		0
normtimo	db		0				;timeout counter
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
normconc	dw		4726h, 477Bh, 01	;constants for algorithm
normcond	dw		29AAh, 0AA18h, 1DCh
_ux			dd		0				;uniform distr arg
_udx		dd		0				;increment for ux
ucount		dd		0				;count of unif no's used
ucounthi	dw		0				;hi 16, not used
ncount		dd		0				;count of normals generated
umpyo		dw		5	dup(0)		;result array
recipnc		db		0				;n left shifts to normalize arg
recipcc		db		0				;loop counter
recipql		dw		0				;quotient lo
recipqm		dw		0
recipqh		dw		0				;quotient hi
k10000		dw		10000
k10			dw		10
kk10		dd		10				;for 386
			db		200				;y for I=-1
tabley		db		200,199,199,198,197,196,195,193,192,190		;0-
			db		188,186,184,181,179,176,173,170,167,164		;10-
            db		161,157,154,151,147,143,140,136,132,128		;20-
            db		125,121,117,113,110,106,102,98,95,91		;30-
            db		88,84,81,77,74,71,68,64,61,59			;40-
            db		56,53,50,48,45,43,40,38,36,34			;50-
            db		32,30,28,27,25,23,22,20,19,18			;60-
            db		17,15,14,13,12,11,11,10,9,8				;70-
            db		8,7,6,6,5,5,4,4,4,3,3,3,2,2,2,2,2,1,1,1	;80-
            db		1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
tablea		db		31,30,29,28,27,26,25,24,23,22			;0-
			db		21,20,27,26,25,24,23,22,21,255			;10-
			db		19,19,21,20,19,18,17,16,15,14			;20-
			db		13,12,19,18,17,16,15,14,13,12			;30-
			db		11,10,9,8,7,6,5,4,3,2					;40-
			db		1,0,23,22,21,20,19,18,17,16				;50-
			db		15,14,13,12,11,10,9,8,7,6				;60-
			db		5,4,3,2,1,0,51,50,49,48					;70-
			db		47,46,45,44,43,42,41,40,39,38			;80-
			db		37,36,35,34,33,32,31,30,29,28			;90-
			db		27,26,25,24,23,22,21,20,19,18			;100-
			db		17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0	;110-
tableq		db		28,32,33,36,40,43,45,47,51,53			;0-
			db		57,59,27,37,43,54,28,45,60,63			;10-
            db		49,61,52,34,63,46,34,18,47,40			;20-
            db		36,29,61,57,53,51,47,43,40,37			;30-
            db		33,31,27,25,21,19,17,14,11,9			;40-
            db		8,5,54,51,49,46,44,41,39,37				;50-
            db		35,33,31,29,28,26,24,23,21,20			;60-
            db		19,18,16,15,14,13,12,12,11,10			;70-
            db		9,9,8,7,7,6,6,5,5,5,4,4,4,3,3,3,3,3,2,2	;80-
            db		2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1


;**************** DOS device driver internals *********************
Dispatch:						;Command code dispatch table
			dw		init
			dw		Nullc			;1 media check (block only)
			dw		Nullc			;2 build BIOS param blk (block only)
			dw		IORead			;3 IOCTL read
			dw		Read
			dw		NdRead
			dw		InpStat
			dw		InpFlush
			dw		Write			;8 write
			dw		Nullc			;9 write w/verify
			dw		OutStat
			dw		Nullc			;11 flush output buffers
			dw		Write			;12 IOCTL write, same as write
			dw		DevOpen
			dw		DevClose
			dw		Nullc			;15 removable media (block only)
			dw		OutBusy
			dw		Error			;not used
			dw		Error			;not used
			dw		Nullc			;19 generic IOCTL request
			dw		Error			;not used
			dw		Error			;not used
			dw		Error			;not used
			dw		Nullc			;23
			dw		Nullc			;24

Strat		proc	far				;"Strategy" routine
			mov		word ptr cs:[RHPtr],bx
			mov		word ptr cs:[RHPtr+2],es
			ret
Strat		endp

Intr		proc	far				;"Interrupt" routine
			IFE		ver-3
            pusha
            ELSE
			push	ax
			push	bx
			push	cx
			push	dx
			push	di
			push	si
;			push	bp				;BP not used
            ENDIF
			push	ds
			push	es
			mov		ax,cs			;set DS to =CS
			mov		ds,ax

			les		di,[RHPtr]		;ES:DI pts to Request header

			mov		bl,es:[di+2]	;command code
			mov		bh,0
			cmp		bx,MaxCmd		;is it > max
			jle		Intr1
			call	Error			;yes,
			jmp		Intr2

Intr1:		shl		bx,1			;form index & branch
			call	word ptr[bx+Dispatch]

			les		di,[RHPtr]		;ES:DI pts to Request header

; exit from all command routines- status in AX- 0=ok, 80xx=err
; ES:DI must point to request header here
Intr2:		or		ax,0100h
			mov		es:[di+3],ax	;store status into request header

			pop		es
			pop		ds
            IFE		ver-3
            popa
            ELSE
;			pop		bp
			pop		si
			pop		di
			pop		dx
			pop		cx
			pop		bx
			pop		ax
            ENDIF
			ret

; Individual command code routines
Nullc		proc	near			;for unimplemented commands
			xor		ax,ax
			ret
Nullc		endp

Error		proc	near			;for error returns
			mov		ax,8003h
			ret
Error		endp

; IOREAD -- IOCTL read, read status etc  *****************************
; ES:DI points to request header from DOS
; if caller asks for less bytes than we send, send nothing
; to see what data is set back, see 'iorbuf'
IORead		proc	near
			mov		ax,es:[di+rhcount]		;get byte count wanted
			cmp 	ax,IOR_SIZ
			jae		ioread2
			mov		word ptr es:rhcount[di],0	;error, return nothing
			jmp		ioreadx
ioread2:    mov		word ptr es:rhcount[di],IOR_SIZ
			mov		cx,es:[di+rhdataseg]
			mov		di,es:[di+rhdataoffs]	;destination address
			mov		es,cx				;use es:di for destination
			mov		si,offset iorbuf
			mov		cx,IOR_SIZ
			cld
			rep
			movsb
;ioreadl:	mov		al,[si]			;loop to copy bytes
;			mov		es:[di],al
;			inc		si
;			inc		di
;			dec		cx
;			jnz		ioreadl
ioreadx:	xor		ax,ax			;exit
			ret
IORead		endp

; READ ***********************************************************
; ES:DI points to request header from DOS
; always transfers the no of bytes wanted, so don't rewrite in req header
Read		proc	near
			mov		ax,es:[di+rhcount]		;get byte count wanted
			mov		[xfrcount],ax			;will always transfer this many
			mov		bx,es:[di+rhdataoffs]	;destination address
			mov		cx,es:[di+rhdataseg]
			mov		di,bx			;use es:di for destination
			mov		es,cx
			cld						;set direction positive
			cmp		verbose2,0
			jz		noshowrd
			mov		dx,offset showrd	;if verbose, show R flag
			call	showst
			mov		ax,xfrcount
			mov		cl,'}'
			call	showdec5t
noshowrd:	and		statbits,0FDh	;set status bit 2 on
			mov		al,statbits
			mov		dx,devcode
			add		dx,2
			out		dx,al
IF 0
; loop to transfer chunks
; a chunk is the smaller of:  nbytes wanted / nbytes available in cbuf
rchunk:		mov		cx,cbufe		;first, is cbuf empty
			sub		cx,cbufb
			jnz		rchgotc			;no, got something
			call	convtuni			;yes, get another value- always gets
			mov		cbufb,0			;nonzero amt
			mov		cbufe,bx		;BX is now amt you've got
			mov		cx,bx
rchgotc:	cmp		cx,xfrcount
			jb		rch2			;if CX smaller
			mov		cx,xfrcount		;if xfrcount smaller
rch2:		sub		xfrcount,cx		;CX is now the chunk size
			mov		bx,cbufb
			mov		si,bx			;si is source index
			add		cbufb,cx		;push up the buffer pointer
			rep
			movsb
			cmp		xfrcount,0
			jnz		rchunk
ELSE
xxloop:								;loop to xfer bytes
			mov		bx,cbufb		;is there anything in cbuf now
			cmp		bx,cbufe
			jnz		xxgotc			;yes, got chars
			call	getnewval		;no, get new value
			mov		bx,cbufb
xxgotc:		inc		cbufb
			mov		al,cbuf[bx]
			mov		es:[di],al		;come here with byte in AL
			inc		di
			dec		[xfrcount]
			jnz		xxloop
ENDIF
			or		statbits,2		;set status bit 2 off
			mov		al,statbits
			mov		dx,devcode
			add		dx,2
			out		dx,al
			xor		ax,ax
			ret
Read		endp

dtestbad:	mov		cl,'2'
			jmp		getserr

; GETNEWVAL -- get a new value, convert to ASCII, store in 'cbuf'
; look at mode to tell how to convert value to correct format
; sets up cbufb, cbufe
; this routine must **always** return something, even if only err msg
getnewval:	cmp		consecbad,NBADBL	;is data testing good or bad
			jae		dtestbad
dtestok:	mov		ax,dmode
			test	ax,80h			;normal or uniform?
			jnz		normal			;normal
			and		ax,0Fh			;mode=uniform: get size
			cmp		ax,8
			jb		getun14			;if 1-4
			call	getunif			;if 8=32b or C=48b: 
			jc		getnodat		;get 2,3 words into CX:DX:AX
			test	dmode,4			;now is it 32 or 48b frac
			jnz		frac48
			call	convt32			;32: convert to 10 digit frac
			jmp     xxnew
frac48:		call	convt48			;48: convert to 14 digit frac
			jmp 	xxnew
getun14:	call    getword			;if 1-4 =16b: get 1 word into AX
			jc		getnodat		;if timeout, no data
			test	dmode,4
			jnz		getun16			;if 16 bit data
			test 	dmode,3			;if not 16, is it 4 or 1
			jnz		getun1n
			call	convtbin		;1 bit data- convert binary
			jmp		xxnew
getun1n:	test	dmode,20h		;if 4 bit data: dec or hex
			jnz		getun1h			;hex
			call	convt4i			;dec: convert to 4 dec numbers
			jmp		xxnew
getun1h:	call	convth4			;convert to 4 hex digits
			jmp		xxnew
getun16:	test	dmode,10h		;if 16 bit data: integer or frac
			jnz		getun4i			;integer
			call	convt16			;convert to 6 digit frac
			jmp		xxnew
getun4i:	call	convt16i
			jmp		xxnew
normal:     push	di
			call	getnorm			;get data value
			pop		di
			jc		getnodat
			call	convtnorm		;
xxnew:		mov		cbufb,0
			mov		cbufe,bx
			retn
getnodat:   mov		cl,'1'
getserr:	mov		bx,0          	;copy error message into cbuf
getnocop:	mov		al,errmsg[bx]	;"ERROR 1"
			mov		cbuf[bx],al
			inc		bx
			cmp		bx,ERRMSL
			jb		getnocop
			mov		cbuf+ERRDIG,cl	;plug in the digit
			jmp		xxnew

; CONVT16 -- new value is in AX, convert to frac, store in cbuf[]
; always returns 9 chars:  point, 6 digits, cr lf
; returns with BX: n chars put in buffer
convt16:	mov		cbuf[0],'.'
			mov		argu,ax
			mov		bx,1			;storing pointer
			mov		ch,6			;digit counter
xx3:		mov		ax,argu			;digit loop: 'argu' is a fraction
			mul		k10				;'argu' is a fraction; mpy by 10
			cmp		ch,6			;if first digit, round it
			jnz		xx3n
			add		ax,5			;add half a (future) lsb
			jnc		xx3n            ;note: this may carry, all the way up
			inc		dl				;to top digit
xx3n:		mov		argu,ax
			add		dl,'0'
			mov		cbuf[bx],dl
			inc		bx
			dec		ch				;count down digits
			jnz		xx3
; finally add a newline
xxret:		mov		cbuf[bx],cr
			inc		bx
			mov		cbuf[bx],lf
			inc		bx
			retn

; CONVT4I -- convert AX to 4 tiny decimal integers 0-15
; this could be made a lot more efficient
convt4i:	mov		bx,0
			mov		obcount,4
convt4il:	push	ax
			and		ax,0Fh
			call	convt16ib
			pop		ax
			mov		cl,4
			shr		ax,cl
			dec		obcount
			jnz		convt4il
			retn

; CONVTBIN -- convert AX to 8 really tiny decimal integers 0-1
; note: we could do 16, but 'cbuf' needs to be enlarged
; this is so inefficient, they wouldn't be able to use all 16
convtbin:	mov		bx,0
			mov		cl,8
convtbinl:  mov		dl,al
			and		dl,1
			add		dl,'0'
			mov		cbuf[bx],dl
			mov		cbuf+1[bx],cr
			mov		cbuf+2[bx],lf
			add		bx,3
			shr		ax,1
			dec		cl
			jnz		convtbinl
			retn

; CONVT16I -- convert to decimal intgr, unsigned, from AX, cut leading zeros
; enter at convt16ib if BX is already set
; enter at convt16ic to use a smaller digit count, set in CH
convt16i:   mov		bx,0			;storing pointer
convt16ib:	mov		ch,5			;digit counter
			mov		cl,0			;leading 0 indicator
			xor		dx,dx			;hi 16 bits=0
c16loop:	div		K10000			;strip off 1 digit into AX
			push	dx				;remainder, save for next loop
			cmp		ch,1			;if last digit, always print
			jz		c16yp
			or		cl,al			;quotient, is digit to print now
			jz		c16ix
c16yp:		add		al,'0'			;(is most signif)
			mov		cbuf[bx],al		;store it
			inc		bx
c16ix:		pop		ax				;next (reduced) value
			mul		K10				;note- may put bits into DX
			dec		ch
			jnz		c16loop
			jmp		xxret			;add terminators

; CONVT32 -- new value is in DX:AX, convert to text, store in cbuf[]
; always returns 13 chars: point, 10 digits, cr lf
; returns with BX: n chars put in buffer
convt32:    mov		obcount,10
			mov		cx,14074		;lower byte contains rounding const only
convt32x:	mov		bx,0
			jmp		convtfrac

; CONVT48 -- new value is in DX:AX:CX, convert to text, store in cbuf[]
; always returns 17 chars: point, 14 digits, cr lf
; returns with BX: n chars put in buffer
convt48:    mov		obcount,14
			add		cx,1			;add rounding const (should be 1.407)
			adc		ax,0
			adc		dx,0
			jmp		convt32x

; CONVTNORM -- new value is in CH.CL:DX:AX, convert to intgr & frac
; returns 12 chars if +, 13 chars if -
; returns with BX: n chars put in buff
; fix for 386
convtnorm:	mov		bx,0			;storing pointer
            test	ch,80h
            jns		nosign32		;if +
			mov		cbuf[bx],'-'	;if -, show sign
            inc		bx
nosign32:   and		ch,7Fh			;get rid of sign
			add		ch,'0'
			mov		cbuf[bx],ch		;show integer digit
			inc		bx
			mov		ch,al			;move all bytes down 1
			mov		al,ah			;convert from 5-byte fxp format to
			mov		ah,dl			;whole word fraction DX:AX:CX
			mov		dl,dh
			mov		dh,cl
			mov		cl,0
			mov		obcount,9		;digit counter =9
			test	dmode,4			;if 48 bit mode, convt 12
			jz		norm9d
			mov		obcount,12
norm9d:
; convert fraction:  frac in DX:AX:CX, BX= index into cbuf
; add rounding constant for correct precision before coming here
; also set 'obcount' to correct no of digits
; this loop multiplies arg by 10 n times, gets a digit each time
convtfrac:	mov		cbuf[bx],'.'	;show dec pt
            inc		bx
			IF		0				;E ver-3			;386 version
			shl		edx,16			;note: needs to be fixed for 48 bits
			mov		dx,ax			;get entire arg into 32b reg
			mov		eax,edx			;stays in EAX
			mov		cl,9			;digit counter
xx332:		mul		kk10			;digit loop: eax is frac
			add		dl,'0'
			mov		cbuf[bx],dl
			inc		bx
			dec		cl				;count down digits
			jnz		xx332
			ELSE					;8086 version
			mov		argu,dx 		;save argument
			mov		argu2,ax
			mov		argu3,cx
xx332:		mov		ax,argu3		;digit loop: 'argu:argu2:argu3' = fraction
			mul		k10				;mpy least signif word
			mov		argu3,ax
			mov		cx,dx			;save intermed in CX
			mov		ax,argu2
			mul		k10  			;mpy middle word
			add		ax,cx
			adc		dx,0
			mov		argu2,ax
			mov		cx,dx
			mov		ax,argu			;mpy upper word
			mul		k10				;result in dx:ax
			add		ax,cx			;add ovflo from intermed
			adc		dx,0
			mov		argu,ax
			add		dl,'0'
			mov		cbuf[bx],dl
			inc		bx
			dec		obcount			;count down digits
			jnz		xx332
			ENDIF
; finally add a newline & exit
            jmp		xxret

; CONVTH4 -- new value is in AX, convert & send 4 hex digits
; always returns 4 chars
; Note: lowest nibble is sent first, so hi bits are always last
; bx: storing pointer
convth4:	mov		bx,0
xxh4:		mov		cl,al			;get the nibble
			and		cl,0Fh
			cmp		cl,10
			jb		xxh4d
			add		cl,7
xxh4d:		add		cl,'0'
			mov		cbuf[bx],cl
			mov		cl,4
			ror		ax,cl			;get the 4 bits you want
			inc		bx
            cmp		bx,4
			jb		xxh4
			retn

			IF		0
; convthex -- convert & send hex value (from ax)
; bx: storing pointer
convthex:	mov		cbuf[bx],' '
			inc		bx
			mov		ch,4
xx4:		mov		cl,4
			rol		ax,cl			;get the 4 bits you want
			mov		cl,al
			and		cl,0Fh
			cmp		cl,10
			jb		xx4d
			add		cl,7
xx4d:		add		cl,'0'
			mov		cbuf[bx],cl
			inc		bx
			dec		ch
			jnz		xx4
			retn
			ENDIF

; GETWORD -- get 1 word from the buffer, return in AX
; if nothing there even after waiting for timeout, return C=1
getword:	cmp		pollmode,0
			jnz		getwpo			;if poll mode
			mov		ax,TIMOUT		;set up timeout
xxwait:		mov		bx,buffout		;is there something in buffer
			cmp		bx,buffin
			jnz		issome
			dec		ax				;count 65K tries
			jnz		xxwait
			stc						;set error flag
			retn
issome:		shl		bx,1			;make byte index
			mov		ax,buff[bx]		;get data wd
			inc		buffout			;push up index
			and		buffout,BUFFSZ-1 ;wrap if nec.
			clc						;non-error flag
			retn
; getword in polling mode- just wait for 4 nibbles to come along
; note- this will hang up if device isn't operating
getwpo:     mov		ch,4			;count nibbles
			xor		bx,bx			;acum
			mov		pollast,0FFh
			mov		cx,TIMOUT		;timeout
getwpol:	mov		dx,devcode
			inc		dx				;use code+1
			in		al,dx
			mov		ah,pollast		;maintain last
			mov		pollast,al		;AH has last, AL has current
			test	ah,040h			;look at bit 6- was it 0 before
			jnz		getwpow			;no, wait
			test	al,040h			;and 1 now
			jz		getwpow			;no
			in		al,dx			;read again after delay
			mov		ah,al
			and		al,0B8h			;saves all 4
			and		ah,38h			;saves lower 3
			add		ah,al			;shifts lower 3 bits L 1 place
			xor		al,al			;now in top 4b of AX (only)
			mov		cl,4			;shift accum R 4
			shr		bx,cl
			or		bx,ax			;'or' new bits in
			dec		ch
			jnz     getwpol			;next nibble
			mov		ax,bx
			clc						;non-error flag
			retn
getwpow:	dec		cx				;timeout loop
			jnz		getwpol			;still ok
tretnc:		stc						;timeout, return error
tretn:		retn					;note: getnorm jumps here too

; ********* GETNORM -- get a normal-distribution number into CH.CL:DX:AX
; returns sign/magnitude format: CH has sign in bit 7
; returns C=1 if no data avail
getnorm:	mov		normtimo,100
;			inc whcall
;			mov	whstep,0
nstep1:     dec		normtimo		;how many times have we been here
			jz		tretnc			;too many w/no result, quit
			call	getunif			;into DX:AX also possibly CX
			jc		tretn			;if no data
			xchg	al,cl			;convert to 5-byte fxp format
			mov		normsign,cl		;save upper bit as sign
			and		normsign,80h
			test	dmode,20h
			jz		nstep1a			;if full width
			test	dmode,10h		;tail only: want signed?
			jnz		nstep1s
to_nstep11:	jmp		nstep11			;want signed, get 2 more unif's
nstep1s: 	jmp		nstep11a		;want unsigned- use this, get 1 more
nstep1a:	and		cl,7Fh			;clear sign bit in U
			mov		normu,ax  		;save in 'normu'
			mov		normu+2,dx
nstep2:     mov		bl,cl
			mov		bh,0
			mov		normi,bx		;save I as word
nstep3:     test	dmode,4			;32 or 48 bit mode?
			jz		nstep3a			;if 32bit, K is taken from B2 xor B4
			mov		dh,ch			;if 48bit, K is taken from CH (extra byte)
			mov		ch,0
			jmp		nstep3b
nstep3a:	xor		dh,ah			;get b2 xor b4, 6 bits only, is K
nstep3b:	and		dh,3Fh
			mov		normk,dh
			mov		normu+4,cx		;save upper byte
nstep4:		cmp		dh,tableq[bx]	;compare K with Q[i]
			jl		nstep7			;if K < Q[i]
nstep5:		mov		bl,tablea[bx]	;alias: set I to a[i]
			cmp		bl,255			;if -1, do tail case
			jz		to_nstep11
nstep6:		mov		byte ptr normu+4,bl	;replace I
			mov		byte ptr normi,bl	;not necessary
;			mov whstep,6
			call	ux8z			;mpy U x 8
			jmp		nstep8
nstep7:		call	ux8z
;			mov whstep,7
			mov		bx,normi
			dec		bx				;get i-1
			mov		al,tabley[bx]	;want y[i-1] - y[i]
			sub		al,tabley+1[bx]
            cmp     normk,al		;is K <= ()
            jle		nstep9			;yes, go to A/R test
nstep8:		mov		ax,normx		;return; here X is in 'normx'
			mov		dx,normx+2
			mov		cx,normx+4
			test	dmode,10h		;do they want unsigned values
			jnz		nstep8x			;yes
			or		ch,normsign		;return sign in CH, others unchanged
nstep8x:    add		word ptr ncount,1	;count normals generated
			adc		word ptr ncount+2,0
			clc
getnormx:	retn
; ----- A/R (accept/reject) test ---------------
nstep9:
;			mov whstep,9
			call	getunif			;A/R test: generate a new U
			jc		getnormx		;if no data
			xchg	al,cl
			mov		ch,0
			mov		normu2,ax 		;set up full 3-word var
			mov		normu2+2,dx
			mov		normu2+4,cx
			call	xs2t			;get X^2/2, put in T
			mov		bx,normi		;now get I, y[i-1], y[i]
			dec		bx				;get i-1
			mov		ch,tabley[bx]	;want y[i-1] - y[i] +1
			sub		ch,tabley+1[bx]
			inc		ch
			mov		dx,0
			mov		ax,dx
			mov		cl,dh			;now mpy by U2, put into V
			mov		si,offset normu2
			mov		di,offset normv
			call	umpy
			mov		bx,normi		;now add y[i] to result
			mov		ah,tabley[bx]
			mov		al,0
			add		normv+4,ax
			mov		di,offset normv	;now mpy all of it by the constant C
			mov		si,offset normconc
			call	umpysame		;now have V (in normv)
nstep10:	call	vttest			;do the (V > exp(-T)) test
			cmp		al,0			;returns al=1 reject, 0 accept
			jz		nstep8			;accept
to_nstep1:	jmp		nstep1			;reject (V > exp(-T))
; ----------- "tail" case- get 2 new uniform no's ------------
nstep11:
			call	getunif			;get a new uniform no
tgetnormx:	jc 		getnormx
			xchg	al,cl
nstep11a:	mov		ch,0
			cmp		cx,15			;this is approx 1/17
			jb		to_nstep1		;reject if too small
			mov		normu,ax		;save in U
			mov		normu+2,dx
			mov		normu+4,cx 		;all 3 words please
			call	recip			;gets 1/U
			IF		0	;E		ver-3
			shrd	ax,dx,2
			shrd	dx,cx,2
			shr		cx,2
            ELSE
			shr		cx,1			;now get .25/U
			rcr		dx,1
			rcr		ax,1
			shr		cx,1
			rcr		dx,1
			rcr		ax,1
			ENDIF
			add		cx,960			;add 3.75
			mov		normx,ax		;this becomes the new X
			mov		normx+2,dx
			mov		normx+4,cx
			call	xs2t			;get X^2/2, put in T
			sub		normt+4,800h	;subtract 8 from integer part
			call	getunif			;get 2nd uniform
			jc		tgetnormx
			xchg	al,cl
			mov		ch,0
			mov		normu2,ax		;stash in normu2
			mov		normu2+2,dx
			mov		normu2+4,cx
			mov		si,offset normcond
			mov		bx,offset normu
			mov		di,offset normv
			call	umpybx			;get d * U
			mov		si,offset normu	
			call	umpysame		;mpy by U again
			mov		si,offset normu2
			call	umpysame		;mpy by U2
			jmp		nstep10			;T, V are now set, do A/R test

; ------------ VTTEST -- is V > exp(-T)  if yes, al=1, 0 if no
vttest:
;			mov normc,0
nstepa:		cmp		normt+4,0B1h	;if T >= ln 2 (approx), reduce it
			jbe		nstepc			;ok, go on to step c
nstepb:		sub		normt,0F7D1h   	;subtract ln 2 from T (needs to be exact)
			sbb		normt+2,7217h
			sbb		normt+4,0B1h
            shl		normv,1			;and double V
            rcl		normv+2,1
            rcl		normv+4,1
			cmp		normv+4,100h	;if V <= 1 goto a
			jbe		nstepa
vtreject:	mov		al,1			;if > 1, reject
			retn
nstepc:		mov		ax,normt		;V = V -1 +T
;			mov normc,1
			mov		dx,normt+2
            mov		cx,normt+4
			sub		cx,100h			;subt 1
            add		normv,ax
            adc		normv+2,dx
			adc		normv+4,cx
			jl		vtaccept		;accept if V < 0
			mov		ax,normv+4		;or if V = 0  (all 3 words)
			or		ax,normv+2
			or		ax,normv
			jnz		nstepd
vtaccept:	mov		al,0			;accept if V <= 0
			retn
nstepd:     mov		ax,normt		;copy T to R
			mov		dx,normt+2
            mov		cx,normt+4
            mov		normr,ax
            mov		normr+2,dx
            mov		normr+4,cx
			mov		normc,2			;set C =2
stepdloop:	mov		si,offset normt	;R = R * T
            mov		di,offset normr
            call	umpysame
			mov		ax,0			;now get C * V (V is signed)
			mov		dx,ax			;we will mpy by adding
            mov		cx,ax
            mov		bx,normc
mpycvloop:	add		ax,normv
			adc		dx,normv+2
            adc		cx,normv+4
            dec		bx
            jnz		mpycvloop
            test	normc,1			;now, is C even or odd
            jnz		stepdodd
            sub		ax,normr		;if even, subtract R
            sbb		dx,normr+2
            sbb		cx,normr+4
          	js		stepdcom
            jmp		vtreject		;reject if V >= 0
stepdodd:	add		ax,normr		;if odd, add R
			adc		dx,normr+2
            adc		cx,normr+4
            jl		vtaccept		;accept if V < 0
stepdcom:	mov		normv,ax		;re-store
			mov		normv+2,dx
			mov		normv+4,cx
            inc		normc    		;C = C+1
            jmp		stepdloop

; ------------ XS2T -- calculate X^2 /2, put in T
xs2t:		mov		si,offset normx
			mov		ax,0[si]		;now calc X^2 /2
			mov		dx,2[si]
			mov		cx,4[si]
			shr		cx,1
			rcr		dx,1
			rcr		ax,1
			mov		di,offset normt
			jmp		umpy			;T = x^2 /2

; ---------- UX8 -- mpy U by 8 and put result in X
ux8z:		mov		ax,normu
			mov		dx,normu+2
			mov		cx,normu+4
			mov		ch,0				;clear integer part
			mov		bl,3				;shift 'normu' L 3
ux8loop:	shl		ax,1
			rcl		dx,1
			rcl		cx,1
			dec		bl
			jnz		ux8loop
			mov		normx,ax
			mov		normx+2,dx
			mov		normx+4,cx
			retn

; GETUNIF -- get a 32-bit (uniform distrib) no in DX:AX, cx=0
; to convert to 5-byte fxp format, xchg cl,al
; Note: if dmode bit 4 =1, get 48 bits; DX:AX:CX
; returns carry=1 if no data available
getunif:    call	getword
			jc		getuerr			;if no data
			push	ax
			call	getword			;have 2 words, in AX & stack
			jc		getunifa		;if err, pop stack then exit
			mov		cx,0
			test	dmode,4			;is it 48 bit mode (TEST clears carry)
			jz		getunifa		;no
			push	ax				;yes, get word #3
			call	getword
			pop		cx
getunifa:	pop		dx
			jc		getuerr
			add		word ptr ucount,1	;count uniforms used
			adc		word ptr ucount+2,0
			clc
getuerr:	retn

;**************** UMPY -- unsigned fixed pt multiply *******************
; arg1 is in CX.DX:AX  (dec pt is in middle of CX; CH is integer)
; arg2 is in 3 words pointed to by SI (least signif first) (4[di] is intgr)
; DI: pointer to 3 words, result will be stored there, unchanged on exit
; result goes into umpyo, 5 words, least sig first.  last is integer part
; also returns result in registers: CX.DX:AX   DP in midle of CX
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
			IF		0  ;E ver-3			;386 VERSION
			mov		di,cx			;integer part
			mov		cx,dx			;fraction, hi
			mov		bx,ax			;fraction, lo
			mov		dx,0			;first clear result array
			mov		umpyo,dx
			mov		umpyo+2,dx
			mov		umpyo+4,dx
			mov		umpyo+6,dx
			mov		umpyo+8,dx
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
			ELSE					;86 version
            mov		di,cx			;integer part
            mov		cx,dx			;fraction, hi
            mov		bx,ax			;fraction, lo
			mov		dx,0			;first clear result array
			mov		umpyo,dx
			mov		umpyo+2,dx
			mov		umpyo+4,dx
			mov		umpyo+6,dx
			mov		umpyo+8,dx
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
			adc		umpyo+8,0
			partmpy	di,2[si],4		;2H x 1M
			adc		umpyo+8,0
			mov		ax,di			;2H x 1H
			mul		word ptr 4[si]
			add		umpyo+6,ax		;dx is not 0
			adc		umpyo+8,dx
			mov		bx,umpyo+2
			mov		ax,umpyo+4
			mov		dx,umpyo+6
			mov		cx,umpyo+8
			mov		ch,cl			;shift everything L 8b: integer part to CH
			mov		cl,dh			;but leave the 'umpy' words as before
			mov		dh,dl
			mov		dl,ah
			mov		ah,al
			mov		al,bh
			ENDIF
			pop		di
            mov		0[di],ax
            mov		2[di],dx
            mov		4[di],cx
			retn


;************* RECIP -- reciprocal of 32 bit fraction ********************
; arg in .DX:AX   result in CX.DX:AX
; DO NOT call with arg=0, infinite loop
recip:		push	si
			push	di
			mov		bl,0
recipnorm:	test 	cx,80h			;first normalize
			jnz		recipno			;when sign bit=1, quit
			shl		ax,1			;shift L 1, count shifts
			rcl		dx,1
			rcl		cx,1
			inc		bl
			jmp		recipnorm
recipno:	mov		recipnc,bl		;save norm count
			mov		bx,0
			mov		di,bx			;set up dividend
			mov		si,100h
			mov		recipql,bx		;clear lower quo word (uppers will shift L)
			mov		recipcc,41		;loop count
reciploop:	sub		bx,ax			;subt divisor from dividend
			sbb		di,dx
			sbb		si,cx
			cmc						;C=1 if it went in
			jc		recipok			;if it went in
			add		bx,ax			;if it didnt go in, add back
			adc		di,dx
			adc		si,cx
			clc
recipok:	rcl		recipql,1			;slurp carry into the quotient
			rcl		recipqm,1
			rcl		recipqh,1
			shl		bx,1			;also shif dividend L 1
			rcl		di,1
			rcl		si,1
			dec		recipcc
			jnz		reciploop		;do 41X
			mov		ax,recipql		;done, get quo into CL.DX:AX
			mov		dx,recipqm
			mov		cx,recipqh
			cmp		recipnc,0		;finally, do we need to shift
			jz		recipdone
recipshl:	shl		ax,1
			rcl		dx,1
			rcl		cx,1
			dec		recipnc
			jnz		recipshl
recipdone:	pop		di
			pop		si
			retn

; SHOWHEX -- show a 4 digit hex no. on screen, from AX - for debug
; this routine belongs with INIT- is here for debugging use
showhex:	mov		bx,ax			;working value
			mov		ch,4			;digit counter
shloop:		mov		cl,4    		;loop to do 1 digit
			rol		bx,cl
			mov		dl,bl
			and		dl,0Fh
			cmp		dl,10
			jl		shdigit
			add		dl,7
shdigit:	add		dl,'0'
			call	showc
			dec		ch
			jnz		shloop
			mov		dl,' '			;finally, print 1 space
			call	showc
			retn

; SHOWDEC5 -- show 5-digit decimal no on screen, unsigned, from AX - for debug
; enter at 'showdec5t' with different term char in CL
showdec5:   mov		cl,' '			;normal term. char
showdec5t:	mov		ch,5			;digit counter
			xor		dx,dx			;hi 16 bits=0
sdloop:		div		K10000			;strip off 1 digit into DX
			push	dx				;remainder, save for next loop
			mov		dl,al			;quotient, is digit to print now
			add		dl,'0'			;(is most signif)
			call	showc			;print char from DL
			pop		ax				;next (reduced) value
			mul		K10				;note- may put bits into DX
			dec		ch
			jnz		sdloop
			mov		dl,cl			;finally, print a term char
			call	showc
			retn

; SHOWC -- show single char on screen- from DL (note***)
showc:		mov		ah,6
			int		21h
			retn

; SHOWST -- show a string on screen- DX must contain offset
; string must be terminated by 'eom'
showst:		mov		ah,9
			int		21h
			retn

; WRITE *************************************************************
; 'write' just accepts command strings for option & mode setting
; note: a string may span more than 1 'write' call; ended by c.r.
Write		proc	near				;ES:DI point to request header
			mov		dx,es:[di+rhcount]		;get byte count wanted
			mov xfrcount,dx
			mov		si,es:[di+rhdataoffs]	;source address
			mov		ax,es:[di+rhdataseg]	;use ES:SI for source
			mov		es,ax
			cmp		verbose2,0
			jz		noshowwr
			push	dx
			mov		dx,offset showwr
			call	showst
			pop		dx
noshowwr:
			cmp		dx,0
			jz      wrexit			;if nothing to do
wrloop:		mov		al,es:[si]		;get char
			cmp		al,'a'			;if lower, convert to upper
			jb		wrlnl
			cmp		al,'z'
			ja		wrlnl
			sub		al,'a'-'A'      ;is lower case, convert
wrlnl:		cmp		al,'F'
			ja		wrnext			;skip if above F
			cmp		al,'A'
			jb		wrtryd
			sub		al,'A'-10		;ok, is letter A-F
			jmp		wracm
wrtryd:		cmp		al,'0'
			jb		wrnewd			;if < '0', set up new dmode
			cmp		al,'9'
			ja		wrnext
			sub		al,'0'			;ok, is digit
wracm:      mov		cl,4
			shl		dmodeac,cl		;accum into 'dmodeac'
			or		byte ptr dmodeac,al
			inc		dmoden			;count chars accumulated
wrnext:		inc		si				;next char
			dec		dx
			jnz		wrloop
wrexit:		xor		ax,ax
			ret
; terminator seen- process the accum received so far
wrnewd:     cmp		dmoden,0		;terminator seen; were there chars
			jz      wrnext			;no, ignore
			mov		ax,dmodeac		;yes, set up new dmode
			mov 	dmode,ax
;			push dx
;			mov ax,xfrcount
;			call showdec5
;			mov ax,dmode
;			call showhex
;			pop dx
			mov 	ax,0
			mov		dmodeac,ax		;rezero acum
			mov		dmoden,al
			mov		cbufb,ax		;dump the convert buffer on any write
			mov		cbufe,ax
			jmp		wrnext
Write		endp

; OPEN -- just turns on the interrupt (in dev and 8259)
; interrupt vector was changed when driver installed
DevOpen		proc	near
			cmp		verbose2,0
			jz		noshowop
			mov		dx,offset showopn
			call	showst
noshowop:	test	fileopen,0FFh
			jnz		alredyop		;if already open, don't open again
			cmp		pollmode,0
			jnz		nosetint		;if poll mode, don't set intrr
			call	setint			;set up intrr masks
nosetint:	mov		fileopen,byte ptr 1
alredyop:	xor		ax,ax			;clear buffers to start
			mov		cbufb,ax    	;text formatting buffer
			mov		cbufe,ax
			mov		buffin,ax		;interrupt buffer
			mov		buffout,ax
			mov		b2,ax			;clear bit stats
			mov		s4,ax
			mov		b2save,ax
			mov		s4save,ax
			mov		consecbad,ax
			mov		icount,NWTEST	;restart block count
			mov		word ptr ucount,ax	;clear normal counts
			mov		word ptr ucount+2,ax
			mov		word ptr ncount,ax
			mov		word ptr ncount+2,ax
			mov		dmodeac,ax		;clear dmode accum
			mov		dmoden,al		;and char count
			test	dmode,8000h		;is dmode permanent
			jnz		opexit			;yes
			mov		dmode,88h		;default mode= normalized
opexit:		ret						;also return with AX=0 (err code)
DevOpen		endp

; CLEARSTATS -- clear the bit statistics accums-- not used now
clearstats:	mov		ax,0
			mov		cl,NWDSC
			mov		bx,ax
clrstal:	mov		icount[bx],0
			add		bx,2
			dec		cl
			jnz		clrstal
			retn

; CLOSE -- just turns off the interrupt
DevClose 	proc	near
			cmp		verbose2,0
			jz		noshowcl
			mov		dx,offset showclo
			call	showst
noshowcl:	test	fileopen,0FFh
			jz		alredycl		;if file is already closed
			cmp		pollmode,0
			jnz		nounseti		;if polling mode
			call	unsetint		;restore intrr pointer
nounseti:	mov		fileopen,byte ptr 0
alredycl:	xor		ax,ax
			ret
DevClose 	endp

bogus7:		mov		dx,devcode
			add		dx,2
			and		statbits,0F6h
			mov		al,statbits		;turn status bit 0 & 3 on
			out		dx,al
			jmp		intexit

; *******************************************************************
; Device interrupt  routine - working driver version
; this handler needs: 'devcode'
inthand   PROC
		;
		;--- save machine state ---
		;
			push	ax
			push	bx
			push	cx
			push	dx
			;push    es      		; save segment registers - es not used
			push    ds

			;--- load DS with data segment for this block of data ---
			mov		ax,cs
			mov		ds,ax

;			mov		al,0Bh				;test for bogus interrupt
;			out		20h,al				;TEMP !!
;			in		al,20h				;bit 7=1 if ok
;			test	al,80h
;			jz		bogus7				;no, skip

			IF		STATOUT
			mov		dx,devcode
			add		dx,2
			and		statbits,0FEh
			mov		al,statbits		;turn status bit 0 on
			out		dx,al
			ENDIF
			jmp intexit

			mov		dx,devcode		;read the data byte
			inc		dx				;379h
			in		al,dx

			;
			;--- Get the 4 bits all together (eliminate bit 6 gap)
			mov		ah,al
			and		al,0B8h			;saves all 4
			and		ah,38h			;saves lower 3
			add		ah,al			;shifts lower 3 bits L 1 place
			xor		al,al			;now in top 4b of AX (only)

			;
			;--- if internal-xor mode, combine this with last
			test	dmode,1000h
			jz		notxorm			;not xor mode
			add		xorcnt,80h		;xor mode: which phase is this
			jns		xorc2
			mov		xorlast,ah		;phase 1- just store the nibble, quit
			jmp		intexit
xorc2:		xor		ah,xorlast		;phase 2- combine with previous
notxorm:
			;
			;--- Combine into 16-bit word accumulator
			mov		bx,wordtmp
			mov		cl,4			;shift accum 4b right
			shr		bx,cl
			or		ax,bx			;'or' in the new 4b (in MSB's)
			xchg	wordtmp,ax		;re-store, save old 16b in AX
			dec		c4				;have we done 4
			jnz		not4n			;not yet
			;
			;--- We now have a 16-bit word- store it & set flag
			mov		c4,4

			;now accum word into bit statistics- is in WORDTMP
			;accumulated in blocks of 100k bits (5 sec @20K/s)
			;for B2, we accum (n 1's - n 0's) /2  =-2,-1,0,1,2
			;actual Z score= 2 * b2 / sqrt(100k)
			;for S1, we xor w/shifted data, accum (n 0's - n 1's) /2
			;actual Z score= 2 * S1 / sqrt(100k)
			;first get xor of this wd & 4 bits earlier, for serial corr
			xor		ax,wordtmp		;serial corr xor
			call	bitcntw
			add		dx,s4			;add into s4 accum (note: is neg)
			jo		s1full			;if ovflo, don't rewrite to mem
			mov		s4,dx
s1full:     mov		ax,wordtmp		;now get B2
			call	bitcntw			;how many bits in this wd (count-8)
			add		dx,b2
			jo		b2full			;if overflow, don't rewrite to mem
			mov		b2,dx
b2full:		dec		icount			;count words
			jz		resetwd			;ran out, reset
endtest:	mov		ax,wordtmp		;get new val back into AX

			;--- also store in buffer, if there is room
			mov		bx,buffin
			shl		bx,1			;make byte index
			mov		buff[bx],ax		;store the word
			shr		bx,1			;now, is there room
			inc		bx	 			;new value of buffin (hopeful)
			and		bx,BUFFSZ-1
			cmp		bx,buffout		;did it become = to buffout
			jz		isfull			;yes, is full
			mov		buffin,bx		;not full, update buffin
isfull:
not4n:
intexit:	;
			;--- acknowledge the interrupt ---
			mov     al,EOI          ;eoi to interrupt controller
			out     OCR,al          ;
			;

			IF		STATOUT
			mov		dx,devcode
			add		dx,2
			or		statbits,1
			mov		al,statbits		;turn status bit 0 off (is inverted)
			out		dx,al
			ENDIF

			;--- restore machine state ---
			;
			pop    	ds       		;restore registers
			;pop    es       		;
			pop		dx
			pop		cx
			pop		bx
			pop		ax
;			jmp 	[old_intv]
;			old_off
;            old_seg
			iret
; stats block is complete-- process it & post bad flag if nec
resetwd:	mov		ax,0 			;end of stats block- get b2, s4
			mov		cx,ax
			xchg	ax,b2			;and clear them at same time
			mov		b2save,ax
			xchg	cx,s4			;(note: s4 is neg.)
			mov		s4save,cx
			add		ax,zlimit		;if -zlimit, is now =0
			cmp		ax,zlimit2		;so is ok if 0..(zlimit*2)
			ja		wdtestbad		;&bad if (zlimit*2) .. 65535
			add		cx,zlimit
			cmp		cx,zlimit2
			ja		wdtestbad
			mov		consecbad,0		;data ok, clear consecbad count
newtest:	mov		icount,NWTEST	;restart the counter
			jmp		endtest
wdtestbad:	inc		consecbad		;count up another bad blk
			jnz		newtest
			dec		consecbad		;if overflow, don't wrap to 0
			jmp		newtest
inthand 	endp

;************ BITCNTW -- get bitcount in AX, return in DX ************
; subtract 8, so range is -8 .. +8  -- clobbers AX
bitcntw:	mov		dx,0
			cmp		ax,0
			jz		bitcntwx		;nothing to do
bitcntwl:   inc		dx
			mov		cx,ax			;ok, remove a bit
			dec		cx      		;this loop removes the least sig. 1 bit
			and 	ax,cx
			jnz		bitcntwl
bitcntwx:	sub		dx,8
			retn


; *********** SETINT routine -- set up interrupt ************
; uses global 'devcode' and 'intrrmx'
; also enables the interrupt in the PIC chip(s)
setint:
;unmask irq7
			IN    	AL, 21h			; get contents of PIC
			mov   	old_msk,al   	; save old contents
			mov		ah,intrrmx		; get new mask bit
			xor		ah,0FFh			; complement
			AND   	AL, ah		   	; set off the bit for IRQ7
			OUT   	21h, AL        	; send it to the controller

;enable interrupt in the device
			mov		dx,devcode		;enable intrrs
			add		dx,2			;37A
			mov		al,01Bh			;int on, others off
			mov		statbits,al		;save in soft copy, but don't write thru
			out		dx,al
setintx:	retn

; *********** UNSETINT routine -- turns off interrupt ************
; uses global 'devcode',  'old_msk', and 'intrrmx'
; also disables the interrupt in the PIC chip(s)
unsetint:
			mov		dx,devcode			;disable intrr in device
			add		dx,2
			mov		al,0Bh			;int off, others off
			mov		statbits,al
			out		dx,al

; restore old intrr vector
; not used- intrr vector is set once, never restored
;			push	ds
;			mov		dx,old_off	    ;get the original vector
;			mov		ax,old_seg
;			mov     ds,ax
;			mov     ah,SetIntVect   ;dos command code => AH
;			mov     al,intrrcd      ;interrupt number => AL
;			int     21h		        ;set original vector
;			pop		ds

;	reset the pic:
			MOV   	DX, 21H       	;address of the PIC
			in		al,dx			;get present contents
			mov		ah,old_msk
			and		ah,intrrmx		;get 1 mask bit from old
			or		al,ah
			OUT   	DX, AL        	;set it
			retn

NdRead	proc	near
		xor		ax,ax
		ret
NdRead	endp

InpStat	proc	near
		xor		ax,ax
		ret
InpStat	endp

InpFlush proc	near
		xor		ax,ax
		ret
InpFlush endp

OutStat	proc	near
		xor		ax,ax
		ret
OutStat	endp

OutBusy	proc	near
		xor		ax,ax
		ret
OutBusy	endp

; ******************************************************************
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
jtest		dw		offset fixeol

; INIT procedure
Init		proc	near
			push	es
			push	di

; is this the 386 version? and are we running in <386? trouble--
			IFE		ver-3
            pushf                   ;save flags
            push	sp				;first the 8086 test
			pop		ax				;is 86 if SP decrements before a
			cmp		sp,ax			;value is pushed
			jne		bad386
			pushf					;not 86-- now the 286 test
			pop		ax				;bit 14 in the flags reg can't be set
			or		ax,4000h
			push	ax
			popf         			;set flags reg
			pushf					;now read flags
			pop		ax
			test	ax,4000h
			jnz		ok386
bad386:     popf
			mov		dx,offset Idbad386a
			call	showstr
		    mov		dx,offset Idbad386b
			call	showstr
		    mov		dx,offset Idbad386c
			call	showstr
            jmp		badexit
ok386:      popf
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
;			push di
;testll:		mov dl,es:[di]
;			call showc
;			inc di
;			cmp byte ptr es:[di],0
;			jnz testll
;            pop di
; loop to get 1 parameter setting, es:di is char pntr
fixskip:	inc		di				;skip over device name
			mov		al,es:di		;by skipping all print chars (not sp)
			cmp 	al,20h
			ja		fixskip
			jmp		fixloop
fixlinc:	inc		di
fixloop:	call	scanblks		;skip white space
			jz		fixlinc			;if this is wht sp
			cmp		al,0Ah
			jz      fixlx
			cmp		al,0Dh
			jz		fixlx
			cmp		al,0
			jnz		fixl2
fixlx:		jmp		[jtest] ;fixeol			;eol, no more specs given
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
;			pusha
;			mov ax,bx
;			call showdec5
;			popa
			cmp		ax,clocktimx	;new tick: have time diff
			jb		wsslo			;maintain max value
			mov		clocktimx,ax
wsslo:		add		clocktiml,ax	;maintain sum (32b)
			adc		clocktimh,0
			inc		cl				;if it rose, this is a new tick
			cmp		cl,37			;timer wraps around every 25ms
			jb		wait1s			;if not there yet

; Show the clock tick average & max times
;			mov		dx,offset Idclock
;			call	showstr
;			mov		ax,clocktiml	;get avg
;			mov		dx,clocktimh
;			div		k37
;			call	showdec5
;			mov		ax,clocktimx	;max
;			call	showdec5

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
			mov		pollmode,1
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
			call	showcr
noshowa:

; Check DOS revision; if 6.2, operate in polling mode only
;			mov		ax,3000h
;			int		21h
;			cmp		al,6
;			jb		olddosrev
;			mov		pollmode,1
;			mov		dx,offset Idpollms
;			call	showstr
;olddosrev:

; misc. jobs
			mov		ax,zlimit		;set up zlimit2
			shl		ax,1
			mov		zlimit2,ax

; lastly, fiddle with the BIOS parallel port control words
; to remove this port from the list of printers
; if user manually specs a dev code that isn't in list, do nothing
			mov		ax,40h
			mov		es,ax
			IF 0 					;show BIOS list before & after
			mov ax,es:[8h]
			call showhex
			mov ax,es:[0Ah]
			call showhex
			mov ax,es:[0Ch]
			call showhex
			mov ax,es:[0Eh]
			call showhex
			mov ax,es:[10h]
			call showhex
			call showcr
			ENDIF
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
			IF  0
			mov ax,es:[8h]
			call showhex
			mov ax,es:[0Ah]
			call showhex
			mov ax,es:[0Ch]
			call showhex
			mov ax,es:[0Eh]
			call showhex
			mov ax,es:[10h]
			call showhex
			call showcr
			ENDIF

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

; ******* SCANBLKS -- is the current char white space (blanks & tabs) ******
; es:di is char pointer
; returns Z flag =true if whitespace
scanblks:	mov		al,es:[di]
			cmp		al,' '
			jz		scanblr			;if space
			cmp		al,9
scanblr:    retn

; ********** TOUPPER -- convert AL to upper case if l.c.
toupper:	cmp		al,'a'
			jb		toupperx
            cmp		al,'z'
            ja		toupperx
            sub		al,20h
toupperx:	retn

; ********* SCANHEX -- scan string for a hex no. *************
; return result in DX, n digits in CH, term char in AL
; will not skip whitespace, you have to have done that already
scanhex:	mov		dx,0
			mov		ch,dl
scanhexl:	mov		al,es:[di]		;get next char
			call	toupper			;in case it's l.c.
            sub		al,'A'
            cmp		al,'F'-'A'
            ja 		schdig			;not letter, try digit
            add		al,10			;ok, is hex digit
            jmp		schacum
schdig:		sub		al,'0'-'A'
			cmp		al,'9'-'0'
            ja		schexit			;not letter or digit, exit
schacum:	mov		cl,4 			;ok, accum into DX
			shl		dx,cl
            add		dl,al
            inc		ch				;count chars
            inc		di				;push up pointer
            jmp		scanhexl
schexit:	add		al,'0'			;restore term char
			retn					;& get out

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

; SHOWCR -- print cr/lf on screen
; do not call this routine except during init
showcr:		mov		dx,offset Idportcr
									;then fall thru to showstr

; SHOWSTR -- show a string on screen- DX must contain offset
; string must be terminated by 'eom'
showstr:	mov		ah,9
			int		21h
			retn

; SHOWDEC -- show a decimal no. up to 655359, from DX:AX
; cuts out leading zeros
; NOTE- enter at SHOWDECA if arg is in AX only, it clears DX
; Note- wipes out registers, doesn't save BX
showdeca:	mov		dx,0
showdec:	mov		bx,offset sdbuf+9
			mov		cl,eom
			mov		[bx],cl			;work backwards, str ended by eom
			dec		bx
			mov		cl,' '			;and a space after the no
			mov		[bx],cl
sddloop:	div		k10				;quo in AX, rem in DX
			add		dl,'0'
			dec		bx
			mov		[bx],dl
			mov		dx,0			;clear upper dividend for next
			cmp		ax,0			;is there more
			jnz		sddloop
			mov		dx,bx			;offset to str
			jmp		showstr			;let showstr finish the job

; ********* Recipr -- find reciprocal of an integer (unsigned) ************
; finds 1E6 / AX, converts rate/sec to (usec per event)
; returns result in AX; carry=0 if ok, 1 if overflow
; arg must be 16 thru 65535
recipr:
			mov		bx,ax
			cmp		bx,16
			jae		recpok
			stc						;overflow- return C=1
			mov		ax,0FFFFh
			retn
recpok:		mov		dx,15			;get 1 million in DX:AX
			mov		ax,16960
			mov		cx,bx
			shr		cx,1
			add		ax,cx			;round by adding 1/2 of divisor
			adc		dx,0
			div		bx				;leaves quo in ax
			clc						;normal return: C=0
			retn

Idbad386a	db		cr,lf,'Error- 386 QNG driver, not running in 386',eom
Idbad386b	db		cr,lf,'QNG Driver not loaded',eom
Idbad386c	db		cr,lf,'You must re-install QNG software',eom
Idports		db		cr,lf,'Parallel ports installed at ',eom
Idclock		db		cr,lf,'Clock tick avg/max: ',eom
Idrate		db		cr,lf,'QNG Data rate   ',eom
Idcorr		db		'Serial corr  ',eom
Idssov		db		'Ovflo ',eom
Idintrr		db		'Interrupt 5&7: P=',eom
Idirise		db		'rise=',eom
Idifall		db		'fall=',eom
Iditot		db		'tot=',eom
Iddevc		db		'QNG using Device ',eom
Iddevi		db		'  Interrupt ',eom
Idintboth	db		'Interrupts 5, 7 both active, using 7',cr,lf,eom
Idintnone	db		'No interrupt active, using polling',cr,lf,eom
Idnone		db		'No QNG device is attached',cr,lf,eom
Idnoneb		db		'QNG Driver was not loaded',cr,lf,eom
Idbadfmt	db		'Bad format in DEVICE= command line',cr,lf,eom
Ident		db		'QNG device driver loaded ',eom
Idpollms	db		'Polling mode',cr,lf,eom
Idportcr	db		cr,lf,eom
Intr		endp

_TEXT	ends

; Facts learned while debugging this program:
; 1	MSDOS doesn't call the driver to get the n chars the application requests
;	it fills its buffer of 512 when needed (in cooked mode) (old stream I/O)
;   new stream i/o gets the exact number
; 2	This program may not have any instructions that contain a relocatable
;	address offset, since there is no way to relocate them at run time
;	assume that ds=cs =start of module on entry
;	(offsets are OK, segments aren't) 
; 3 "MOV" does NOT set any condition flags. Use CMP or TEST. watch out!
; 4 "fgets" (in C) w/intrrs returns error under DOS6.2 ok under 5.0
;	can't fool with intrr vectors after opening file
; 5 When declaring data arrays, remember to say "dw n dup(0)"
; 6	Open device for both read&write; do rewind in between

		end
