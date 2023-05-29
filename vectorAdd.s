.globl vectorAdd
vectorAdd:
  pushl %ebp
  movl %esp, %ebp
  pushl %edi
  clc
  movl 8(%ebp), %ecx      
  movl 12(%ebp), %ebx     
  movl 16(%ebp), %edi                   
vector_add:
  movb (%ebx,%edi), %al  
  adc %al, (%ecx,%edi)   
  decl %edi
  jns vector_add               
  jnc end
carry:
  dec %ecx
  incb (%ecx)
  je carry  
end:
  popl %edi
  popl %ebp
  ret
  