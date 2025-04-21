	.file	"A6_42_test1.nc"

#	Allocation of function variables and temporaries on the stack:

#	main
#	ep: -4
#	i: -8
#	j: -12
#	k: -20
#	printInt: -24
#	printStr: -28
#	readInt: -32
#	t0: -36
#	t1: -44
#	t10: -52
#	t11: -56
#	t12: -64
#	t13: -68
#	t14: -76
#	t15: -80
#	t16: -88
#	t17: -92
#	t18: -100
#	t19: -108
#	t2: -112
#	t20: -116
#	t21: -120
#	t22: -124
#	t23: -132
#	t24: -136
#	t25: -140
#	t26: -144
#	t27: -148
#	t28: -152
#	t29: -156
#	t3: -160
#	t30: -164
#	t31: -168
#	t32: -172
#	t4: -176
#	t5: -180
#	t6: -188
#	t7: -192
#	t8: -196
#	t9: -200

	.section	.rodata
.LC0:
	.string	" Hello "
.LC1:
	.string	"world\n"
.LC2:
	.string	"enter the i : "
.LC3:
	.string	"\n address: "
.LC4:
	.string	"\n Pointer val: "
.LC5:
	.string	"\n\nYou Entered : "
	.text
	.globl  main
	.type   main, @function
main:
.LFB0:
	.cfi_startproc
	pushq   %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq    %rsp, %rbp
	.cfi_def_cfa_register 6
	subq    $200, %rsp
	movl    $0, -36(%rbp)
	movl    -36(%rbp), %eax
	movl    %eax, -12(%rbp)
	movq    $.LC0, -44(%rbp)
	movq    -44(%rbp), %rdi
	call    printStr
	movl    %eax, -112(%rbp)
	movl    $8, -160(%rbp)
	movl    -160(%rbp), %eax
	movl    %eax, -8(%rbp)
	movl    $2, -176(%rbp)
	movl    -176(%rbp), %eax
	cmpl    %eax, -8(%rbp)
	jg      .L1
	jmp     .L2
.L1:
	movl    $75358, -180(%rbp)
	movl    -180(%rbp), %eax
	cmpl    %eax, -8(%rbp)
	jl      .L3
	jmp     .L4
.L3:
	movq    $.LC1, -188(%rbp)
	movq    -188(%rbp), %rdi
	call    printStr
	movl    %eax, -192(%rbp)
	jmp     .L4
.L4:
	movl    $2, -196(%rbp)
	movl    -8(%rbp), %eax
	addl    -196(%rbp), %eax
	movl    %eax, -200(%rbp)
	movl    -200(%rbp), %eax
	movl    %eax, -8(%rbp)
	jmp     .L2
.L2:
	movq    $.LC2, -52(%rbp)
	movq    -52(%rbp), %rdi
	call    printStr
	movl    %eax, -56(%rbp)
	leaq    -4(%rbp), %rax
	movq    %rax, -64(%rbp)
	movq    -64(%rbp), %rdi
	call    readInt
	movl    %eax, -68(%rbp)
	movl    -68(%rbp), %eax
	movl    %eax, -8(%rbp)
	movq    $.LC3, -76(%rbp)
	movq    -76(%rbp), %rdi
	call    printStr
	movl    %eax, -80(%rbp)
	leaq    -8(%rbp), %rax
	movq    %rax, -88(%rbp)
	movq    -88(%rbp), %rdi
	call    printInt
	movl    %eax, -92(%rbp)
	leaq    -8(%rbp), %rax
	movq    %rax, -100(%rbp)
	movq    -100(%rbp), %rax
	movq    %rax, -20(%rbp)
	movq    $.LC4, -108(%rbp)
	movq    -108(%rbp), %rdi
	call    printStr
	movl    %eax, -116(%rbp)
	movq    -20(%rbp), %rax
	movl    (%rax), %eax
	movl    %eax, -120(%rbp)
	movl    -120(%rbp), %edi
	call    printInt
	movl    %eax, -124(%rbp)
	movq    $.LC5, -132(%rbp)
	movq    -132(%rbp), %rdi
	call    printStr
	movl    %eax, -136(%rbp)
	movl    -8(%rbp), %edi
	call    printInt
	movl    %eax, -140(%rbp)
	movl    $2, -144(%rbp)
	movl    -8(%rbp), %eax
	cdq     
	idivl   -144(%rbp)
	movl    %eax, -148(%rbp)
	movl    -148(%rbp), %eax
	movl    %eax, -8(%rbp)
	movl    $2, -152(%rbp)
	movl    -8(%rbp), %eax
	imull   -152(%rbp), %eax
	movl    %eax, -156(%rbp)
	movl    -156(%rbp), %eax
	movl    %eax, -8(%rbp)
	movl    -8(%rbp), %eax
	addl    -8(%rbp), %eax
	movl    %eax, -164(%rbp)
	movl    -164(%rbp), %eax
	movl    %eax, -12(%rbp)
	movl    -8(%rbp), %eax
	cdq     
	idivl   -8(%rbp)
	movl    %edx, -168(%rbp)
	movl    -168(%rbp), %eax
	movl    %eax, -12(%rbp)
	movl    $0, -172(%rbp)
	movl    -172(%rbp), %eax
.LFE0:
	movq    %rbp, %rsp
	popq    %rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
	.size   main, .-main
