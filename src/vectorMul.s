.globl vectorMul
vectorMul:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebx
    pushl %ecx
    pushl %edx
    pushl %edi
    pushl %esi
    movl 8(%ebp), %ecx   
    movl 12(%ebp), %ebx  
    movl 16(%ebp), %edx    
    movl 20(%ebp), %edi     
    movl 24(%ebp), %esi 

    movl %edi, %ebp
    add %esi, %ebp
    dec %edi
    movb (%ebx), %bl

mul:
    movb (%ecx, %edi), %al
    mulb %bl
    clc
    adcb %al, (%edx, %ebp)
    dec %ebp
    adcb %ah, (%edx, %ebp)
    jnc noCarry

carry:
    dec %ebp 
    incb (%edx, %ebp)
    je carry

index:
    movl %edi, %ebp
    add %esi, %ebp
    dec %edi
    jns mul

noCarry:
    dec %edi
    jns mul

    popl %esi
    popl %edi
    popl %edx
    popl %ecx
    popl %ebx
    popl %ebp
ret
