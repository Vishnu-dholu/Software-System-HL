/*
  ===============================================================================================
  Name : 28.c
  Author : Vishnu Dholu
  Description : 28. Write a program to get maximum and minimum real time priority.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>
#include <sched.h>  // provides functions and constants for CPU scheduling

int main(){
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);
    min_priority = sched_get_priority_min(SCHED_FIFO);

    printf("SCHED_FIFO policy:\n");
    printf(" Maximum Priority: %d\n", max_priority);
    printf(" Minimum Priority: %d\n", min_priority);

    return 0;
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_28$ gcc 28.c 
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_28$ ./a.out 
SCHED_FIFO policy:
 Maximum Priority: 99
 Minimum Priority: 1
*/

// sched_get_priority_max(SCHED_FIFO) -> queries the maximum priority value the system allows for the 
//                                       SCHED_FIFO scheduling.
// sched_get_priority_min(SCHED_FIFO) -> queries the minimum priority value the system allows for the 
//                                       SCHED_FIFO scheduling.
// SCHED_FIFO -> is a real-time scheduling policy in Linux.