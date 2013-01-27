#include <iostream>
#include "Position.h"

Position:: Position(int _x, int _y) {
  x = _x;
  y = _y;
}

Position:: ~Position() {

}

Position:: Position(const Position& p) {
  x = p.x;
  y = p.y;
}

int Position:: getX() {
  return x;
}

int Position:: getY() {
  return y;
}

void Position:: setX(int _x) {
  x = _x;
}

void Position:: setY(int _y) {
  y = _y;
}

bool Position:: operator==(Position& pos) {
  return (pos.x == x && pos.y == y);
}

Position Position:: topLeft() {
  if(x - 1 > 0 && y - 1 > 0) return Position(x - 1, y - 1); 
  return Position(0, 0);
}

Position Position:: topRight() {
  if(x - 1 > 0 && y + 1 <= 8) return Position(x - 1, y + 1); 
  return Position(0, 0);
}

Position Position:: bottomLeft() {
  if(x + 1 <= 8 && y - 1 > 0) return Position(x + 1, y - 1); 
  return Position(0, 0);
}

Position Position:: bottomRight() {
  if(x + 1 <= 8 && y + 1 <= 8) return Position(x + 1, y + 1); 
  return Position(0, 0);
}

