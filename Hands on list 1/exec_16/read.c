/*
  ===============================================================================================
  Name : 15.c
  Author : Vishnu Dholu
  Description : 16. Write a program to perform mandatory locking.
                    a. Implement write lock
                    b. Implement read lock
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    struct flock lock;
    int fd;
    fd = open("file.txt", O_RDWR);
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Before entering into critical section\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside the critical section\n");
    printf("Press enter to unlock");
    // This makes the program wait till an input is received on STDIN and enter is pressed, so file remains 
    // locked, till that happens
    getchar();
    printf("File unlocked\n");
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("End\n");
}