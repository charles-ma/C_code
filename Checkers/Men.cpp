#include <iostream>
#include "Men.h"

using namespace std;

Men:: Men(Side _side, Board* board): Piece(_side, board) {

}

Men:: ~Men() {

}

bool Men:: move(int x, int y) {
  cout << "Men's move" << endl;
}
