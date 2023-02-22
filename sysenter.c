#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>

extern long my_syscall(const char *buf, size_t len);

int main(int argc, char *argv[])
{
    char buf[256] = {0};
    int ret;

    printf("Enter a string: ");
    fgets(buf, 256, stdin);

    ret = my_syscall(buf, strlen(buf));
    printf("System call returned: %d\n", ret);

    return 0;
}
