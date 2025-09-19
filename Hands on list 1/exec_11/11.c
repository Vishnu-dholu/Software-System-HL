/*
  ===============================================================================================
  Name : 11.c
  Author : Vishnu Dholu
  Description : 11. Write a program to open a file, duplicate the file descriptor and append the file with both the
                    descriptors and check whether the file is updated properly or not.
                    a. use dup
                    b. use dup2
                    c. use fcntl
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>     // for dup, dup2, write, close
#include <fcntl.h>      // for open, fcntl

int main() {
    int fd1, fd2, fd3;

    // open a file
    fd1 = open("test.txt", O_RDWR | O_CREAT | O_APPEND, 0644);

    // a) using dup
    fd2 = dup(fd1);
    write(fd1, "Hello from fd1\n", 15);
    write(fd2, "Hello from fd2\n", 15);

    // b) using dup2
    fd3 = dup2(fd1, 10);   // duplicate fd1 into descriptor 10
    write(fd3, "Hello from fd3 (dup2)\n", 22);

    // c) using fcntl
    int fd4 = fcntl(fd1, F_DUPFD, 0);  // duplicate fd1
    write(fd4, "Hello from fd4 (fcntl)\n", 23);

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);

    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_11$ gcc 11.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_11$ ./a.out 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_11$ cat test.txt 
Hello from fd1
Hello from fd2
Hello from fd3 (dup2)
Hello from fd4 (fcntl)
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_11$ 
*/