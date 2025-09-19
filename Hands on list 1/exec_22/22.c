/*
  ===============================================================================================
  Name : 22.c
  Author : Vishnu Dholu
  Description : 22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
                    parent processes. Check output of the file.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>      // for printf, sprintf
#include <string.h>     // for strlen
#include <fcntl.h>      // for open() and file control flags
#include <unistd.h>     // for fork(), getpid(), getppid(), write(), close()

int main(){
    char buffer1[250];
    char buffer2[250];
    int fd;
    fd = open("file.txt", O_RDWR | O_CREAT, 0644);

    if(!fork()){
        // Child process
        sprintf(buffer1, "Child process: pid=%d\tppid=%d\n", getpid(), getppid());
        write(fd, buffer1, strlen(buffer1));
        close(fd);
    }
    else{
        // Parent process
        sprintf(buffer2, "Parent process: pid=%d\n", getpid());
        write(fd, buffer2, strlen(buffer2));
        close(fd);
    }
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_22$ gcc 22.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_22$ ./a.out 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_22$ cat file.txt 
Parent process: pid=182845
Child process: pid=182846	ppid=182845
*/

// fork() - creates a new proces (child).
// -> In child process, fork() returns 0
// -> In parent process, fork() returns the child's PID
// sprintf - formats the message into buffer.