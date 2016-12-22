#pragma once
#include "Piece.h"
#include "CustomExceptions.h"
class Pawn : public Piece
{
public:
	Pawn(Square* base) : Piece(base) {}
	Pawn(Square* base, int player) : Piece(base, player) {}
	~Pawn();
	char getType() { return 'p'; }
	char getChar() { return _player == 0 ? 'P' : 'p'; }
	vector<Move>* getPossibleMoves();
};

