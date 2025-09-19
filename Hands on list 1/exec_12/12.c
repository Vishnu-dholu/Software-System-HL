/*
  ===============================================================================================
  Name : 12.c
  Author : Vishnu Dholu
  Description : 12. Write a program to find out the opening mode of a file. Use fcntl.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd, flags;

    fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, 0644);

    // Get the file status flags
    flags = fcntl(fd, F_GETFL);

    // Check access mode
    switch(flags & O_ACCMODE) {
        case O_RDONLY:
            printf("File opened in: READ ONLY mode\n");
            break;
        case O_WRONLY:
            printf("File opened in: WRITE ONLY mode\n");
            break;
        case O_RDWR:
            printf("File opened in: READ and WRITE mode\n");
            break;
    }
    close(fd);
    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_12$ gcc 12.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_12$ ./a.out 
File opened in: READ and WRITE mode
 */