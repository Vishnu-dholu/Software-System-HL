/*
  ===============================================================================================
  Name : db.c
  Author : Vishnu Dholu
  Description : 18. Write a program to perform Record locking.
                    a. Implement write lock
                    b. Implement read lock
                    Create three records in a file. Whenever you access a particular record, first lock it then modify/access
                    to avoid race condition.
  Date:  SEPT 7th, 2025.
  ===============================================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int i, fd;
    struct {
        int train_num;
        int ticket_count;
    } db[3];

    for(i=0; i<3; i++){
        db[i].train_num = i + 1;
        db[i].ticket_count = 0;
    }

    fd = open("record.txt", O_RDWR);
    write(fd, db, sizeof(db));

    close(fd);
    return 0;
}