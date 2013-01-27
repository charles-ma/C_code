#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Position.h"
//#include "King.h"
//#include "Men.h"

using namespace std;

int main(int argc, char** argv) {
  Board* board = new Board();
  Piece* piece = new Piece(red, men);
  Piece* other = new Piece(black, men);
  Piece* ano = new Piece(black, king);
  list<Position> result;
  board -> setPiece(7, 2, piece);
  board -> setPiece(6, 3, other);
  board -> setPiece(4, 3, ano);
  result = board -> getPath(Position(7, 2), Position(3, 2));
  list<Position>:: iterator i;
  cout << result.size() << endl;
  for(i = result.begin(); i != result.end(); i++) cout << (*i).x << (*i).y << endl;
}
