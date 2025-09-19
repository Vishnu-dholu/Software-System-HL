/*
  ===============================================================================================
  Name : 21.c
  Author : Vishnu Dholu
  Description : 21. Write a program, call fork and print the parent and child process id.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    if(!fork()){
        printf("Child process PID: %d and Parent process PID: %d\n", getpid(), getppid());
    }
    else{
        printf("Parent process PID: %d\n", getpid());
    }
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_21$ gcc 21.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_21$ ./a.out 
Parent process PID: 180035
Child process PID: 180036 and Parent process PID: 180035
*/