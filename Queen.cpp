#include "Queen.h"


vector<Move>* Queen::getPossibleMoves()
{
	clearPossibleMoves();
	for (int r = -1; r <= 1; r++)
	{
		for (int c = -1; c <= 1; c++)
		{
			if (!c && !r) continue;
			for (int dR = _square->getRow() + r, dC = _square->getCol() + c; dR >= 0 && dR < 8 && dC >= 0 && dC < 8; dR += r, dC += c)
			{
				if (!(*_square)(dR, dC).isEmpty())
				{
					if ((*_square)(dR, dC).getPiece().getPlayer() != _player)
						current_possible_moves.push_back(Move(_square, dR, dC));
					break;
				}
				current_possible_moves.push_back(Move(_square, dR, dC));
			}
		}
	}
	return &current_possible_moves;
}

Queen::~Queen()
{
}
