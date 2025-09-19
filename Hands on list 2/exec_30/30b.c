/*
========================================================================================================================================================================================
Name : 16.c      
Author : Vishnu Dholu
Description : 30. Write a program to create a shared memory.
                b. attach with O_RDONLY and check whether you are able to overwrite.
              
Date : 11th sept, 2025
========================================================================================================================================================================================
*/


#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int key, shmid;
    char *data;

    key = ftok(".", 'b');
    shmid = shmget(key, 1024, 0);
    data = shmat(shmid, 0, 0);
    printf("Text from shared memory: %s\n", data);
}