#include "Pawn.h"

Pawn::~Pawn()
{
}

vector<Move>* Pawn::getPossibleMoves()
{
	clearPossibleMoves();
	int dir = _player == 0 ? 1 : -1;
	int strt = _player == 0 ? 1 : 6;
	if (Square::exists(_square->getRow() + dir, _square->getCol()) &&
		(*_square)(_square->getRow() + dir, _square->getCol()).isEmpty())
	{
		current_possible_moves.push_back(Move(_square, _square->getRow() + dir, _square->getCol()));
	}
	if (Square::exists(_square->getRow() + dir * 2, _square->getCol()) &&
		(*_square)(_square->getRow() + dir * 2, _square->getCol()).isEmpty() &&
		_square->getRow() == strt)
	{
		current_possible_moves.push_back(Move(_square, _square->getRow() + dir * 2, _square->getCol()));
	}
	if (Square::exists(_square->getRow() + dir, _square->getCol() + 1) &&
		!(*_square)(_square->getRow() + dir, _square->getCol() + 1).isEmpty() &&
		(*_square)(_square->getRow() + dir, _square->getCol() + 1).getPiece().getPlayer() != _player)
	{
		current_possible_moves.push_back(Move(_square, _square->getRow() + dir, _square->getCol() + 1));
	}
	if (Square::exists(_square->getRow() + dir, _square->getCol() - 1) &&
		!(*_square)(_square->getRow() + dir, _square->getCol() - 1).isEmpty() &&
		(*_square)(_square->getRow() + dir, _square->getCol() - 1).getPiece().getPlayer() != _player)
	{
		current_possible_moves.push_back(Move(_square, _square->getRow() + dir, _square->getCol() - 1));
	}
	return &current_possible_moves;
}