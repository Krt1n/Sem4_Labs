/* Q4: Reader - Read words, detach, and delete Shared Memory */
#include <stdio.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid, (void*)0, 0);

    printf("Consumer read: %s", str);

    shmdt(str); // Detach
    shmctl(shmid, IPC_RMID, NULL); // Delete
    printf("Shared memory deleted.\n");

    return 0;
}