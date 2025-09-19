 /*
  ===============================================================================================
  Name : 7.c
  Author : Vishnu Dholu
  Description : 7. Write a program to copy file1 into file2 ($cp file1 file2).
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int fd1;
    int fd2;
    int buff[1024];

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_WRONLY, 0777);

    int cnt;
    while((cnt = read(fd1, buff, 1024)) > 0){
        write(fd2, buff, cnt);
    }

    close(fd1);
    close(fd2);
    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_7$ gcc 7.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_7$ ./a.out 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_7$ cat file1.txt 
This line is from file1.txt.
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_7$ cat file2.txt 
This line is from file1.txt.
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_7$ 
*/