#pragma once
#include "Piece.h"
class Piece;
#include "Square.h"
class Square;

class Rook : public Piece
{
public:
	Rook(Square* base);
	Rook(Square* base, int player);
	~Rook();
	char getType() { return 'r'; }
	char getChar() { return _player == 0 ? 'R' : 'r'; }
	vector<Move>*  getPossibleMoves();
};

