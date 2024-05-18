// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>
// #include <unistd.h>

// #define NUM_PHILOSOPHERS 5

// sem_t forks;
// sem_t sauce_bowls;

// void eat(int id) {
//     printf("\nPhilosopher %d is eating.\n", id);
//     sleep(1);
// }

// void think(int id) {
//     // printf("Philosopher %d is thinking.\n", id);
//     sleep(1);
// }

// void *philosopher(void *arg) {
//     int id = ((int)arg);
//     while (1) {
//         sem_wait(&forks);
//         sem_wait(&sauce_bowls);
//         eat(id);
//         sem_post(&sauce_bowls);
//         sem_post(&forks);
//         think(id);
//     }
// }

// int main(void) {
//     pthread_t philosophers[NUM_PHILOSOPHERS];
//     int ids[NUM_PHILOSOPHERS];

//     sem_init(&forks, 0, NUM_PHILOSOPHERS - 1);
//     sem_init(&sauce_bowls, 0, 2);

//     for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
//         ids[i] = i;
//         pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
//     }

//     for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
//         pthread_join(philosophers[i], NULL);
//     }

//     sem_destroy(&forks);
//     sem_destroy(&sauce_bowls);

//     return 0;
// }

// //This code creates a semaphore for the forks and a semaphore for the sauce bowls, and then creates a thread for each philosopher. The philosophers will acquire the semaphores for the forks and sauce bowls before eating and release them after they are finished. This will ensure that only one philosopher can access a fork or a sauce bowl at a time, preventing the deadlock from occurring.
