#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execve("/bin/ls", argv, NULL);
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}
