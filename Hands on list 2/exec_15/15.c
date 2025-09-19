/*
========================================================================================================================================================================================
Name : 15.c      
Author : Vishnu Dholu
Description : 15. Write a simple program to send some data from parent to the child process. 
              
Date : 11th sept, 2025
========================================================================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);

    char buff[50];

    if(!fork()){
        close(fd[1]);
        read(fd[0], buff, 20);
        printf("%s", buff);
    }
    else{
        close(fd[0]);
        write(fd[1], "This is from parent\n", 20);
        wait(0);
    }

    return 0;
}


/*
OUTPUT:
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 2/exec_15$ gcc 15.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 2/exec_15$ ./a.out 
This is from parent

*/