#pragma once
#include "Piece.h"
class Board;
class Knight : public Piece
{
public:
	Knight(bool move, bool alive, const Position& pos, Colour col) :Piece(move, alive, pos, col) {};
	bool isLegalMove(const Position& dest,Board&  board) override ;
	char getSymbol();
};