#include <fstream>
#include <iostream>

using namespace std;

int main(int argv, char** argc) {
  ofstream myfile;
  myfile.open("sample1000.txt");
  int size = 1000;
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      myfile << 1 << " ";
    }
    myfile << "\n";
  }
  myfile << "\n";
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      myfile << 1 << " ";
    }
    myfile << "\n";
  }
  myfile.close();
}
