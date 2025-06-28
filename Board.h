#pragma once
#include "Piece.h"
class Piece;
class Board {
protected:
	Piece* Ps[8][8];

public:
	Board();

	void initBoard();
	void displayBoard();

	Piece* getPiece(int row, int col);
	void setPiece(int r, int c, Piece* P);

	Piece*& operator()(int row, int col);

};
