 /*
  ===============================================================================================
  Name : 9.c
  Author : Vishnu Dholu
  Description : 9. Write a program to print the following information about a given file.
                    a. inode
                    b. number of hard links
                    c. uid
                    d. gid
                    e. size
                    f. block size
                    g. number of blocks
                    h. time of last access
                    i. time of last modification
                    j. time of last change
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>      // for printf, perror
#include <stdlib.h>     // for exit codes, general utilities
#include <sys/stat.h>   // for struct stat and stat() function
#include <unistd.h>     // for POSIX functions (needed on UNIX-like systems)
#include <time.h>       // for ctime() to convert timestamps

int main(int argc, char *argv[]){       // argc - argument count,  argv - argument vector(array of strings with command-line arguments)
    
    struct stat fileStat;

    if(stat(argv[1], &fileStat) < 0){
        perror("stat");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("Inode: %lu\n", (unsigned long)fileStat.st_ino);
    printf("Number of hard links: %lu\n", (unsigned long)fileStat.st_nlink);
    printf("UID: %u\n", fileStat.st_uid);
    printf("GID: %u\n", fileStat.st_gid);
    printf("Size: %ld bytes\n", (long)fileStat.st_size);
    printf("Block size: %ld\n", (long)fileStat.st_blksize);
    printf("Number of blocks: %ld\n", (long)fileStat.st_blocks);

    printf("Last access: %s", ctime(&fileStat.st_atime));
    printf("Last modification: %s", ctime(&fileStat.st_mtime));
    printf("Last change: %s\n", ctime(&fileStat.st_ctime));

    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_9$ gcc 9.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_9$ ./a.out myfile.txt 
File: myfile.txt
Inode: 2887233
Number of hard links: 1
UID: 1000
GID: 1000
Size: 278 bytes
Block size: 4096
Number of blocks: 8
Last access: Sun Sep  7 11:55:03 2025
Last modification: Wed Aug 20 21:29:34 2025
Last change: Wed Aug 20 21:29:34 2025
*/

// stat(filename, &fileStat) -> fills the fileStat structure with informaiton about the file.
// st_ino = inode number(unique identifier for a file in the filesystem)
// st_nlink = how many directory entires point to this inode.
//          -> 1 for regular files.
//          -> 2 or more for directories.
// st_uid = numeric User ID of the file's owner.
//          -> 1000 = your Linux user.
//          -> 0 = root.
// st_gid = numeric Group ID of the file's group.
// st_size = size of the file in bytes
// st_blksize = preferred block size for I/O operations.(Commonly 4096 bytes on linux)
// st_blocks = actual number of disk blocks allocated (each usually 512 bytes).
// st_atime = last access time (read).
// st_mtime = last modification time (write/append).
// st_ctime = last status change (permissions, ownership,etc.).
// ctime() -> converts the raw timestamps into a human-readable string.