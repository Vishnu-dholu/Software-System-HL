 /*
  ===============================================================================================
  Name : 3.c
  Author : Vishnu Dholu
  Description : 3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int fd1 = creat("newFile1.txt", 0644);
	printf("Value of file descriptor is %d ", fd1);
	printf("\n");
	close(fd1);

	return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_3$ gcc 3.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_3$ ./a.out 
Value of file descriptor is 3 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_3$ ls -l
total 20
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu  1392 Sep  7 11:37 3.c
-rwxrwxr-x 1 vishnu-dholu vishnu-dholu 16160 Sep  7 11:38 a.out
-rw-r--r-- 1 vishnu-dholu vishnu-dholu     0 Sep  7 11:38 newFile1.txt
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_3$ 

*/

// creat is particularly connected to linux os. 
// It cannot be used in other os.

// what is fd(file descriptor)?
// -> In simple words, when a process opens a file, the OS creates an entry in the kernel to keep track of that opened
//    file (like which file it is, current read/write position, access mode, etc.). Each such entry is given a small integer
// 	  number called a file descriptor (FD).
// -> So a file descriptor is just an integer that uniquely represents an opened file for that process.
// -> By default:
//		~ 0 -> standard input (stdin)
//		~ 1 -> standard output (stdout)
//		~ 2 -> standard error (stderr)

// How creat works?
// -> Whenever we call a system call, there will be a return value. That value is used to track that the operation has happened
//    succesfully or not.