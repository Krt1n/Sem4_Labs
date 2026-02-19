#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    system("date");
    pid_t pid = fork();

    if(pid == 0)
    {
        printf("Child exiting...\n");
        exit(0);
    }
    else
    {
        printf("Parent sleeping...\n");
        sleep(30);   // gives time to check zombie
    }

    return 0;
}
