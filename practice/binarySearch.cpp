#include <iostream>

using namespace std;

int binarySearch(int, int[], int, int);

int main(int argc, char** argv) {
  int a[5] = {1, 2, 3, 4, 5};
  for(int i = 0; i < 6; i++) {
    cout << binarySearch(i, a, 0, 4) << endl;
  }
}

int binarySearch(int i, int a[], int start, int end) {
  int mid = (start + end) / 2;
  if(start > end) return -1;
  if(a[mid] == i) return mid;
  if(a[mid] > i) return binarySearch(i, a, start, mid - 1);
  if(a[mid] < i) return binarySearch(i, a, mid + 1, end);
}
