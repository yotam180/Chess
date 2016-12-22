#include "Move.h"



Move::Move(Square * src, Square * dst)
{
	_src = src;
	_dst = dst;
}

Move::Move(int srow, int scol, int drow, int dcol)
{
	_src = &Board::getMainBoard()(srow, scol);
	_dst = &Board::getMainBoard()(drow, dcol);
}

Move::Move(int srow, int scol, Square * dst)
{
	_src = &Board::getMainBoard()(srow, scol);
	_dst = dst;
}

Move::Move(Square * src, int drow, int dcol)
{
	_src = src;
	_dst = &Board::getMainBoard()(drow, dcol);
}

Move::~Move()
{
}
