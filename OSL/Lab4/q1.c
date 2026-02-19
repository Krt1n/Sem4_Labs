#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    system("date");
    pid_t pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    else if(pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
        printf("Child Parent PID: %d\n", getppid());
        exit(0);
    }
    else
    {
        wait(NULL);  
        printf("\nParent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Parent Parent PID: %d\n", getppid());
    }
    return 0;
}
