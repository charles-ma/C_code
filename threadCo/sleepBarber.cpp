#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "pthread.h"
#include "semaphore.h"
#include "unistd.h"

int customerNum = 0;
sem_t mutex;
sem_t cusSem;
sem_t barSem;

//barber's action
void * barAction(void * para) {
  while(true) {
    sem_wait(&cusSem);
    sem_post(&barSem);
    printf("Barber is giving a hair cut!\n");
    sleep(1);
  }
}

//customers' action
void * cusAction(void * para) {
  int * index = (int*) para;
  while(true) {
    sleep(2);
    sem_wait(&mutex);
    if(customerNum == 3) {
      sem_post(&mutex);
      printf("Customer %d leaves the shop\n", *index);    
      continue;
    } else {
      customerNum++;
      printf("Customer %d waits in line\n", *index);    
    }
    sem_post(&mutex);

    sem_post(&cusSem);
    sem_wait(&barSem);
    printf("Customer %d is getting a hair cut!\n", *index);
  
    sem_wait(&mutex);
    customerNum--;
    printf("Customer %d finishes the hair cut!\n", *index);
    sem_post(&mutex);
  }
} 

int main(int argv, char** args) {

  //parse the parameter: the number of customer thread
  if(argv < 2) {
    printf("Too few parameters! You have to give the number of customers!\n");
    return 0;
  }
  char* para = (char*) malloc(100 * sizeof(char));
  strcpy(para, args[1]);
  int cusNum = atoi(para);
  
  //init the semaphores
  sem_init(&mutex, 0, 1);
  sem_init(&cusSem, 0, 0);
  sem_init(&barSem, 0, 0);

  //init the barber thread and customer thread
  pthread_t barber;
  pthread_t customers[cusNum];
  pthread_create(&barber, NULL, barAction, NULL);
  for(int i = 0; i < cusNum; i++) {
    int* para = (int*) malloc(sizeof(int));
    *para = i;
    pthread_create(&customers[i], NULL, cusAction, para);
  }

  pthread_join(barber, NULL);
  for(int i = 0; i < cusNum; i++) {
    pthread_join(customers[i], NULL);
  }
}
