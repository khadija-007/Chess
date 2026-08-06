#include <iostream>
#include "Pawn.h"
#include "Board.h"
using namespace std;
bool Pawn:: isLegalMove(const Position& dest, Board& board) 
{
	int rsteps;
	int csteps;
	Position pos = getPosition();
	Position mid;
	int sourceR = pos.getRow();
	int sourceC = pos.getCol();
	int destR = dest.getRow();
	int destC = dest.getCol();
	Piece* oop = board.getPieceAt(dest);
	if (getColour() == Colour::White)
	{
		rsteps = destR - sourceR;
		mid.setPosition(sourceR + 1, sourceC);
	}
	else
	{
		rsteps = sourceR - destR;
		mid.setPosition(sourceR - 1, sourceC);
	}
	if (rsteps <= 0)
	{
		return false;
	}
	csteps = sourceC - destC;
	if (csteps < 0)
	{
		csteps = csteps * -1;
	}
	if (oop != nullptr)
	{
		if (oop->getColour() == getColour())
		{
			return false;
		}
		else
		{
			if (csteps != 1||rsteps!=1)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else //considering no piece present
	{
		if (sourceC != destC)
		{
			return false;
		}
		if (rsteps == 2 && !hasMoved())
		{
			if (board.isEmpty(mid))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (rsteps == 1)
		{
			return true;
		}
	}
	return false;
};
char Pawn:: getSymbol()
{
	return 'P';
};