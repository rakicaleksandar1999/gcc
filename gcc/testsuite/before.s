	.file	1 "fp_foo.c"
	.section .mdebug.abi64
	.previous
	.nan	2008
	.module	fp=64
	.module	oddspreg
	.module	arch=mips64r6
	.abicalls
	.text
	.align	2
	.align	3
	.globl	daxpy
	.set	nomips16
	.set	nomicromips
	.ent	daxpy
	.type	daxpy, @function
daxpy:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	blezc	$6,.L7
	dlsa	$6,$6,$4,2
	.align	3
.L3:
	lwc1	$f1,0($5)
	daddiu	$4,$4,4
	lwc1	$f0,-4($4)
	daddiu	$5,$5,4
	maddf.s	$f0,$f1,$f15
	bne	$4,$6,.L3
	swc1	$f0,-4($4)

.L7:
	jrc	$31
	.set	macro
	.set	reorder
	.end	daxpy
	.size	daxpy, .-daxpy
	.align	2
	.align	3
	.globl	dgefa
	.set	nomips16
	.set	nomicromips
	.ent	dgefa
	.type	dgefa, @function
dgefa:
	.frame	$sp,48,$31		# vars= 0, regs= 6/0, args= 0, gp= 0
	.mask	0x101f0000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	li	$2,1			# 0x1
	bgec	$2,$6,.L23
	daddiu	$sp,$sp,-48
	addiu	$14,$6,-1
	move	$11,$6
	sd	$20,32($sp)
	sd	$19,24($sp)
	addiu	$20,$5,1
	sd	$18,16($sp)
	move	$18,$4
	sd	$17,8($sp)
	dlsa	$10,$7,$4,2
	sd	$16,0($sp)
	move	$17,$5
	dsll	$12,$5,2
	move	$25,$5
	move	$13,$0
	move	$24,$0
	move	$15,$0
	move	$19,$14
	.align	3
.L11:
	addiu	$8,$15,1
	addiu	$16,$15,1
	move	$15,$8
	bgec	$8,$11,.L15
	daddu	$5,$25,$24
	daddiu	$9,$13,1
	dsubu	$6,$0,$13
	dsll	$5,$5,2
	dlsa	$9,$9,$18,2
	dsll	$6,$6,2
	move	$7,$14
	.align	3
.L14:
	daddu	$3,$10,$5
	move	$2,$9
	lwc1	$f2,0($3)
	move	$4,$0
	.align	3
.L13:
	daddu	$3,$6,$2
	lwc1	$f0,0($2)
	daddu	$3,$3,$5
	daddiu	$2,$2,4
	lwc1	$f1,0($3)
	addiu	$4,$4,1
	maddf.s	$f0,$f2,$f1
	swc1	$f0,-4($2)
	bltc	$4,$7,.L13
	addiu	$8,$8,1
	bne	$11,$8,.L14
	daddu	$5,$5,$12

.L15:
	daddiu	$24,$24,1
	addu	$13,$20,$13
	addiu	$14,$14,-1
	daddiu	$10,$10,-4
	bne	$19,$16,.L11
	addu	$25,$17,$25

	ld	$20,32($sp)
	ld	$19,24($sp)
	ld	$18,16($sp)
	ld	$17,8($sp)
	ld	$16,0($sp)
	jr	$31
	daddiu	$sp,$sp,48

.L23:
	jrc	$31
	.set	macro
	.set	reorder
	.end	dgefa
	.size	dgefa, .-dgefa
	.section	.text.startup,"ax",@progbits
	.align	2
	.align	3
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	jr	$31
	move	$2,$0

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (GNU) 14.0.1 20240214 (experimental)"
	.section	.note.GNU-stack,"",@progbits
