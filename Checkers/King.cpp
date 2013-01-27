#include <iostream>
#include "King.h"

using namespace std;

King:: King(Side _side, Board* board): Piece(_side, board) {

}

King:: ~King() {

}

bool King:: move(int x, int y) {
  cout << "king's move" << endl;
}
