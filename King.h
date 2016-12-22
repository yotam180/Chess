#pragma once
#include "Piece.h"
class King :
	public Piece
{
public:
	King(Square *base) : Piece(base) {}
	King(Square *base, int player) : Piece(base, player) {}
	char getType() { return 'k'; }
	char getChar() { return _player == 0 ? 'K' : 'k'; };
	vector<Move>* getPossibleMoves();
	bool isPossible(Move& m);
	~King();
};

