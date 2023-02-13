/* Implementation of how lseek() system call is used */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd;
    off_t offset;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    offset = lseek(fd, 0, SEEK_END);
    if (offset == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }
    
    printf("Size of %s: %ld bytes\n", argv[1], offset);
    
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}
