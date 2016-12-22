#pragma once
#include "Piece.h"
#include "Square.h"
class Square;
#include "CustomExceptions.h"

class Knight : public Piece
{
public:
	Knight(Square* base) : Piece(base) {}
	Knight(Square* base, int player);
	~Knight();
	char getType() { return 'n'; }
	char getChar() { return _player == 0 ? 'N' : 'n'; }
	vector<Move>* getPossibleMoves();
};

