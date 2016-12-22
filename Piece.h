#pragma once
#include <iostream>
using namespace std; 
#include <vector>
#include "Square.h"
class Square;
#include "Move.h"
class Move;

class Piece
{
public:
	Piece(Square* base);
	Piece(Square* base, int player);
	virtual ~Piece();
	virtual char getType() = 0; // Type will ALWAYS be a lower-case letter
	virtual int getPlayer();
	Square& getSquare();
	void setSquare(Square* s);
	virtual char getChar() = 0;
	virtual vector<Move>* getPossibleMoves() = 0;
	virtual bool isPossible(Move& m);
	void move(int _row, int _col);
	virtual bool checks();

	int getError() { return _error_num; }

protected:
	Square* _square;
	//char _p;
	int _player;
	vector<Move> current_possible_moves;
	
	int _error_num = 0;
	
	void clearPossibleMoves();
};

