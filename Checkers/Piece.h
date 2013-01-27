#ifndef PIECE_H
#define PIECE_H

#include <iostream>

enum Side {black, red, white};
enum Kind {king, men};

class Piece {
 public:
  Side side;
  Kind kind;
  Piece(Side, Kind);
  ~Piece();
};

#endif
