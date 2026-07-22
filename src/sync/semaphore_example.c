#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void* task(void* arg) {
    sem_wait(&sem);
    printf("Inside critical section\n");
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    sem_init(&sem, 0, 1);

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);
    return 0;
}
