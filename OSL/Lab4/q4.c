#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int arr1[MAX], arr2[MAX];
int n;

void* bubble(void* arg)
{
    clock_t start = clock();
    
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr1[j] > arr1[j+1])
            {
                int t=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=t;
            }

    clock_t end = clock();
    printf("Bubble Sort Time: %lf\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    pthread_exit(NULL);
}

void* selection(void* arg)
{
    clock_t start = clock();

    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
            if(arr2[j] < arr2[min])
                min=j;

        int t=arr2[i];
        arr2[i]=arr2[min];
        arr2[min]=t;
    }

    clock_t end = clock();
    printf("Selection Sort Time: %lf\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    pthread_exit(NULL);
}

int main()
{
    pthread_t t1,t2;
    system("date");
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
        arr2[i]=arr1[i];
    }

    pthread_create(&t1,NULL,bubble,NULL);
    pthread_create(&t2,NULL,selection,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Final Sorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr1[i]);

    return 0;
}
