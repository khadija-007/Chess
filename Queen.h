#pragma once
#include "Piece.h"
class Queen : public Piece
{
	Queen(bool move, bool alive, const Position& pos, Colour col) :Piece(move, alive, pos, col) {};
	bool isLegalMove(const Position& dest) override;
};