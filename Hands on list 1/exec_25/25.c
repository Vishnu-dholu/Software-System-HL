/*
  ===============================================================================================
  Name : 25.c
  Author : Vishnu Dholu
  Description : 25. Write a program to create three child processes. The parent should wait for a particular child (use
                    waitpid system call).
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t i, j, k;
    int status;

    if((i=fork()) == 0){
        // Child 1
        printf("Child1 (PID=%d) running...\n", getpid());
        sleep(1);
        printf("Child1 exiting.\n");
        return 0;
    }
    else{
        if((j=fork()) == 0){
            // Child 2
            printf("Child2 (PID=%d) running...\n", getpid());
            sleep(3);
            printf("Child2 exiting.\n");
            return 0;
        }
        else{
            if((k=fork()) == 0){
                // Child 3
                printf("Child3 (PID=%d) running...\n", getpid());
                sleep(10);
                printf("Child3 exiting.\n");
                return 0;
            }
            else{
                printf("Parent (PID=%d) waiting for Child3 (PID=%d)...\n", getpid(), k);
                pid_t waited = waitpid(k, &status, 0);
                printf("Parent: Child3 (PID=%d) finished.\n", waited);
            }
        }       
    }
    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_25$ gcc 25.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_25$ ./a.out 
Child1 (PID=189745) running...
Child2 (PID=189746) running...
Parent (PID=189744) waiting for Child3 (PID=189747)...
Child3 (PID=189747) running...
Child1 exiting.
Child2 exiting.
Child3 exiting.
Parent: Child3 (PID=189747) finished.
*/