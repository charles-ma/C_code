#include <cstdio>
#include <cstdlib>
#include "pthread.h"
#include "semaphore.h"
#include "unistd.h"

sem_t forks[5];
sem_t limit;

//take up the fork
void takeFork(int i) {
  sem_wait(&forks[i]);
}

//put down the fork
void putFork(int i) {
  sem_post(&forks[i]);
}

//things that a philosopher will do 
void * action(void * index) {
  int * i = (int*) index;
  while(true) {
    sleep(2);
    sem_wait(&limit);
    takeFork(*i);
    takeFork((*i + 1) % 5);
    printf("Philosopher %d is eating!\n", *i);
    sleep(1);
    printf("Philosopher %d finishes eating!\n", *i);
    putFork(*i);
    putFork((*i + 1) % 5);
    sem_post(&limit);
  }
}

int main() {
  
  //init the limit for the number of philosophers trying to eat and five forks
  sem_init(&limit, 0, 4);
  for(int i = 0; i < 5; i++) {
    sem_init(&forks[i], 0, 1);
  }

  //init five philosophers
  pthread_t philosophers[5];
  for(int i = 0; i < 5; i++) {
    pthread_t philosopher;
    int *para = (int*) malloc(sizeof(int));
    *para = i;
    pthread_create(&philosopher, NULL, action, para);
    philosophers[i] = philosopher;
  }

  //make main thread wait for the five philosophers
  for(int i = 0; i < 5; i++) {
    pthread_join(philosophers[i], NULL);
  }

}
