#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <list>
#include "Piece.h"
#include "Position.h"

using namespace std;

class Board {

 private:
  Piece*** grid;

 public:
  Board();
  ~Board();
  void resp();
  Piece* getPiece(int, int);
  bool setPiece(int, int, Piece*);
  bool move(int, int, int, int);
  list<Position> getPath(Position, Position);
 private:
  bool findJumpPath(Position, Position, list<Position>*, Side, Kind);
  bool findMovePath(Position, Position, list<Position>*);
  bool isPhysicPos(Position);
  list<Position> findPossibleMove(Position);
  list<Position> findPossibleJump(Position, Position, Side, Kind);
};

#endif
