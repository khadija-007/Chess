#include <iostream>
#include "Knight.h"
#include "Board.h"
using namespace std;
bool Knight:: isLegalMove(const Position& dest, Board& board) 
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
	if (oop!=nullptr&&oop->getColour() == getColour())
	{
		return false;
	}
	if (csteps == 2 && rsteps == 1)
	{
		return true;
	}
	if (csteps == 1 && rsteps == 2)
	{
		return true;
	}
	return false;
};
char Knight:: getSymbol()
{
	return 'N';
};