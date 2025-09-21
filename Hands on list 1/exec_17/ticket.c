#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    struct flock lock;
    int fd;

    struct {
        int ticket_no;
    } db;

    fd = open("db", O_RDWR);

    // Initialize lock
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Before entering into critical section");
    fcntl(fd, F_SETLKW, &lock);     // acquire lock
    printf("Inside the critical section\n");

    // Read after acquiring lock, so that no inconsistencies happen
    read(fd, &db, sizeof(db));
    printf("Current ticket number: %d\n", db.ticket_no);
    db.ticket_no++;;        // actually incrementing the ticket number

    // Because of initial read, fd is now pointing to the end of the file,so we have to reposition to the beginning of the file
    lseek(fd, 0, SEEK_SET);
    write(fd, &db, sizeof(db));

    // This is just the demonstrate that locking actually works
    printf("Press enter to unlock\n");
    getchar();

    // Unlock the file
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);      //Release lock
    printf("Exited critical section\n");

    close(fd);
    return 0;
}

// whence -> It tells the system the reference point for start(the offset).