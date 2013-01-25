#ifndef PIECE_H
#define PIECE_H

#include <iostream>

enum Kind {men, king};
enum Side {black, red};

class Piece {
 public:
  Kind kind;
  Side side;
  Piece(Side, Kind = men);
  ~Piece();
};

#endif
