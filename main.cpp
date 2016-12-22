#include <cstdlib>
#include <iostream>
#include "Pipe.h"
#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Communication.h"
#include <vector>

int main(void)
{
	Board b(false);
	cout << Communication::getSquare("A8").getPiece().getChar() << endl;
	Pipe *pipe = new Pipe();
	pipe->connect();
	pipe->sendMessageToGraphics(Communication::parseBoard(&b));
	
	string msg = string("");
	while (msg != string("quit"))
	{
		system("cls");
		b.print();
		msg = pipe->getMessageFromGraphics();
		Square *src, *dst;
		try
		{
			src = &Communication::getSquare(msg.c_str());
			dst = &Communication::getSquare(msg.c_str() + 2);
		}
		catch (...)
		{
			pipe->sendMessageToGraphics("5");
			continue;
		}
		Move m = Move(src, dst);
		if (src == dst)							// Same source and destination squares
		{
			pipe->sendMessageToGraphics("7");
			continue;
		}		
		if (src->isEmpty())						// Source square is empty
		{
			pipe->sendMessageToGraphics("2");
			continue;
		}
												// Not the right player's turn
		if (src->getPiece().getPlayer() != b.getPlayer())
		{
			pipe->sendMessageToGraphics("2");
			continue;
		}
												// Destination has current player's piece on it
		if (!dst->isEmpty() && dst->getPiece().getPlayer() == src->getPiece().getPlayer())
		{
			pipe->sendMessageToGraphics("3");
			continue;
		}

		int __err__ = 0;
		vector<Move>& pm = *src->getPiece().getPossibleMoves();
		Piece* pc = &src->getPiece();
		for (int i = 0; i < pm.size(); i++)
		{
			cout << pm[i]._dst->str() << endl;
		}
		if (src->getPiece().isPossible(m))
		{
			b.move(m);
			for (int row = 0; row < 8; row++)
			{
				for (int col = 0; col < 8; col++)
				{
					if (pc->getSquare()(row, col).isEmpty()) continue;
					Piece *p = &pc->getSquare()(row, col).getPiece();
					if (p->getPlayer() == p->getPlayer())
					{
						p->getPossibleMoves();
						if (p->checks())
						{
							__err__ = 1;
						}
					}
				}
			}
			pipe->sendMessageToGraphics(__err__ == 0 ? "0" : "1");
			continue;
		}
		else
		{
			pipe->sendMessageToGraphics(src->getPiece().getError() == 4 ? "4" : "6");
			continue;
		}
	}

	system("pause");
	pipe->close();
	delete pipe;
	return 0;
}