#include "Piece.h"
using namespace std;
Piece::Piece(bool st,bool alive, Position pos, Colour col)
{
	hasMoved = st;
	isAlive = alive;
	position = pos;
	colour = col;
}
Piece:: ~Piece(){}
bool Piece::getStatus() const
{
	return isAlive;
}
bool Piece::hasMov() const
{
	return hasMoved;
}
Position Piece:: getPosition()
{
	return position;
}
void Piece::setPosition(const Position& rhs)
{
	position = rhs;
}

