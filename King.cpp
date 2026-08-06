#include <iostream>
#include "King.h"
#include "Board.h"
using namespace std;
bool King:: isLegalMove(const Position& dest, Board& board) 
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
	if (oop != nullptr && oop->getColour() == getColour())
	{
		return false;
	}
	return (csteps == 1 && rsteps == 0) || (rsteps == 1 && csteps == 0) || (rsteps == 1 && csteps == 1);
};
char King:: getSymbol()
{
	return 'K';
};