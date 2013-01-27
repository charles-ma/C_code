#include <iostream>
#include "Board.h"

void Board:: resp() {
  if(grid[7][0] != NULL)
    cout << "hello again" << endl;
}

Board:: Board() {
  grid = new Piece**[8];
  for(int i = 0; i < 8; i++) {
    Piece** a = new Piece*[8];
    for(int j = 0; j < 8; j++) {
      a[j] = NULL;
    }
    grid[i] = a;
  }

}

Board:: ~Board() {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(grid[i][j] != NULL) delete grid[i][j];
    }
    delete grid[i];
  }
  delete grid;
}

Piece* Board:: getPiece(int x, int y) {
  if(x <= 8 && x > 0 && y <= 8 && y > 0)
    return grid[x - 1][y - 1];
  return NULL;
}

bool Board:: setPiece(int x, int y, Piece* piece) {
  if(x >= 1 && x <=8 && y >=1 && y <= 8)
    grid[x - 1][y - 1] = piece;
  else return false;
  return true;
}

bool Board:: findJumpPath(Position startPos, Position endPos, list<Position>* possiblePos, Side side, Kind kind) {
  possiblePos -> push_back(startPos);
  list<Position> :: reverse_iterator i;
  Position lastPos = Position(0, 0);
  i = possiblePos -> rbegin();
  i--;
  if(i != possiblePos -> rend()) lastPos = *i;
  list<Position> possibles = findPossibleJump(startPos, lastPos, side, kind);
  if(startPos == endPos) {
    if(possibles.size() == 0) return true;
    else{
      possiblePos -> pop_back();
      return false;
    }
  }
  else if(possibles.size() == 0) {
    possiblePos -> pop_back();
    return false;
  }
  else {
    list<Position> :: iterator j;
    for(j = possibles.begin(); j != possibles.end(); j++) {
      if(findJumpPath(*j, endPos, possiblePos, side, kind)) return true;
    }
    possiblePos -> pop_back();
    return false;
  }
}

list<Position> Board:: getPath(Position startPos, Position endPos) {
  list<Position> result;
  if(endPos.x > 8 || endPos.y > 8 || endPos.x <= 0 || endPos.y <= 0 || startPos == endPos) return result;
  Piece* p = getPiece(startPos.x, startPos.y);
  if(p == NULL) return result;
  if(findJumpPath(startPos, endPos, &result, p -> side, p -> kind))
    return result;
  result.clear();
  if(findMovePath(startPos, endPos, &result))
    return result;
  result.clear();
  return result;
}

bool Board:: findMovePath(Position startPos, Position endPos, list<Position>* possiblePos) {
  list<Position> result = findPossibleMove(startPos);
  list<Position>:: iterator i;
  if(result.size() == 0) return false;
  for(i = result.begin(); i != result.end(); i++) {
    if(endPos == *i) {
      possiblePos -> push_back(startPos);
      possiblePos -> push_back(endPos);
    }
  }
  return true;
}

list<Position> Board:: findPossibleMove(Position point) {
  list<Position> result;
  Piece* p = getPiece(point.x, point.y);
  if(p == NULL) return result;
  if(p -> kind == king) {
    if(isPhysicPos(point.topLeft()))
      result.push_back(point.topLeft());
    if(isPhysicPos(point.topRight()))
      result.push_back(point.topRight());
    if(isPhysicPos(point.bottomLeft()))
      result.push_back(point.bottomLeft());
    if(isPhysicPos(point.bottomRight()))
      result.push_back(point.bottomRight());
  }
  if(p -> kind == men) {
    if(p -> side == red) {
      if(isPhysicPos(point.topLeft()))
	result.push_back(point.topLeft());
      if(isPhysicPos(point.topRight()))
	result.push_back(point.topRight());
    }
    else if(p -> side == black) {
      if(isPhysicPos(point.bottomLeft()))
	result.push_back(point.bottomLeft());
      if(isPhysicPos(point.bottomRight()))
	result.push_back(point.bottomRight());
    }
  }
  return result;
}

list<Position> Board:: findPossibleJump(Position point, Position last, Side side, Kind kind) {
  list<Position> result;
  int x = point.x;
  int y = point.y;
  
  if(kind == king || (kind == men && side == black)){
    if(getPiece(x + 1, y + 1) != NULL && getPiece(x + 1, y + 1) -> side != side && isPhysicPos(Position(x + 2, y + 2)))
      result.push_back(point.bottomRight().bottomRight());
    if(getPiece(x + 1, y - 1) != NULL && getPiece(x + 1, y - 1) -> side != side && isPhysicPos(Position(x + 2, y - 2)))
      result.push_back(point.bottomLeft().bottomLeft());
  }else if(kind == king || (kind == men && side == red)) {
    if(getPiece(x - 1, y + 1) != NULL && getPiece(x - 1, y + 1) -> side != side && isPhysicPos(Position(x - 2, y + 2)))
      result.push_back(point.topRight().topRight());
    if(getPiece(x - 1, y - 1) != NULL && getPiece(x - 1, y - 1) -> side != side && isPhysicPos(Position(x - 2, y - 2)))
      result.push_back(point.topLeft().topLeft());
  }
  return result;
}

bool Board:: isPhysicPos(Position point) {
  if(point.x > 8 || point.y > 8 || point.x <= 0 || point.y <= 0 || getPiece(point.x, point.y) != NULL) return false;
  return true;
}


