#include "Knight.h"
#include <tuple>
#include <iostream>
using namespace std;

Knight::Knight(Square* base, int player) : Piece(base, player)
{ }


Knight::~Knight()
{ }

vector<Move>* Knight::getPossibleMoves()
{
	clearPossibleMoves();
	vector<tuple<int, int>> knight_moves = vector<tuple<int, int>>();
	knight_moves.push_back(tuple<int, int>(2, -1));
	knight_moves.push_back(tuple<int, int>(2, 1));
	knight_moves.push_back(tuple<int, int>(-2, -1));
	knight_moves.push_back(tuple<int, int>(-2, 1));
	knight_moves.push_back(tuple<int, int>(1, -2));
	knight_moves.push_back(tuple<int, int>(1, 2));
	knight_moves.push_back(tuple<int, int>(-1, -2));
	knight_moves.push_back(tuple<int, int>(-1, 2));
	for (int i = 0; i < (int)knight_moves.size(); i++)
	{
		if (Square::exists(_square->getRow() + get<0>(knight_moves[i]), _square->getCol() + get<1>(knight_moves[i])))
		{
			if (!_square->getBoard()(_square->getRow() + get<0>(knight_moves[i]), _square->getCol() + get<1>(knight_moves[i])).isEmpty()
				&& _square->getBoard()(_square->getRow() + get<0>(knight_moves[i]), _square->getCol() + get<1>(knight_moves[i])).getPiece().getPlayer() == _player)
				continue;

			current_possible_moves.push_back(Move(_square, &_square->getBoard()(_square->getRow() + get<0>(knight_moves[i]), _square->getCol() + get<1>(knight_moves[i]))));
		}
	}
	return &current_possible_moves;
}