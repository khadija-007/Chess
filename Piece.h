#pragma once
#include "Position.h"
#include "Colour.h"
#include "Board.h"
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
	void setIsAlive(bool alive);
	bool hasMoved() const;
	void setHasMoved(bool m);
	Position getPosition();
	void setPosition(const Position& rhs);
	virtual bool isLegalMove(const Position& destination,Board & board) = 0;
	virtual char getSymbol() = 0;
	Colour getColour() const;
};