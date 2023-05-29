.globl vectorMul
vectorMul:
    pushl %ebp
    movl %esp, %ebp        
    pushl %ebx
    pushl %ecx
    pushl %edx
    pushl %edi
    pushl %esi
    movl 8(%ebp), %ecx   #pierwsza  
    movl 12(%ebp), %ebx   #druga
    movl 16(%ebp), %edx    # trzecia
    movl 20(%ebp), %edi     #rozmiar pierwsze
    movl 24(%ebp), %ebp #petla
    
    movl %edi, %esi         
    add %ebp, %esi
    dec %edi                
    movb (%ebx), %bl        

mul:
    movb (%ecx, %edi), %al	
    mulb %bl               
    clc
    adcb %al, (%edx, %esi)	
    dec %esi
    adcb %ah, (%edx, %esi)	
    jnc carry

carry:
    movl %edi, %esi        
    add %ebp, %esi
    dec %edi             
    jns mul

    popl %esi
    popl %edi
    popl %edx
    popl %ecx
    popl %ebx
    popl %ebp
ret
