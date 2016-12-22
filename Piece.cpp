#include "Piece.h"
#include <string>
#include <iostream>
using namespace std;

Piece::Piece(Square* base)
{
	_square = base;
	*base << this;
	current_possible_moves = vector<Move>();
}

Piece::Piece(Square * base, int player)
{
	_square = base;
	*base << this;
	_player = player;
	current_possible_moves = vector<Move>();
}


Piece::~Piece()
{
}

int Piece::getPlayer()
{
	return _player;
}

Square & Piece::getSquare()
{
	return *_square;
}

void Piece::setSquare(Square * s)
{
	_square = s;
}

bool Piece::isPossible(Move& m)
{
	Square *mySqr = _square;
	Piece* myPc = &mySqr->getPiece();
	Piece* otherPc = &m._dst->getPiece();
	if (otherPc != nullptr)
	{
		m._dst->clearPiece(false);
		*m._dst << myPc;
	}
	m._src->clearPiece(false);
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if ((*_square)(row, col).isEmpty()) continue;
			Piece *p = &(*_square)(row, col).getPiece();
			if (p->getPlayer() != _player)
			{
				p->getPossibleMoves();
				if (p->checks())
				{
					*m._src << myPc;
					m._dst->clearPiece(false);
					if (otherPc != nullptr)
					{
						*m._dst << otherPc;
					}
					_error_num = 4;
					return false;
				}
			}
		}
	}
	*m._src << myPc;
	m._dst->clearPiece(false);
	if (otherPc != nullptr)
	{
		*m._dst << otherPc;
	}
	for (int i = 0; i < (int)current_possible_moves.size(); i++)
	{
		if (current_possible_moves[i]._dst->getRow() == m._dst->getRow() && current_possible_moves[i]._dst->getCol() == m._dst->getCol())
		{
			_error_num = 0;
			return true;
		}
	}
	_error_num = 6;
	return false;
}

void Piece::move(int _row, int _col)
{
	_square->getBoard().move(Move(_square, &_square->getBoard()(_row, _col)));
}

bool Piece::checks()
{
	for (int i = 0; i < (int)current_possible_moves.size(); i++)
	{
		if (!current_possible_moves[i]._dst->isEmpty() &&
			current_possible_moves[i]._dst->getPiece().getType() == 'k' &&
			current_possible_moves[i]._dst->getPiece().getPlayer() != _player)
		{
			return true;
		}
	}
	return false;
}

void Piece::clearPossibleMoves()
{
	while (!current_possible_moves.empty())
	{
		current_possible_moves.pop_back();
	}
}
