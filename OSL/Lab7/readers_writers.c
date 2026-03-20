// 2. Write a C/C++ program for first readers-writers problem using semaphores.

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
sem_t wrt;

int readcount = 0;
int data = 0;

void *reader(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&mutex);
    readcount++;

    if (readcount == 1)
        sem_wait(&wrt);

    sem_post(&mutex);

    printf("Reader %d is reading data = %d\n", id, data);
    sleep(1);

    sem_wait(&mutex);
    readcount--;

    if (readcount == 0)
        sem_post(&wrt);

    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&wrt);

    data++;
    printf("Writer %d is writing data = %d\n", id, data);
    sleep(2);

    sem_post(&wrt);

    return NULL;
}

int main()
{
    pthread_t r[5], w[2];
    int i;

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    int rid[5], wid[2];

    for (i = 0; i < 5; i++)
    {
        rid[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &rid[i]);
    }

    for (i = 0; i < 2; i++)
    {
        wid[i] = i + 1;
        pthread_create(&w[i], NULL, writer, &wid[i]);
    }

    for (i = 0; i < 5; i++)
        pthread_join(r[i], NULL);

    for (i = 0; i < 2; i++)
        pthread_join(w[i], NULL);

    return 0;
}


// gcc readers_writers.c -lpthread
// ./a.out