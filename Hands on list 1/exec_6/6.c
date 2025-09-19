 /*
  ===============================================================================================
  Name : 6.c
  Author : Vishnu Dholu
  Description : 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){
    char buffer[1024];      // temporary storage for input
    int count = read(0, buffer, 1024);
    printf("Entered text: \n");
    write(1, buffer, count);
    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_6$ gcc 6.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_6$ ./a.out 
this is input
Entered text: 
this is input
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_6$ 

*/

// read() System call:
// -> ssize_t read(int fd, void *buf, size_t count);
// -> fd = file descriptor
// -> buf = pointer to memory (where the data will be stored).
// -> count = maximum number of bytes to read.
// Return value:
// -> >0 = number of bytes actually read.
// -> 0 = end of file.
// -> -1 = error.

// write() System call:
// -> ssize_t write(int fd, const void *buf, size_t count);
// -> fd = file descriptor
// -> buf = pointer to memory (where the data is stored to send).
// -> count = number of bytes to write.
// Return value:
// -> >=0 = number of bytes actually written.
// -> -1 = error.