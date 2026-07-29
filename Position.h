#pragma once
class Position
{
private:
	int row;
	int col;
public:
	Position();
	Position(int r, int c);
	Position (const Position& pos);
	Position &operator=(const Position& pos);
	int getRow();
	int getCol();
};