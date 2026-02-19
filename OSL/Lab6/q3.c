/* Q3: Parent-Child communication using Shared Memory */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
    int shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid, (void*)0, 0);

    if (fork() == 0) { // Child
        sleep(2); // Wait for parent to write
        printf("Child read: %c\n", str[0]);
        str[0] = str[0] + 1; // Increment alphabet
        shmdt(str);
        exit(0);
    } else { // Parent
        printf("Parent: Enter an alphabet: ");
        scanf(" %c", &str[0]);
        
        wait(NULL); // Wait for child to respond
        printf("Parent: Child replied with: %c\n", str[0]);
        
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}