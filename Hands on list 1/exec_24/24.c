/*
  ===============================================================================================
  Name : 24.c
  Author : Vishnu Dholu
  Description : 24. Write a program to create an orphan process.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pid = fork();

    if(pid > 0){
        printf("parent process: (PID: %d) is exiting...\n", getpid());
        exit(0);
    }
    else if(pid == 0){
        sleep(15);
        printf("child process: (PID: %d) became orphan, new parent PID: %d\n", getpid(), getppid());
        exit(0);
    }
    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_24$ gcc 24.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_24$ ./a.out 
parent process: (PID: 188513) is exiting...

*/


// Zombie → Parent is alive but didn’t collect child’s exit status.
// Orphan → Parent is dead, child is still running.