; ITEST.ASM -- assembly module for install program
; contains a test for CPU type
; returns AX=0 if 8086/286, 3 if 386 or better

			.MODEL	LARGE,C

			.DATA
temp		dw		0

			.CODE
			PUBLIC	findcpu
findcpu		PROC	FAR
			pushf                   ;save flags
			push	sp				;first the 8086 test
			pop		ax				;is 86 if SP decrements before a
			cmp		sp,ax			;value is pushed
			jne		bad386			;is 8086
			pushf					;not 86-- now the 286 test
			pop		ax				;bit 14 in the flags reg can't be set
			or		ax,4000h
			push	ax
			popf         			;set flags reg
			pushf					;now read flags
			pop		ax
			test	ax,4000h
			jz		bad386			;if 286
			mov		ax,3			;if 386
			jmp		exit
bad386:     mov		ax,0			;8086/286
exit:		popf
			ret
findcpu		ENDP
			END
