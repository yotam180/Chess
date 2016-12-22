#include "Rook.h"
#include "CustomExceptions.h" 


Rook::Rook(Square *base) : Piece(base)
{ }

Rook::Rook(Square * base, int player) : Piece(base, player)
{ }


Rook::~Rook()
{
	
}

vector<Move>* Rook::getPossibleMoves()
{
	clearPossibleMoves();
	for (int i = _square->getRow() + 1; i < 8; i++)
	{
		if (!(*_square)(i, _square->getCol()).isEmpty())
		{
			if ((*_square)(i, _square->getCol()).getPiece().getPlayer() != _player)
				current_possible_moves.push_back(Move(_square, &(*_square)(i, _square->getCol())));
			break;
		}
		current_possible_moves.push_back(Move(_square, &(*_square)(i, _square->getCol())));
	}
	for (int i = _square->getRow() - 1; i >= 0; i--)
	{
		if (!(*_square)(i, _square->getCol()).isEmpty())
		{
			if ((*_square)(i, _square->getCol()).getPiece().getPlayer() != _player)
				current_possible_moves.push_back(Move(_square, &(*_square)(i, _square->getCol())));
			break;
		}
		current_possible_moves.push_back(Move(_square, &(*_square)(i, _square->getCol())));
	}
	for (int i = _square->getCol() + 1; i < 8; i++)
	{
		if (!(*_square)(_square->getRow(), i).isEmpty())
		{
			if ((*_square)(_square->getRow(), i).getPiece().getPlayer() != _player)
				current_possible_moves.push_back(Move(_square, &(*_square)(_square->getRow(), i)));
			break;
		}
		current_possible_moves.push_back(Move(_square, &(*_square)(_square->getRow(), i)));
	}
	for (int i = _square->getCol() - 1; i >= 0; i--)
	{
		if (!(*_square)(_square->getRow(), i).isEmpty())
		{
			if ((*_square)(_square->getRow(), i).getPiece().getPlayer() != _player)
				current_possible_moves.push_back(Move(_square, &(*_square)(_square->getRow(), i)));
			break;
		}
		current_possible_moves.push_back(Move(_square, &(*_square)(_square->getRow(), i)));
	}
	return &current_possible_moves;
}