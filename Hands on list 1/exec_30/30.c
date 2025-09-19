/*
  ===============================================================================================
  Name : 30.c
  Author : Vishnu Dholu
  Description : 30. Write a program to run a script at a specific time using a Daemon process.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main(){
    pid_t pid = fork();

    if(pid > 0){
        printf("Parent: Child created with PID %d\n", pid);
        exit(EXIT_SUCCESS);
    }
    else{
        printf("Child: Running as daemon (PID %d)\n", getpid());

        while (1){
            time_t cur_time = time(NULL);
            struct tm *t = localtime(&cur_time);

            if(t->tm_hour == 12 && t->tm_min == 40){
                printf("Child: OPEN DAEMON PROCESS...\n");
                system("./file.sh");
                break;
            }
            sleep(30);
        }
    }
    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_30$ gcc 30.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_30$ ./a.out 
Parent: Child created with PID 199496
Child: Running as daemon (PID 199496)
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_30$ Child: OPEN DAEMON PROCESS...
I AM VISHNU, HOW ARE YOU ???:
SEE U NEXT TIME!!

*/