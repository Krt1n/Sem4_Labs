/* Q2: Producer - Write 4 integers to FIFO */

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd, arr[4];
    mkfifo("myfifo", 0666);

    printf("Enter 4 integers: ");
    for(int i=0; i<4; i++) scanf("%d", &arr[i]);

    fd = open("myfifo", O_WRONLY);
    write(fd, arr, sizeof(int) * 4); 
    close(fd);

    return 0;
}
