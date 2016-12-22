#pragma once
#include "Board.h"
class Board;
#include "Square.h"
class Square;

namespace Communication
{
	char board_desc[66];

	Square& getSquare(const char* sq)
	{
		int col = string("ABCDEFGH").find(sq[0]);
		if (col == -1) col = string("abcdefgh").find(sq[0]);
		int row = sq[1] - '1';
		if (col > 7 || col < 0 || row > 7 || row < 0) throw "Out of range.";
		return Board::getMainBoard()(row, col);
	}

	char* parseBoard(Board *b)
	{
		for (int row = 7; row >= 0; row--)
		{
			for (int col = 0; col < 8; col++)
			{
				if (Board::getMainBoard()(row, col).isEmpty())
				{
					board_desc[(7 - row) * 8 + col] = '#';
				}
				else
				{
					board_desc[(7 - row) * 8 + col] = Board::getMainBoard()(row, col).getPiece().getChar();
				}
			}
		}
		board_desc[64] = '0';
		board_desc[65] = '\0';
		return board_desc;
	}
}