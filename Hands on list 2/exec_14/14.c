#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];
    char buf[7];
    pipe(fd);

    write(fd[1], "hello\n", 7);
    read(fd[0], buf, sizeof(buf));
    printf("Read from Pipe: %s\n", buf);
    
}