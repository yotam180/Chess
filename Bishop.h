#pragma once
#include "Piece.h"
#include "Square.h"
class Square;
#include "CustomExceptions.h"

class Bishop : public Piece
{
public:
	Bishop(Square* base) : Piece(base) {}
	Bishop(Square* base, int player);
	~Bishop();
	char getType() { return 'b'; }
	char getChar() { return _player == 0 ? 'B' : 'b'; }
	vector<Move>* getPossibleMoves();
};

