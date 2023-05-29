.globl vectorMul
vectorMul:
    pushl %ebp
    movl %esp, %ebp        
    pushl %ebx
    pushl %edi
    pushl %esi
    clc
    movl 8(%ebp), %ebx   #pierwsza  
    movl 12(%ebp), %ecx   #druga
    movl 16(%ebp), %edx    # trzecia
    movl 20(%ebp), %edi     #rozmiar pierwsze
    movl 24(%ebp), %ebp #petla

    movl %edi, %esi
    add %ebp, %esi
    movb (%ecx), %cl
    
    mul:
    movb (%ebx, %edi), %al
    mulb %cl
    clc 
    adcb %al, (%edx, %esi)
    dec %esi
    adcb %ah, (%edx, %esi)
    dec %edi               
    jns mul

    popl %esi
    popl %edi
    popl %ebx
    popl %ebp
ret

