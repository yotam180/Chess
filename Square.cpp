#include "Square.h"


Square::Square(Board* base, int row, int col)
{
	_board = base;
	_piece = nullptr;
	_x = row;
	_y = col;
}

void Square::seek()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (&(*_board)(i, j) == this)
			{
				_x = i;
				_y = j;
			}
		}
	}
}

Square::Square(Board *base, Piece* piece, int row, int col)
{
	_board = base;
	_piece = piece;
	_x = row;
	_y = col;
}


Square::~Square()
{
	if (_piece != nullptr)
	{
		delete _piece;
	}
}

bool Square::isEmpty()
{
	return _piece == nullptr;
}

Piece & Square::getPiece()
{
	return *_piece;
}

void Square::clearPiece(bool withDelete)
{
	if (_piece != nullptr && withDelete)
	{
		delete _piece;
	}
	_piece = nullptr;
}

Piece & Square::operator<<(Piece * piece)
{
	clearPiece();
	_piece = piece;
	return *piece;
}

int Square::getRow()
{
	return _x;
}

int Square::getCol()
{
	return _y;
}

Board & Square::getBoard()
{
	return *_board;
}

string Square::str()
{
	return "ABCDEFGHI"[_y] + std::to_string(1 + _x);
}

bool Square::exists(int _row, int _col)
{
	return _row >= 0 && _row < 8 && _col >= 0 && _col < 8;
}

Square & Square::operator()(int row, int col)
{
	if (_board == nullptr)
	{
		throw exception("No board for square");
	}
	return (*_board)(row, col);
	// TODO: insert return statement here
}
