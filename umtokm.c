#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {
    char message[] = "Hello, kernel mode!\n";

    // Use the int 0x80 instruction to make a system call to write()
    // The write() system call writes the message to the console
    __asm__("int $0x80" : : "a" (__NR_write), "b" (STDOUT_FILENO), "c" (message), "d" (sizeof(message)));

    return 0;
}
