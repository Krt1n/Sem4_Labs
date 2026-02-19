#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    system("date");
    pid_t pid = fork();
    if(pid == 0)
    {
        // child runs previous program
        execl("./q1", "q1", NULL);

        // runs only if exec fails
        perror("Exec failed");
        exit(1);
    }
    else
    {
        wait(NULL);
        printf("Parent finished\n");
    }

    return 0;
}
