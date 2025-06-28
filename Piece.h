#pragma once
#include "utility.h"
#include <cstdlib>
#include "Board.h"

class Board;

class Piece {

protected:
	int pr, pc;
	COLOR c;
	Board* b;

public:

	bool isHorizontalMove(int sr, int er);
	bool isVerticalMove(int sc, int  ec);
	bool isDiagonalMove(int sr, int sc, int er, int  ec);

	bool isHorizPathClear(int sr, int sc, int er, int ec);
	bool isVerticalPathClear(int sr, int sc, int er, int ec);
	bool isDiagonalPathClear(int sr, int sc, int er, int ec);


public:
	Piece(int r, int c, COLOR clr, Board* _b);

	virtual void print() = 0;
	virtual bool Islegal(int sr, int sc, int er, int ec) = 0;
	virtual char getMySym() = 0;
	virtual bool am_i_king();

	COLOR getColor() const;
	int getpr();
	int getpc();
	void setpr(int r);
	void setpc(int c);
	//move
	void setCoord(int r, int c);
	Piece& operator=(const Piece& other);




	//fazool funcs (not really)
	//void highlight_Dmove(int sr, int sc, bool HPs[][8]);
	//void highlight_DPC(int sr, int sc, bool HPs[][8]);
	bool DPathClarity(int sr, int sc, int er, int ec);


};

