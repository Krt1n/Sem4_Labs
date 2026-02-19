/* Q4: Writer - Write words into Shared Memory */
#include <stdio.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid, (void*)0, 0);

    printf("Enter words: ");
    fgets(str, 100, stdin);

    printf("Data written: %s", str);
    shmdt(str);
    return 0;
}