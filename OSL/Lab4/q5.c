#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int fib[100];
int n;

void* generate(void* arg)
{
    fib[0]=0;
    fib[1]=1;

    for(int i=2;i<n;i++)
        fib[i]=fib[i-1]+fib[i-2];

    pthread_exit(NULL);
}

int main()
{
    pthread_t t;
    system("date");
    printf("Enter number of terms: ");
    scanf("%d",&n);

    pthread_create(&t,NULL,generate,NULL);
    pthread_join(t,NULL);

    printf("Fibonacci Series:\n");
    for(int i=0;i<n;i++)
        printf("%d ",fib[i]);

    return 0;
}
