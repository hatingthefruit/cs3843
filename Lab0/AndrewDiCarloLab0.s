	.file	"AndrewDiCarloLab0.c"
	.text
.globl sum
	.type	sum, @function
sum:
	pushl	%ebp    #push current base pointer onto stack
	movl	%esp, %ebp  #move current stack pointer to %ebp to use as base frame 
	movl	12(%ebp), %eax  #Move the long at 12 offset from where %ebp points to %eax
	addl	8(%ebp), %eax   #Add the long at 8 offset from where %ebp points to %eax
	popl	%ebp    #Set pointer to calling function as base pointer
	ret         #Return to calling function; return value is stored in %eax
	.size	sum, .-sum
	.ident	"GCC: (Ubuntu 4.3.3-5ubuntu4) 4.3.3"
	.section	.note.GNU-stack,"",@progbits
