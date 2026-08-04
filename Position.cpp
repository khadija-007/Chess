#include <iostream>
#include "Position.h"
using namespace std;
Position::Position()
{
	row = -1;
	col = -1;
}
Position::Position(int r, int c):row(r),col(c)
{
}
Position::Position(const Position& pos)
{
	row = pos.row;
	col = pos.col;
}
Position& Position:: operator=(const Position& rhs)
{
	if (this != &rhs)
	{
		row = rhs.row;
		col = rhs.col;
	}
	return *this;
}
int Position::getRow() const
{
	return row;
}
int Position::getCol() const
{
	return col;
}
void Position::setPosition(int i,int j)
{
	row = i;
	col = j;
}