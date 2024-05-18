#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define PHIL 5
#define FORK 5

sem_t forks[FORK];
void* philosopher(void* num){

    int philosopher_num = *((int *) num),left_fork = philosopher_num,right_fork = (philosopher_num + 1) % FORK;

    while(1){
        sleep(1);
        if (right_fork > left_fork){
            int temp = right_fork;
            right_fork = left_fork;
            left_fork = temp;
        }
        sem_wait(&forks[right_fork]);
        sem_wait(&forks[left_fork]);

        printf("Philosopher %d is eating\n", philosopher_num);
        sleep(1);
        printf("Philosopher %d is putting down forks\n", philosopher_num);
        sem_post(&forks[left_fork]);
        sem_post(&forks[right_fork]);
    }
}

int main() {
    pthread_t philosophersArray[PHIL];
    
    int phil_num[PHIL];

    for (int i = 1; i <= FORK; i++){
        sem_init(&forks[i], 0, 1);
    }

    for (int i = 1; i <= PHIL; i++){
        phil_num[i] = i;
        pthread_create(&philosophersArray[i], NULL, philosopher, &phil_num[i]);
    }

    for (int i = 1; i <= PHIL; i++){
        pthread_join(philosophersArray[i], NULL);
    }
    
    return 0;
}
