/*
========================================================================================================================================================================================
Name : 16.c      
Author : Vishnu Dholu
Description : 16. Write a program to send and receive data from parent to child vice versa. Use two way
                communication. 
              
Date : 11th sept, 2025
========================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    int parent_fd[2], child_fd[2];
    pipe(parent_fd);
    pipe(child_fd);

    int child = fork();
    
    if(child == 0){
        printf("%d : I am the child\n", getpid());

        close(child_fd[0]);
        close(parent_fd[1]);

        char fromParent[200];

        int n = read(parent_fd[0], fromParent, sizeof(fromParent) - 1);
        strcat(fromParent, " (added this.)");
        
        write(child_fd[1], fromParent, strlen(fromParent));
        close(child_fd[1]);
        printf("%d: Child: writing to pipe - '%s' \n", (int)getpid(), fromParent);
    }
    else{
        printf("%d : I am the parent\n", getpid());

        close(child_fd[1]);
        close(parent_fd[0]);

        char fromChild[200];

        int n = read(child_fd[0], fromChild, sizeof(fromChild) - 1);
        strcat(fromChild, " (added this.)");
        
        write(parent_fd[1], fromChild, strlen(fromChild));
        close(parent_fd[1]);
        printf("%d: Parent: writing to pipe - '%s' \n", (int)getpid(), fromChild);
    }

    return 0;
}