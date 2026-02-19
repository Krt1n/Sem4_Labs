/* Q2: Consumer - Read 4 integers from FIFO */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, arr[4];

    fd = open("myfifo", O_RDONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        return 1;
    }

    read(fd, arr, sizeof(int) * 4);

    printf("Consumer received: ");
    for(int i=0; i<4; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    close(fd);
    return 0;
}