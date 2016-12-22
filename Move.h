#pragma once
#include "Square.h"
class Square;

class Move
{
public:
	Move(Square *src, Square *dst);
	Move(int srow, int scol, int drow, int dcol);
	Move(int srow, int scol, Square *dst);
	Move(Square *src, int drow, int dcol);
	~Move();
	Square *_src, *_dst;
};

