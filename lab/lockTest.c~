#include<signal.h>
#include<pthread.h>
#include<stdio.h>

pthread_mutex_t lock;

void unLock() {
  pthread_mutex_unlock(&lock);
}

void* printString() {
  pthread_mutex_lock(&lock);
  printf("I am unlocked!\n");
  pthread_mutex_unlock(&lock);
}

int main(int argv, char** argc) {
  pthread_mutex_init(&lock, NULL);
  signal(SIGUSR1, unLock);
  pthread_t t;
  pthread_mutex_lock(&lock);
  pthread_create(&t, NULL, &printString, NULL);
  pthread_join(t, NULL);
  pthread_mutex_destroy(&lock);  
}
