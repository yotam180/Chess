#include "Board.h"
#include "Pawn.h"
class Pawn;
#include "Rook.h"
class Rook;
#include "Bishop.h"
class Bishop;
#include "Knight.h"
class Knight;
#include "Queen.h"
class Queen;
#include "King.h"
class King;
#include <iostream>
using namespace std;

#define PC(x,y) (*this)(x, y) << new Piece(&(*this)(x, y)


#ifndef main_board_d
#define main_board_d
Board* main_board;
#endif

void loadFromChar(Board* b, char* tmplt)
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			char p = tmplt[(7 - row) * 8 + col];
			if (p == '#') continue;
			int player = p >= 'A' && p <= 'Z' ? 0 : 1;
			char type = p <= 'Z' ? p - 'A' + 'a' : p;
			if (type == 'p') new Pawn(&(*b)(row, col), player);
			else if (type == 'r') new Rook(&(*b)(row, col), player);
			else if (type == 'n') new Knight(&(*b)(row, col), player);
			else if (type == 'b') new Bishop(&(*b)(row, col), player);
			else if (type == 'k') new King(&(*b)(row, col), player);
			else if (type == 'q') new Queen(&(*b)(row, col), player);
		}
	}
}

Board::Board(bool empty)
{
	turn = 0;
	main_board = this; 
	_board = new Square**[8];
	for (int i = 0; i < 8; i++)
	{
		_board[i] = new Square*[8];
		for (int j = 0; j < 8; j++)
		{
			_board[i][j] = new Square(this, i, j);
		}
	}
	if (!empty)
	{
		loadFromChar(this, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR");
	}
}


Board::~Board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete _board[i][j];
		}
		delete _board[i];
	}
	delete _board;
}

void Board::setMain()
{
	main_board = this;
}

Square & Board::operator()(int row, int col)
{
	return *_board[row][col];
}

void Board::print()
{
	cout << "----------" << endl;
	for (int i = 7; i >= 0; i--)
	{
		cout << "|";
		for (int j = 0; j < 8; j++)
		{
			cout << (char)(_board[i][j]->isEmpty() ? ' ' : _board[i][j]->getPiece().getChar());
		}
		cout << "|" << endl;
	}
	cout << "----------" << endl;
}

void Board::move(Move & m)
{
	if (!m._dst->isEmpty())
	{
		m._dst->clearPiece(true);
	}
	*m._dst << &m._src->getPiece();
	m._dst->getPiece().setSquare(m._dst);
	m._src->clearPiece(false);
	turn = turn == 0 ? 1 : 0;
}

Board & Board::getMainBoard()
{
	return *main_board;
}
