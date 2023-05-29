.globl vectorSub
vectorSub:
  pushl %ebp
  movl %esp, %ebp
  pushl %edi
  clc           
  movl 8(%ebp), %ecx      
  movl 12(%ebp), %edx    
  movl 16(%ebp), %edi  
       
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
  popl %ebp
  ret
  