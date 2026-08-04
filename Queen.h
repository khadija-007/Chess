#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(bool move, bool alive, const Position& pos, Colour col) :Piece(move, alive, pos, col) {};
	bool isLegalMove(const Position& dest,Board& board) override 
	{
		return true;
	};
	char getSymbol()
	{
		return 'Q';
	};

};