 /*
  ===============================================================================================
  Name : 4.c
  Author : Vishnu Dholu
  Description : 4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <fcntl.h>	// for open() flags
#include <unistd.h>	// for close(), read(), write()

int main() {
	int fd;

	// Open file in read/write mode and Try to create file, but fail if is already exists.
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_EXCL, 0666);

	printf("File opened successfully with fd = %d\n", fd);

	close(fd);
	return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_4$ gcc 4.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_4$ ./a.out 
File opened successfully with fd = 3
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_4$ ls -l
total 20
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu   737 Sep  7 11:39 4.c
-rwxrwxr-x 1 vishnu-dholu vishnu-dholu 16112 Sep  7 11:40 a.out
-rw-rw-r-- 1 vishnu-dholu vishnu-dholu     0 Sep  7 11:41 testfile.txt
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_4$ 
*/