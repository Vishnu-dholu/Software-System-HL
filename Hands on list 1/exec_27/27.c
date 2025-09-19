/*
  ===============================================================================================
  Name : 27.c
  Author : Vishnu Dholu
  Description : 27. Write a program to execute ls -Rl by the following system calls
                    a. execl
                    b. execlp
                    c. execle
                    d. execv
                    e. execvp
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
    char *envp[] = {NULL};

    // execl
    if (fork() == 0) {
        printf("\n--- Running with execl ---\n");
        execl("/bin/ls", "ls", "-Rl", NULL);
    }
    wait(NULL);

    // execlp
    if (fork() == 0) {
        printf("\n--- Running with execlp ---\n");
        execlp("ls", "ls", "-Rl", NULL);
    }
    wait(NULL);

    // execle
    if (fork() == 0) {
        printf("\n--- Running with execle ---\n");
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
    }
    wait(NULL);

    // execv
    if (fork() == 0) {
        printf("\n--- Running with execv ---\n");
        execv("/bin/ls", args);
    }
    wait(NULL);

    // execvp
    if (fork() == 0) {
        printf("\n--- Running with execvp ---\n");
        execvp("ls", args);
    }
    wait(NULL);

    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_27$ gcc 27.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_27$ ./a.out 

--- Running with execl ---
.:
total 20
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu  1425 Sep  7 14:37 27.c
-rwxrwxr-x 1 vishnu-dholu vishnu-dholu 16376 Sep  7 14:37 a.out

--- Running with execlp ---
.:
total 20
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu  1425 Sep  7 14:37 27.c
-rwxrwxr-x 1 vishnu-dholu vishnu-dholu 16376 Sep  7 14:37 a.out

--- Running with execle ---
.:
total 20
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu  1425 Sep  7 14:37 27.c
-rwxrwxr-x 1 vishnu-dholu vishnu-dholu 16376 Sep  7 14:37 a.out

--- Running with execv ---
.:
total 20
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu  1425 Sep  7 14:37 27.c
-rwxrwxr-x 1 vishnu-dholu vishnu-dholu 16376 Sep  7 14:37 a.out

--- Running with execvp ---
.:
total 20
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu  1425 Sep  7 14:37 27.c
-rwxrwxr-x 1 vishnu-dholu vishnu-dholu 16376 Sep  7 14:37 a.out
*/