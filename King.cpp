#include "King.h"



vector<Move>* King::getPossibleMoves()
{
	clearPossibleMoves();
	for (int c = -1; c <= 1; c++)
	{
		for (int r = -1; r <= 1; r++)
		{
			if (Square::exists(_square->getRow() + r, _square->getCol() + c))
			{
				if ((*_square)(_square->getRow() + r, _square->getCol() + c).isEmpty() ||
					(*_square)(_square->getRow() + r, _square->getCol() + c).getPiece().getPlayer() != _player)
					current_possible_moves.push_back(Move(_square, _square->getRow() + r, _square->getCol() + c));
			}
		}
	}
	return &current_possible_moves;
}

bool King::isPossible(Move & m)
{
	_square->clearPiece(false);
	*m._dst << this;
	for (int col = 0; col < 8; col++)
	{
		for (int row = 0; row < 8; row++)
		{
			if ((*_square)(row, col).isEmpty() || (*_square)(row, col).getPiece().getPlayer() == _player) continue;
			(*_square)(row, col).getPiece().getPossibleMoves();
			if ((*_square)(row, col).getPiece().checks())
			{
				m._dst->clearPiece(false);
				*m._src << this;
				return false;
			}
		}
	}
	m._dst->clearPiece(false);
	*m._src << this;
	for (int i = 0; i < (int)current_possible_moves.size(); i++)
	{
		if (current_possible_moves[i]._dst->getRow() == m._dst->getRow() && current_possible_moves[i]._dst->getCol() == m._dst->getCol())
		{
			return true;
		}
	}
	return false;
}

King::~King()
{
}
