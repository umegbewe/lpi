#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "semaphore.h"

#define NUM_THREADS 10

semaphore_t mutex;

void* thread_func(void* arg) {
    long tid = (long)arg;
    printf("Thread %ld started\n", tid);
    sem_wait(&mutex);
    printf("Thread %ld entering\n", tid);
    sleep(1);
    printf("Thread %ld leaving critical section\n", tid);
    sem_post(&mutex);
    printf("Thread %ld finished\n", tid);
    return NULL;
}


int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    sem_init(&mutex, 1);
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, thread_func, (void*)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            return 1;
        }
    }
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    sem_destroy(&mutex);
    return 0;
}
