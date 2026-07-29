#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(bool move, bool alive, const Position& pos, Colour col) :Piece(move, alive, pos, col) {};
	bool isLegalMove(const Position& dest) override;
};