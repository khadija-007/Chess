#pragma once
#include "Position.h"
#include "Colour.h"
class Piece
{
private:
	bool moved;
	bool Alive;
	Position position;
	Colour colour;
public:
	Piece(bool mov,bool alive, Position pos,Colour col);
	virtual ~Piece();
	bool isAlive() const;
	bool hasMoved() const;
	Position getPosition();
	void setPosition(const Position& rhs);
	virtual bool isLegalMove() = 0;
};