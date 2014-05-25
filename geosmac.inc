
;GEOS macros
;reassembled for 6502TASM/MMS by Maciej 'YTM/Alliance' Witkowiak
;4-2-99

LoadB	.macro	;dest, value
	lda #\2
	sta \1
	.endm

LoadW	.macro	;dest, value
	lda #>\2
	sta \1+1
	.if (>\2)!=(<\2)
	lda #<\2
	.fi
	sta \1+0
	.endm

MoveB	.macro	;source, dest
	lda \1
	sta \2
	.endm

MoveW	.macro	;source, dest
	lda \1+1
	sta \2+1
	lda \1+0
	sta \2+0
	.endm

add	.macro	;source
	clc
	adc \1
	.endm

AddB	.macro	;source, dest
	lda \1
	clc
	adc \2
	sta \2
	.endm

AddW	.macro	;source, dest
	lda \1+0
	clc
	adc \2+0
	sta \2+0
	lda \1+1
	adc \2+1
	sta \2+1
	.endm

AddVB	.macro	;value, dest
	lda \2
	clc
	adc #\1
	sta \2
	.endm

AddVW	.macro	;value, dest
	clc
	lda #<\1
	adc \2+0
	sta \2+0
	.if ((\1 >= 0) & (\1 <= 255))
	.if ((\2 >= 0) & (\2 <= 255))
	bcc *+4
	.else
	bcc *+5
	.fi
	inc \2+1
	.else
	lda #>\1
	adc \2+1
	sta \2+1
	.fi
	.endm

sub	.macro	;source
	sec
	sbc \1
	.endm

SubB	.macro	;source, dest
	lda \2
	sec
	sbc \1
	sta \2
	.endm

SubW	.macro	;source, dest
	lda \2+0
	sec
	sbc \1+0
	sta \2+0
	lda \2+1
	sbc \1+1
	sta \2+1
	.endm

SubVW	.macro	;value,	dest
	sec
	lda \2+0
	sbc #<\1
	sta \2+0
	lda \2+1
	sbc #>\1
	sta \2+1
	.endm

CmpB	.macro	;source, dest
	lda \1
	cmp \2
	.endm

CmpBI	.macro	;source, immed
	lda \1
	cmp #\2
	.endm

CmpW	.macro	;source, dest
	lda \1+1
	cmp \2+1
	.if (((\1 >= 0) & (\1 <= 255)) & ((\2 >=0) & (\2 <= 255)))
	bne *+6
	.else
	.if (((\1 >= 0) & (\1 <= 255)) | ((\2 >= 0) & (\2 <= 255)))
	bne *+7
	.else
	bne *+8
	.fi
	.fi
	lda \1+0
	cmp \2+0
	.endm

CmpWI	.macro	;source, immed	
	lda \1+1
	cmp #>\2
	.if ((\1 >= 0) & (\1 <= 255))
	bne *+6
	.else
	bne *+7
	.fi
	lda \1+0
	cmp #<\2
	.endm

PushB	.macro	;source
	lda \1
	pha
	.endm

PushW	.macro	;source
	lda \1+1
	pha
	lda \1+0
	pha
	.endm

PopB	.macro	;dest
	pla
	sta \1
	.endm

PopW	.macro	;dest
	pla
	sta \1+0
	pla
	sta \1+1
	.endm

bra	.macro	;addr
	clv
	bvc \1
	.endm

smb	.macro	;bitNumber, dest
	pha
	lda #(1 << \1)
	ora \2
	sta \2
	pla
	.endm

smbf	.macro	;bitNumber, dest
	lda #(1 << \1)
	ora \2
	sta \2
	.endm

rmb	.macro	;bitNumber, dest
	pha
	lda #(1 << \1) ^ $ff
	and \2
	sta \2
	pla
	.endm

rmbf	.macro	;bitNumber, dest
	lda #(1 << \1) ^ $ff
	and \2
	sta \2
	.endm

bbs	.macro	;bitNumber, source, addr
	php
	pha
	lda \2
	and #(1 << \1)
	beq *+7
	pla
	plp
	#bra \3
	pla
	plp
	.endm

bbsf	.macro	;bitNumber, source, addr
	.if \1=7
	bit \2
	bmi \3
	.else
	.if \1=6
	bit \2
	bvs \3
	.else
	lda \2
	and #(1 << \1)
	bne \3
	.fi
	.fi
	.endm

bbr	.macro	;bitNumber, source, addr
	php
	pha
	lda \2
	and #(1 << \1)
	bne *+7
	pla
	plp
	#bra \3
	pla
	plp
	.endm

bbrf	.macro	;bitNumber, source, addr
	.if \1=7
	bit \2
	bpl \3
	.else
	.if \1=6
	bit \2
	bvc \3
	.else
	lda \2
	and #(1 << \1)
	beq \3
	.fi
	.fi
	.endm

;03.03.1999 by Maciej Witkowiak
addv	.macro	;value
	clc
	adc #\1
	.endm

subv	.macro	;value
	sec
	sbc #\1
	.endm

bnex	.macro	;addy
	txa
	bne \1
	.endm

beqx	.macro	;addy
	txa
	beq \1
	.endm