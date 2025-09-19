/*
  ===============================================================================================
  Name : 29.c
  Author : Vishnu Dholu
  Description : 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
					SCHED_RR).
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include<sys/types.h>
#include<sched.h>
#include<stdio.h>
#include<unistd.h>

struct sched_param p;

int main(){
	p.sched_priority = 10;
	printf(" ret = %d\n", sched_setscheduler(0,SCHED_FIFO,&p));
	printf("\nThe scheduling policy is = %d\n",sched_getscheduler(getpid()));
	printf(" ret = %d\n",sched_setscheduler(0,SCHED_RR,&p));
	printf("\nThe scheduling policy is = %d\n",sched_getscheduler(getpid()));
}

/*
OUTPUT
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_29$ sudo ./a.out 
[sudo] password for vishnu-dholu: 
 ret = 0

The scheduling policy is = 1
 ret = 0

The scheduling policy is = 2
*/