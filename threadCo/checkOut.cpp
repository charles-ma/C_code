#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "pthread.h"
#include "semaphore.h"
#include "unistd.h"

int customerNum;
int *itemNum;
sem_t *sems;
bool allOpen = false;
int *line1;
int *line2;
int *lineExp;
sem_t mutex;

//print out lines
void printLines() {
    printf("LineExp: ");
    for(int i = 0; i < customerNum; i++) {
      if(lineExp[i] != -1) {
	int cus = lineExp[i];
	printf("%d(%d) ", cus, itemNum[cus]);
      }
    }
    printf("\n");

    printf("Line1: ");
    for(int i = 0; i < customerNum; i++) {
      if(line1[i] != -1) {
	int cus = line1[i];
	printf("%d(%d) ", cus, itemNum[cus]);
      }
    }
    printf("\n");


    printf("Line2: ");
    for(int i = 0; i < customerNum; i++) {
      if(line2[i] != -1) {
	int cus = line2[i];
	printf("%d(%d) ", cus, itemNum[cus]);
      }
    }
    printf("\n---------------------------\n");
}

//shift the line
void shiftLine(int * line) {
  for(int i = 0; i < customerNum - 1; i++) {
    line[i] = line[i + 1];
  }
  line[customerNum - 1] = -1;
}

//find customer number in a line
int findCusNum(int * line) {
  int len = 0;
  for(int i = 0; i < customerNum; i++) {
    if(line[i] == -1) break;
    else len++;
  }
  return len;
}

//find shortest among two lines
int *findShortLine(int * lineOne, int * lineTwo) {
  if(findCusNum(lineOne) < findCusNum(lineTwo)) return lineOne;
  return lineTwo;
}

//find shortest line among three
int *findShortest(int * lineOne, int * lineTwo, int * lineThree) {
  int * shortLine = findShortLine(lineOne, lineTwo);
  shortLine = findShortLine(shortLine, lineThree);
}

//get in line
void getInLine(int * line, int id) {
  for(int i = 0; i < customerNum; i++) {
    if(line[i] == -1) {
      line[i] = id;
      break;
    }
  }
  //printf("%d\n", findCusNum(line));
}

//change line
void changeLine(int * lineOne, int * lineTwo) {
  int len1 = findCusNum(lineOne);
  int len2 = findCusNum(lineTwo);
  int lineChangeNum = rand() % len1 + 1;
  for(int i = 0; i < lineChangeNum; i++) {
    lineTwo[len2 + i] = lineOne[len1 - 1 - i];
    lineOne[len1 - 1 - i] = -1;
  }
}

//customers' action
void * cusAction(void * para) {
  int * index = (int*) para;
  int item = rand() % 8 + 1;
  itemNum[*index] = item;
  //printf("Customer %d with %d items\n", *index, itemNum[*index]);
  //printf("ok");
  while(true){
    int rtime = rand() % 1000; 
    usleep(rtime * 1000);
    sem_wait(&mutex);
    int * line;
    if(allOpen) {
      if(item > 5) {
	line = findShortLine(line1, line2);
      } else {
	line = findShortest(line1, line2, lineExp);
      }
      getInLine(line, *index);
    } else {
      if(item > 5) {
	line = line1;
      } else {
	line = findShortLine(line1, lineExp);
      }
      getInLine(line, *index);
      if(findCusNum(line1) > 5 && allOpen == false) {
	allOpen = true;
	printf("Line2 Open!\n");
	changeLine(line1, line2);
      }
    }
    printLines();
    sem_post(&mutex);

    sem_wait(&sems[*index]);
    //printf("Customer %d paid and leave\n", *index, itemNum[*index]);
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
  customerNum = atoi(para);
  
  //init random number generator
  srand(time(NULL));

  //init arrays
  itemNum = (int*) malloc(customerNum * sizeof(int));
  sems = (sem_t*) malloc(customerNum * sizeof(sem_t));
  line1 = (int*) malloc(customerNum * sizeof(int));
  line2 = (int*) malloc(customerNum * sizeof(int));
  lineExp = (int*) malloc(customerNum * sizeof(int));
  
  sem_init(&mutex, 0, 1);

  for(int i = 0; i < customerNum; i++) {
    itemNum[i] = 0;
    sem_init(&sems[i], 0, 0);
    line1[i] = -1;
    line2[i] = -1;
    lineExp[i] = -1;
  }

  //init the barber thread and customer thread
  pthread_t customers[customerNum];
  for(int i = 0; i < customerNum; i++) {
    int* para = (int*) malloc(sizeof(int));
    *para = i;
    pthread_create(&customers[i], NULL, cusAction, para);
  }

  //serve the customers
  while(true) {
    sleep(1);
    sem_wait(&mutex);
    //printLines();
    if(line1[0] != -1) {
      sem_post(&sems[line1[0]]);
      shiftLine(line1);
    }
    if(line2[0] != -1) {
      sem_post(&sems[line2[0]]);
      shiftLine(line2);
    }
    if(lineExp[0] != -1) {
      sem_post(&sems[lineExp[0]]);
      shiftLine(lineExp);
    }
    printLines();
    sem_post(&mutex);
  }
}
