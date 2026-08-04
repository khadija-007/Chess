#include <iostream>
#include "Board.h"
#include "Rook.h"
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"
#include "Colour.h"
using namespace std;
Board::Board()
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			board[r][c] = nullptr;
		}
	}
	for (int i = 0; i < 32; i++)
	{
		pieces[i] = nullptr;
	}
	Position pos(0, 0);
	pieces[0] = new Rook(false, true, pos, Colour::White);
	placePieceAt(pieces[0], pos);
	pos.setPosition(0, 1);
	pieces[1] = new Knight(false, true, pos, Colour::White);
	placePieceAt(pieces[1], pos);
	pos.setPosition(0, 2);
	pieces[2] = new Bishop(false, true, pos, Colour::White);
	placePieceAt(pieces[2], pos);
	pos.setPosition(0, 3);
	pieces[3] = new Queen(false, true, pos, Colour::White);
	placePieceAt(pieces[3], pos);
	pos.setPosition(0, 4);
	pieces[4] = new King(false, true, pos, Colour::White);
	placePieceAt(pieces[4], pos);
	pos.setPosition(0, 5);
	pieces[5] = new Bishop(false, true, pos, Colour::White);
	placePieceAt(pieces[5], pos);
	pos.setPosition(0, 6);
	pieces[6] = new Knight(false, true, pos, Colour::White);
	placePieceAt(pieces[6], pos);
	pos.setPosition(0, 7);
	pieces[7] = new Rook(false, true, pos, Colour::White);
	placePieceAt(pieces[7], pos);
	for (int i = 0; i < 8; i++)
	{
		pos.setPosition(1, i);
		pieces[i + 8] = new Pawn(false, true, pos, Colour::White);
		placePieceAt(pieces[i + 8], pos);
	}

	pos.setPosition(7, 0);
	pieces[16] = new Rook(false, true, pos, Colour::Black);
	placePieceAt(pieces[16], pos);
	pos.setPosition(7, 1);
	pieces[17] = new Knight(false, true, pos, Colour::Black);
	placePieceAt(pieces[17], pos);
	pos.setPosition(7, 2);
	pieces[18] = new Bishop(false, true, pos, Colour::Black);
	placePieceAt(pieces[18], pos);
	pos.setPosition(7, 3);
	pieces[19] = new Queen(false, true, pos, Colour::Black);
	placePieceAt(pieces[19], pos);
	pos.setPosition(7, 4);
	pieces[20] = new King(false, true, pos, Colour::Black);
	placePieceAt(pieces[20], pos);
	pos.setPosition(7, 5);
	pieces[21] = new Bishop(false, true, pos, Colour::Black);
	placePieceAt(pieces[21], pos);
	pos.setPosition(7, 6);
	pieces[22] = new Knight(false, true, pos, Colour::Black);
	placePieceAt(pieces[22], pos);
	pos.setPosition(7, 7);
	pieces[23] = new Rook(false, true, pos, Colour::Black);
	placePieceAt(pieces[23], pos);
	for (int i = 0; i < 8; i++)
	{
		pos.setPosition(6, i);
		pieces[i + 24] = new Pawn(false, true, pos, Colour::Black);
		placePieceAt(pieces[i + 24], pos);
	}

}

void Board::displayBoard() const
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == nullptr)
			{
				cout << "- ";
			}
			else
			{
				cout<<board[i][j]->getSymbol() << " ";
			}
		}
		cout << endl;
	}
}
void Board:: placePieceAt(Piece* piece,const Position& pos) 
{
	int c=pos.getCol();
	int r = pos.getRow();
	board[r][c] = piece;
};

Board::~Board()
{
	for (int i = 0; i < 32; i++)
	{
		delete pieces[i];
	}
}
Piece* Board::getPieceAt(const Position& pos) const
{
	int r = pos.getRow();
	int c = pos.getCol();
	return board[r][c];
}
bool Board::isEmpty(const Position& pos) const
{
	int r = pos.getRow();
	int c = pos.getCol();
	if (board[r][c] == nullptr)
	{
		return true;
	}
	return false;
}
bool Board::isOnBoard(const Position& pos) const
{
	int r = pos.getRow();
	int c = pos.getCol();
	if (r > 7 || r < 0)
	{
		return false;
	}
	if (c > 7 || c<0)
	{
		return false;
	}
	return true;
}
bool Board::movePiece(const Position& source, const Position& dest)
{
	if (isOnBoard(source)&&isOnBoard(dest) && !isEmpty(source) )
	{
		Piece* movingPiece = getPieceAt(source);
		Piece* destinationPiece = getPieceAt(dest);
		int r = dest.getRow();
		int c = dest.getCol();
		int oldr = source.getRow();
		int oldc = source.getCol();
		if (movingPiece->isLegalMove(dest,*this)) //have to pass board
		{
			if (destinationPiece!=nullptr)
			{
				destinationPiece->setIsAlive(false);
				destinationPiece->setPosition(Position(-1, -1));
			}
			board[r][c] = movingPiece;
			board[oldr][oldc] = nullptr;
			movingPiece->setPosition(dest);
			return true;
		}
	}
	return false;
}


int main()
{
	Board b;
	b.displayBoard();
	return 0;
}