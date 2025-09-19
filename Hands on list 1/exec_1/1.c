 /*
  ===============================================================================================
  Name : 1.c
  Author : Vishnu Dholu
  Description : 1. Create the following types of a files using (i) shell command (ii) system call
                    a. soft link (symlink system call)
                    b. hard link (link system call)
                    c. FIFO (mkfifo Library Function or mknod system call)
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>     // for link(), symlink(), unlink()
#include <sys/stat.h>   // for mkfifo()
#include <sys/types.h>

int main() {
    // a) Soft link
    symlink("file.txt", "softlink.txt");

    // b) Hard link
    link("file.txt", "hardlink.txt");

    // c) FIFO
    mkfifo("myfifo", 0644);

    printf("Soft link, Hard link and FIFO created.\n");

    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_1$ echo "hello" > file.txt
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_1$ gcc 1.c -o links
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_1$ ./links 
Soft link, Hard link and FIFO created.
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_1$ ls -l
total 28
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu   968 Sep  7 11:26 1.c
-rw-rw-r-- 2 vishnu-dholu vishnu-dholu     6 Sep  7 11:28 file.txt
-rw-rw-r-- 2 vishnu-dholu vishnu-dholu     6 Sep  7 11:28 hardlink.txt
-rwxrwxr-x 1 vishnu-dholu vishnu-dholu 16136 Sep  7 11:28 links
prw-r--r-- 1 vishnu-dholu vishnu-dholu     0 Sep  7 11:28 myfifo
lrwxrwxrwx 1 vishnu-dholu vishnu-dholu     8 Sep  7 11:28 softlink.txt -> file.txt
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_1$ 

*/