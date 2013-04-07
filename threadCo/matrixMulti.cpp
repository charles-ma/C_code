#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <pthread.h>

using namespace std;

int** m1, **m2, **result, threadNum, matrixDeg;

//carry out the calculation for a certain thread
void * calculate(void * index) {
  int* num = (int*) index;
  int id = *num;
  for(int i = id; i < matrixDeg; i += threadNum) {
    for(int j = 0; j < matrixDeg; j++) {
      result[i][j] = 0;
      for(int k = 0; k < matrixDeg; k++) {
	result[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}

int main(int argv, char** args) {
  
  //allocate space for the parameters
  char* fileName = (char*) malloc(100*sizeof(char));
  char* pNum = (char*) malloc(5 * sizeof(char));
  char* mDeg = (char*) malloc(5 * sizeof(char));
  
  //check whether there are enough parameters
  if(argv < 4) {
    cout << "Too few parameters!" << endl;
    return 0;
  }
  
  //copy input into corresponding variables
  strcpy(fileName, args[1]);
  strcpy(pNum, args[2]);
  strcpy(mDeg, args[3]);

  //parse the parameters
  threadNum = atoi(pNum);
  matrixDeg = atoi(mDeg);
  if(matrixDeg == 0 || threadNum == 0) {
    cout << "Parameters can't be 0!" << endl;
    return 0;
  }

  //initialize arrays for the matrices
  m1 = (int**) malloc(matrixDeg * sizeof(int*));  
  m2 = (int**) malloc(matrixDeg * sizeof(int*));
  result = (int**) malloc(matrixDeg * sizeof(int*));
  for(int i = 0; i < matrixDeg; i++) {
    m1[i] = (int*)malloc(matrixDeg *  sizeof(int));
    m2[i] = (int*)malloc(matrixDeg * sizeof(int));
    result[i] = (int*)malloc(matrixDeg * sizeof(int));
  }


  //open the file that contains the matrices to be multiplied
  ifstream source(fileName, ifstream:: in);
  if(!source.is_open()) {
    cout << "Can't open " << fileName << endl;
    return 0;
  }

  //read the matrices to conresponding arrays
  string line;
  int index = 0;
  while(getline(source, line)) {
    if(line.compare("") != 0) {
      istringstream iss(line);
      if(index < matrixDeg) {
	for(int j = 0; j < matrixDeg; j++) {
	  iss >> m1[index][j];
	}
      } else if(index > matrixDeg){
	for(int j = 0; j < matrixDeg; j++) {
	  iss >> m2[index - matrixDeg - 1][j];
	}
      }
    }
    index++;
  }
  
  //create workers to do the job
  pthread_t workers[threadNum];
  for(int i = 0; i < threadNum; i++) {
    pthread_t worker;
    int *para = (int*)malloc(sizeof(int));
    *para = i;
    pthread_create(&worker, NULL, calculate, para);
    workers[i] = worker;
  }
  for(int i = 0; i < threadNum; i++) {
    pthread_join(workers[i], NULL);
  }


  //write the result out in the format that an integer will take a constant length, it's better to comment this out when timing the program
  int width = 3;
  cout << "The multiplication of" << endl;
  for(int i = 0; i < matrixDeg; i++) {
    for(int j = 0; j < matrixDeg; j++) {
      cout << setw(width) << m1[i][j];
    }
    cout << endl;
  }

  cout << "and" << endl;

  for(int i = 0; i < matrixDeg; i++) {
    for(int j = 0; j < matrixDeg; j++) {
      cout << setw(width) << m2[i][j];
    }
    cout << endl;
  }

  cout << "is" << endl;

  for(int i = 0; i < matrixDeg; i++) {
    for(int j = 0; j < matrixDeg; j++) {
      cout << setw(width) << result[i][j];
    }
    cout << endl;
  }
}


