 /*
  ===============================================================================================
  Name : 5.c
  Author : Vishnu Dholu
  Description : 5. Write a program to create five new files with infinite loop. Execute the program in the background
					and check the file descriptor table at /proc/pid/fd.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd1 = creat("file1.txt", 0644);
	int fd2 = creat("file2.txt", 0644);
	int fd3 = creat("file3.txt", 0644);
	int fd4 = creat("file4.txt", 0644);
	int fd5 = creat("file5.txt", 0644);

	while(1){}

	return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_5$ gcc 5.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_5$ ./a.out &
[1] 132791
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_5$ ^C
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_5$ 

vishnu-dholu@omen:/proc/132791$ cd fd
vishnu-dholu@omen:/proc/132791/fd$ ls
0  1  2  3  4  5  6  7
vishnu-dholu@omen:/proc/132791/fd$
*/

// fcntl.h header file in the C programming language provides access to file control operations defined by the
// POSIX standard.