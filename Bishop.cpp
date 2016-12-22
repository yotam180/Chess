#include "Bishop.h"
#include <tuple>
#include <iostream>
using namespace std;

Bishop::Bishop(Square* base, int player) : Piece(base, player)
{ }


Bishop::~Bishop()
{ }

vector<Move>* Bishop::getPossibleMoves()
{
	clearPossibleMoves();
	// Do magic stuff to calculate moves
	for (int row = _square->getRow() + 1, col = _square->getCol() + 1; row < 8 && col < 8; row++, col++)
	{
		if (!(*_square)(row, col).isEmpty())
		{
			if ((*_square)(row, col).getPiece().getPlayer() != _player)
				current_possible_moves.push_back(Move(_square, &(*_square)(row, col)));
			break;
		}
		current_possible_moves.push_back(Move(_square, &(*_square)(row, col)));
	}
	for (int row = _square->getRow() + 1, col = _square->getCol() - 1; row < 8 && col >= 0; row++, col--)
	{
		if (!(*_square)(row, col).isEmpty())
		{
			if ((*_square)(row, col).getPiece().getPlayer() != _player)
				current_possible_moves.push_back(Move(_square, &(*_square)(row, col)));
			break;
		}
		current_possible_moves.push_back(Move(_square, &(*_square)(row, col)));
	}
	for (int row = _square->getRow() - 1, col = _square->getCol() - 1; row >= 0 && col >= 0; row--, col--)
	{
		if (!(*_square)(row, col).isEmpty())
		{
			if ((*_square)(row, col).getPiece().getPlayer() != _player)
				current_possible_moves.push_back(Move(_square, &(*_square)(row, col)));
			break;
		}
		current_possible_moves.push_back(Move(_square, &(*_square)(row, col)));
	}
	for (int row = _square->getRow() - 1, col = _square->getCol() + 1; col < 8 && row >= 0; row--, col++)
	{
		if (!(*_square)(row, col).isEmpty())
		{
			if ((*_square)(row, col).getPiece().getPlayer() != _player)
				current_possible_moves.push_back(Move(_square, &(*_square)(row, col)));
			break;
		}
		current_possible_moves.push_back(Move(_square, &(*_square)(row, col)));
	}
	return &current_possible_moves;
}