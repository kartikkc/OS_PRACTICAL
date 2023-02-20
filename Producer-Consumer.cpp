#include <iostream>
#include <stdio.h>
#include <pthread.h>   // used to perfrom threading operations
#include <semaphore.h>  // used to perfom semaphore operations
#include <random> // generates random numbers using generators and distributors
#include <unistd.h>  // posix operating system access

using namespace std;
#define BUFFER_SIZE 10

// buffer
int buffer[BUFFER_SIZE];
int index = 0;

// counting semaphore
sem_t full, empty;

// binary semaphore
pthread_mutex_t mutex;

// producer
void produce(voidarg)
{
    while (1)
    {
        sleep(1);
        sem_wait(&empty); 
        pthread_mutex_lock(&mutex); 

        // random no 
        int item = rand() % 100;
        buffer[index++] = item;

        cout << "Produced " << item << endl;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

// consumer
void consume(void* arg)
{
    while (1)
    {
        sleep(1);
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[--index];
        cout << "Consumed " << item << endl;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    pthread_t producer, consumer;
    // initilize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // init thread
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&producer, NULL, produce, NULL);
    pthread_create(&consumer, NULL, consume, NULL);
    pthread_exit(NULL);
}
