/*
  ===============================================================================================
  Name : 10.c
  Author : Vishnu Dholu
  Description : 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
                    bytes (use lseek) and write again 10 bytes.
                    a. check the return value of lseek
                    b. open the file with od and check the empty spaces in between the data.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>      // for printf
#include <fcntl.h>      // for open() and file control flags
#include <unistd.h>     // for write(), lseek(), close()
#include <stdlib.h>     // for exit()

int main(){
    int fd;     // file descriptor returned by open()
    char buf1[10] = "DHOLUVISHN";
    char buf2[10] = "VISHNDHOLU";

    fd = open("myfile.txt", O_RDWR | O_CREAT, 0644);

    write(fd, buf1, 10);

    off_t pos = lseek(fd, 10, SEEK_CUR);
    printf("lseek returned position: %ld\n", (long)pos);
    
    write(fd, buf1, 10);

    close(fd);
    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_10$ gcc 10.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_10$ ./a.out 
lseek returned position: 20
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_10$ od -c myfile.txt 
0000000   D   H   O   L   U   V   I   S   H   N  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   D   H   O   L   U   V   I   S   H   N
0000036
*/

// O_RDWR -> open for both read and write
// O_CREAT -> create the file if it doesn;t exist
// off_t lseek(int fd, off_t offset, int whence);
// off_t -> in C it is a signed integer type used to represented file sizes and offsets within files
// whence -> specifies the reference point from which the file offset is calculated.
// SEEK_CUR -> used to reposition the file offset relative to the current file position.

// Summary:
// 1. Creates/opens myfile.txt.
// 2. Writes 10 bytes "AAAAAAAAAA".
// 3. Skips 10 bytes.
// 4. Writes 10 more "AAAAAAAAAA".
// 5. close file.
