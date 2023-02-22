.global my_syscall
my_syscall:
    movl %edi, %eax
    movl %esi, %ebx
    movl %edx, %ecx
    movl %ecx, %edx
    sysenter
    ret
