/*
  ===============================================================================================
  Name : 14.c
  Author : Vishnu Dholu
  Description : 14 Write a program to find the type of a file.
                    a. Input should be taken from command line.
                    b. program should be able to identify any type of a file.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    struct stat fileStat;

    if(stat(argv[1], &fileStat) < 0){
        perror("stat");
        exit(1);
    }

    if(S_ISREG(fileStat.st_mode)){
        printf("%s is a regular file.\n", argv[1]);
    }
    else if(S_ISDIR(fileStat.st_mode)){
        printf("%s is a directory.\n", argv[1]);
    }
    else if(S_ISCHR(fileStat.st_mode)){
        printf("%s is a character device.\n", argv[1]);
    }
    else if(S_ISBLK(fileStat.st_mode)){
        printf("%s is a block device.\n", argv[1]);
    }
    else if(S_ISFIFO(fileStat.st_mode)){
        printf("%s is a FIFO (named pipe).\n", argv[1]);
    }
    else if(S_ISLNK(fileStat.st_mode)){
        printf("%s is a symbolic link.\n", argv[1]);
    }
    else if(S_ISSOCK(fileStat.st_mode)){
        printf("%s is a socket.\n", argv[1]);
    }
    else{
        printf("%s is a unknown type.\n", argv[1]);
    }

    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_14$ gcc 14.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_14$ ./a.out 14.c 
14.c is a regular file.
*/

// stat() system call
// -> it fills a struct stat with file info
// st_mode - contains encoded file type + permissions.
// Macros like S_ISREG(), S_ISDIR() help check the type.