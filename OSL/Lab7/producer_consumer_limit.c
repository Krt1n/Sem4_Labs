/* Modify the above Producer-Consumer program so that, a producer can produce at the 
most 10 items more than what the consumer has consumed.*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define LIMIT 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

int produced = 0;
int consumed = 0;

sem_t empty;
sem_t full;
sem_t mutex;

void *producer(void *arg)
{
    int item = 1;

    while (1)
    {
        if (produced - consumed >= LIMIT)
        {
            printf("Producer waiting (limit reached)\n");
            sleep(1);
            continue;
        }

        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("Produced: %d\n", item);

        in = (in + 1) % BUFFER_SIZE;
        produced++;
        item++;

        sem_post(&mutex);
        sem_post(&full);

        sleep(1);
    }
}

void *consumer(void *arg)
{
    int item;

    while (1)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        item = buffer[out];
        printf("Consumed: %d\n", item);

        out = (out + 1) % BUFFER_SIZE;
        consumed++;

        sem_post(&mutex);
        sem_post(&empty);

        sleep(2);
    }
}

int main()
{
    pthread_t p, c;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}

// gcc producer_consumer_limit.c -lpthread
// ./a.out
