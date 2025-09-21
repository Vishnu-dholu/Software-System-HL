/*
  ===============================================================================================
  Name : 26a.c
  Author : Vishnu Dholu
  Description : 26. Write a program to execute an executable program.
                    a. use some executable program
                    b. pass some input to an executable program. (for example execute an executable of $./a.out name)
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Running ls -l using execlp...\n");

    execlp("ls", "ls", "-l", NULL);

    return 1;
}

/*
OUTPUT

vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_26$ gcc 26a.c -o output_a
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_26$ ./output_a 
Running ls -l using execlp...
total 28
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu  1330 Sep  7 12:34 26a.c
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu   181 Sep  1 18:33 launcher.c
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu   135 Sep  1 18:35 myprog.c
-rwxrwxr-x 1 vishnu-dholu vishnu-dholu 16072 Sep 20 18:54 output_a
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_26$ 
*/