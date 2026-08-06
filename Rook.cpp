#include <iostream>
#include "Rook.h"
#include "Board.h"

using namespace std;
bool Rook:: isLegalMove(const Position& dest, Board& board) 
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
	int rowDirection=0;
	int colDirection=0;
	if (csteps != 0 && rsteps != 0)
	{
		return false;
	}
	if (csteps == 0 && rsteps == 0)
	{
		return false;
	}
	if (oop!=nullptr&&oop->getColour() == getColour())
	{
		return false;
	}
	if (csteps == 0)
	{
		if (sourceR < destR)
		{
			rowDirection = +1;
		}
		else
		{
			rowDirection = -1;
		}
		for (int i = 1; i < rsteps; i++)
		{
			if (!board.isEmpty(Position(sourceR + i * rowDirection, sourceC)))
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		if (sourceC < destC)
		{
			colDirection = +1;
		}
		else
		{
			colDirection = -1;
		}
		for (int i = 1; i < csteps; i++)
		{
			if (!board.isEmpty(Position(sourceR, sourceC + i * colDirection)))
			{
				return false;
			}
		}
		return true;
	}
	
};
char Rook:: getSymbol()
{
	return 'R';
};