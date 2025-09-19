#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Running ./myprog with argument 'Vishnu'...\n");

    execlp("./myprog", "./myprog", "Vishnu", NULL);

    return 1;
}