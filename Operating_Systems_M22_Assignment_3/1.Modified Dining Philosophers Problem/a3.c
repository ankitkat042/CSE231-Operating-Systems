#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#include <unistd.h>

#define PHILOSOPHERS 5

sem_t chopstick;
sem_t bowls;

void eat_from_bowl(int id){
    printf("Philosopher %d eating from bowl.\n", id);
    sleep(1);
}

void useChopsticks(int id){
    printf("Philosopher %d using chopsticks.\n", id);
    sleep(1);
}

void think(int id){
    printf("Philosopher %d is thinking.\n", id);
    sleep(1);
}

void *philosopher(void *arg){
    int num = ((int)arg);
    while (1) {
        sem_wait(&chopstick);
        useChopsticks(num);
        sem_wait(&bowls);
        eat_from_bowl(num);
        sem_post(&bowls);
        sem_post(&chopstick);
        think(num);
    }
}

int main(void) {
    pthread_t philosophers[PHILOSOPHERS];
    int num[PHILOSOPHERS+1];

    for(int i = 1; i < PHILOSOPHERS; i++){
        
        num[i] = i+1;
    }

    sem_init(&chopstick, 0, PHILOSOPHERS - 1);
    sem_init(&bowls, 0, 2);

    for (int i = 0; i < PHILOSOPHERS; i++) {
        num[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, num[i]);
    }

    for (int i = 0; i < PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    sem_destroy(&chopstick);
    sem_destroy(&bowls);

    return 0;
}
