#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc > 1){
        printf("Hello, %s!\n", argv[1]);
    }

    return 0;
}


/*
OUTPUT

vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_26$ gcc myprog.c -o myprog
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_26$ gcc launcher.c -o launcher
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_26$ ./myprog Vishnu
Hello, Vishnu!
vishnu-dholu@omen:~/iiitb/sys_software/lab/Hands on list 1/exec_26$ 

*/