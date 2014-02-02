#ifndef PIECE_H
#define PIECE_H

#include <iostream>

enum Side {black, red, white};
enum Kind {king, men};

class Piece {
 public:
  Side side; //the side of the piece, say black or red
  Kind kind; //the kind of the piece, say king or men
  Piece(Side, Kind);
  ~Piece();
};

#endif
