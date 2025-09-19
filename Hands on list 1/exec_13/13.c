/*
  ===============================================================================================
  Name : 13.c
  Author : Vishnu Dholu
  Description : 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
                    verify whether the data is available within 10 seconds or not (check in $man 2 select).
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

int main(){
    fd_set readfds;
    struct timeval timeout;
    int ret;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;

    printf("Waiting for input for 10 seconds...\n");
    printf("Type something and press Enter, or wait for timeout.\n");

    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if(ret == 0) printf("\n");

    if(FD_ISSET(STDIN_FILENO, &readfds)){
        char buffer[100];
        int n = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        if(n > 0){
            buffer[n] = '\0';
            printf("You typed -> %s\n", buffer);
        }
    }
    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_13$ gcc 13.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_13$ ./a.out 
Waiting for input for 10 seconds...
Type something and press Enter, or wait for timeout.
vishnu dholu
You typed -> vishnu dholu

*/

// fd_set:
// -> used to store a list of descriptors that we want select() to watch.
// -> here we watch only STD_FILENO (fd=0 -> keyboard input).

// FD_ZERO() and FD_SET():
// -> FD_ZERO(&readfds) clears the set.
// -> FD_SET(STDIN_FILENO, &readfds) adds standard input to the set.

// FD_ISSET(STDIN_FILENO, &readfds)
// -> checks if stdin became ready for reading.