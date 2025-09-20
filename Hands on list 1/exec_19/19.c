/*
  ===============================================================================================
  Name : 19.c
  Author : Vishnu Dholu
  Description : 19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

// read time stamp counter
unsigned long long rdtsc () {
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
}

int main(){
    int i, nano;
    unsigned long long int start, end;
    start = rdtsc();
    for(int i=0; i<1; i++){
        getppid();
    }
    end = rdtsc();
    nano = (end - start)/2.60;
    printf("The function takes %d nano sec\n", nano);
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_19$ gcc 19.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_19$ ./a.out 
The function takes 8841 nano sec
*/