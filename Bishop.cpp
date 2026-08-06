#include <iostream>
#include "Bishop.h"
#include "Board.h"
#include <cmath>
using namespace std;
bool Bishop:: isLegalMove(const Position& dest, Board& board) 
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
	int rowDirection;
	int colDirection;
	if (rsteps == 0)
	{
		return false;
	}
	if (rsteps != csteps)
	{
		return false;
	}
	if (oop!=nullptr&&oop->getColour() == getColour())
	{
		return false;
	}
	if (destR>sourceR) 
	{
		rowDirection = +1;
	}
	else
	{
		rowDirection = -1;
	}
	if (destC < sourceC) 
	{
		colDirection = -1;
	}
	else 
	{
		colDirection = +1;
	}
	for (int i = 1; i < rsteps; i++)
	{
		if (!board.isEmpty(Position(sourceR + i*rowDirection, sourceC + i*colDirection)))
		{
			return false;
		}
	}
	return true;
};
char Bishop:: getSymbol()
{
	return 'B';
};