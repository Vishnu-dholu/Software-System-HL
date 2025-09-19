 /*
  ===============================================================================================
  Name : 8.c
  Author : Vishnu Dholu
  Description : 8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
                    Close the file when end of file is reached.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int fd;
    char ch;

    fd = open("file1.txt", O_RDONLY);
    
    while(read(fd, &ch, 1) == 1){
        write(STDOUT_FILENO, &ch, 1);
    }
    write(STDOUT_FILENO, "\n", 1);
    close(fd);

    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_8$ gcc 8.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_8$ ./a.out 
This is inside the file.
Good work.
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_8$ 
*/

// write () System call:
// ssize_t write(int fd, const void *buf, size_t count);
// -> fd(file descriptor) - An integer that represents the file you want to write to.
// -> buf(buffer) - Pointer to memory that holds the data you want to write.
// -> count - Number of bytes you want to write from the buffer.

// open () System call:
// ssize_t open(const char *pathname, int flags, mode_t mode);
// -> pathname - the name of the file you want to open
// -> flags - How you want to open the file.
// -> mode - File permission bits.