#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} semaphore_t;

void sem_init(semaphore_t* sem, int value) {
    sem->count = value;
    pthread_mutex_init(&sem->mutex, NULL);
    pthread_cond_init(&sem->cond, NULL);
}

void sem_wait(semaphore_t* sem) {
    pthread_mutex_lock(&sem->mutex);
    while (sem->count <= 0) {
        pthread_cond_wait(&sem->cond, &sem->mutex);
    }
    sem->count--;
    pthread_mutex_unlock(&sem->mutex);
}

void sem_post(semaphore_t* sem) {
    pthread_mutex_lock(&sem->mutex);
    sem->count++;
    pthread_cond_signal(&sem->cond);
    pthread_mutex_unlock(&sem->mutex);
}

void sem_destroy(semaphore_t* sem) {
    pthread_mutex_destroy(&sem->mutex);
    pthread_cond_destroy(&sem->cond);
}
