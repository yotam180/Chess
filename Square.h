#pragma once
#include "Board.h"
class Board;
#include "Piece.h"
class Piece;
#include <string>

class Square
{
public:
	Square() {}
	Square(Board* base, int row, int col);
	Square(Board* base, Piece* piece, int row, int col);
	~Square();
	bool isEmpty();
	Piece& getPiece();
	void clearPiece(bool withDelete = true);
	Piece& operator<<(Piece* piece);
	int getRow();
	int getCol();
	Board& getBoard();
	string str();
	static bool exists(int _row, int _col);
	Square& operator()(int row, int col);
private:
	void seek();

	Board* _board;
	int _x, _y;
	Piece* _piece;
};
