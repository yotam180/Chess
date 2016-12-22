#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(Square* base) : Piece(base) {}
	Queen(Square* base, int player) : Piece(base, player) {}
	char getType() { return 'q'; }
	char getChar() { return _player == 0 ? 'Q' : 'q'; }
	vector<Move>* getPossibleMoves();
	~Queen();
};

