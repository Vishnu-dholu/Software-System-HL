/*
  ===============================================================================================
  Name : 20.c
  Author : Vishnu Dholu
  Description : 20. Find out the priority of your running program. Modify the priority with nice command.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
    int priority;

    priority = getpriority(PRIO_PROCESS, 0);
    printf("Current process (nice value): %d\n", priority);

    int new_priority = nice(5);
    printf("Current process updated priority value: %d\n", new_priority);

    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_20$ gcc 20.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_20$ ./a.out 
Current process (nice value): 0
Current process updated priority value: 5
*/


/*
Nice Value Range:
  20 → highest priority (more CPU time).
  0 → default.
  +19 → lowest priority (less CPU time).

lower value = higher priority.
*/