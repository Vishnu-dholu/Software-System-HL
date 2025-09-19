 /*
  ===============================================================================================
  Name : 2.c
  Author : Vishnu Dholu
  Description : 2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
				   identify all the process related information in the corresponding proc directory.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <stdio.h>

void main (){
	for(;;);
}

/*
OUTPUT
vishnu-dholu@omen:/proc$ cd 118238/
vishnu-dholu@omen:/proc/118238$ cd fd
vishnu-dholu@omen:/proc/118238/fd$ ls
0  1  2
vishnu-dholu@omen:/proc/118238/fd$
*/