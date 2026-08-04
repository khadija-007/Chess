#include "Piece.h"
using namespace std;
Piece::Piece(bool st,bool alive, Position pos, Colour col)
{
	moved= st;
	Alive = alive;
	position = pos;
	colour = col;
}
Piece:: ~Piece(){}
bool Piece::isAlive() const
{
	return Alive;
}
bool Piece::hasMoved() const
{
	return moved;
}
Position Piece:: getPosition()
{
	return position;
}
void Piece::setPosition(const Position& rhs)
{
	position = rhs;
}
Colour Piece::getColour()const
{
	return colour;
}
void Piece:: setIsAlive(bool alive)
{
	Alive = alive;
}

