/*
  ===============================================================================================
  Name : 23.c
  Author : Vishnu Dholu
  Description : 23. Write a program to create a Zombie state of the running program.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){
    if(!fork()){
        printf("child process: pid=%d \t ppid=%d", getpid(), getppid());
    }
    else{
        sleep(2500);
    }
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_23$ gcc 23.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_23$ ./a.out 
child process: pid=184082 	 ppid=184081

PID         S
184082      Z
*/