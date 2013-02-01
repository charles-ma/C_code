#include <cstdlib>
#include <iostream>

using namespace std;

double getSquareRoot(double);

int main(int argc, char** argv) {
  double n;
  cin >> n;
  cout << getSquareRoot(n) << endl;
  return 0;
}

double getSquareRoot(double n) {
  if(n < 0) return 0;
  double start = 0;
  double end = n;
  double mid = 0;
  for(int i = 0; i < 1000; i++) {
    mid = (start + end) / 2;
    if(mid * mid > n) end = mid;
    else if(mid * mid < n) start = mid;
  }
  return mid;
}
