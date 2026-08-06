#pragma once
#include "Piece.h"
#include "Position.h"
class Board
{
private:
	Piece* pieces[32];
	Piece* board[8][8];
	void placePieceAt(Piece* piece, const Position& pos);
public:
	Board(); // places the pieces on the board initializes evrything
	~Board() ;
	Piece* getPieceAt(const Position& pos) const ;
	bool isEmpty(const Position& pos) const ;
	bool isOnBoard(const Position& pos) const ;
	bool movePiece(const Position& source, const Position& dest);
	void displayBoard() const;
};