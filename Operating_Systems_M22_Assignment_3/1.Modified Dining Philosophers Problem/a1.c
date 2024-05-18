#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define PHIL 5
#define FORKS 5

sem_t forks[FORKS];

// Function to simulate the actions of a philosopher
void* philosopher(void* num) {

    int phil_num = *((int *) num);
    int left_fork = phil_num;
    int right_fork = (phil_num + 1) % FORKS;

    while(1){
      
        sleep(1);
        if (left_fork > right_fork) {
            int temp = left_fork;
            left_fork = right_fork;
            right_fork = temp;
        }

        sem_wait(&forks[left_fork]);
        sem_wait(&forks[right_fork]);

        printf("Philosopher %d is eating\n", phil_num);
        sleep(1);

        printf("Philosopher %d is putting down both forks\n", phil_num);
        sem_post(&forks[left_fork]);
        sem_post(&forks[right_fork]);
    }
}

int main() {
    pthread_t philosophers[PHIL];
    int philosopher_nums[PHIL];

    for (int i = 1; i <= FORKS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for (int i = 1; i <= PHIL; i++) {
        philosopher_nums[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_nums[i]);
    }

    for (int i = 1; i <= PHIL; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}
