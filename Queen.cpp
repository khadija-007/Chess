#include <iostream>
#include "Queen.h"
#include "Board.h"

using namespace std;
bool Queen:: isLegalMove(const Position& dest, Board& board) 
{
	int rsteps;
	int csteps;
	Position pos = getPosition();
	int sourceR = pos.getRow();
	int sourceC = pos.getCol();
	int destR = dest.getRow();
	int destC = dest.getCol();
	Piece* oop = board.getPieceAt(dest);
	rsteps = abs(destR - sourceR);
	csteps = abs(destC - sourceC);
	int rowDirection = 0;
	int colDirection = 0;
	if (oop != nullptr && oop->getColour() == getColour())
	{
		return false;
	}
	if (csteps == 0 && rsteps == 0)
	{
		return false;
	}
	if (destR > sourceR)
	{
		rowDirection = +1;
	}
	else if(destR<sourceR)
	{
		rowDirection = -1;
	}
	if (destC < sourceC)
	{
		colDirection = -1;
	}
	else if(destC>sourceC)
	{
		colDirection = +1;
	}
	if (csteps==rsteps)
	{
		for (int i = 1; i < rsteps; i++)
		{
			if (!board.isEmpty(Position(sourceR + i * rowDirection, sourceC + i * colDirection)))
			{
				return false;
			}
		}
		return true;
	}
	if (csteps == 0)
	{
		for (int i = 1; i < rsteps; i++)
		{
			if (!board.isEmpty(Position(sourceR + i * rowDirection, sourceC)))
			{
				return false;
			}
		}
		return true;
	}
	else if(rsteps==0)
	{
		for (int i = 1; i < csteps; i++)
		{
			if (!board.isEmpty(Position(sourceR, sourceC + i * colDirection)))
			{
				return false;
			}
		}
		return true;
	}
	return false;
};
char Queen:: getSymbol()
{
	return 'Q';
};
