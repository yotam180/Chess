#pragma once
#include "Square.h"
class Square;
#include "Move.h"
class Move;

class Board
{
public:
	friend void loadFromChar(Board *b, char* tmplt);
	Board(bool empty = false);
	~Board();
	void setMain();
	Square& operator()(int row, int col);
	void print();
	void move(Move& m);
	static Board& getMainBoard();
	int getPlayer() { return turn; }

private:
	Square*** _board; // 2 dimensional array to Shape pointer
	int turn;
};
