.globl vectorSub
vectorSub:
  pushl %ebp
  movl %esp, %ebp
  pushl %ecx
  pushl %edx
  pushl %edi      
  movl 8(%ebp), %ecx      
  movl 12(%ebp), %edx    
  movl 16(%ebp), %edi  
  clc        
vector_sub:
  movb (%edx,%edi), %al   
  sbb %al, (%ecx,%edi)    
  decl %edi
  jns vector_sub               
  jnc end
borrow:
  dec %ecx
  decb (%ecx)
  je borrow  
end:
  popl %edi
  popl %edx
  popl %ecx
  popl %ebp
  ret
  