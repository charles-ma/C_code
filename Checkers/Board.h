#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <list>
#include <cmath>
#include "Piece.h"
#include "Position.h"

using namespace std;

class Board {

 private:
  Piece*** grid;

 public:
  Board();
  ~Board();
  //print out the board
  bool printBoard();
  //get the piece in a certain position
  Piece* getPiece(int, int);
  //set the piece in a certain position
  bool setPiece(int, int, Piece*);
  //move a step
  bool move(int, int, int, int);
  //get the path from start position to end position
  list<Position> getPath(Position, Position);
  //check which side has won the game
  Side checkWin();
  //get all movable pieces for a side
  list<Piece*> getMovablePieces(Side);
 private:
  //initialize the board
  bool initBoard();
  //find the jump path from start position to end position
  bool findJumpPath(Position, Position, list<Position>*, Side, Kind);
  //find the one step path from start position to end position
  bool findMovePath(Position, Position, list<Position>*);
  //check whether a space can be occupide
  bool isPhysicPos(Position);
  //find all the possible one step move for a position
  list<Position> findPossibleMove(Position);
  //find all the possible jump step for a position
  list<Position> findPossibleJump(Position, Position, Side, Kind);
};

#endif
