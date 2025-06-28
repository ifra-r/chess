#include "Queen.h"
#include "utility.h"
#include "Rook.h"
#include "Bishop.h"
#include <iostream>
using namespace std;

class Piece;

Queen::Queen(int r, int c, COLOR clr, Board* _b) :Piece{ r,c,clr,_b } {

}

void Queen::print() {
	cout << ((this->c == BLACK) ? 'Q' : 'q');
}

bool Queen::Islegal(int sr, int sc, int er, int ec) {
	
	//Rook rook(pr, pc, getColor(), b);
	//Bishop bishop(pr, pc, getColor(), b);
	//bool bLegal = bishop.Islegal(sr, sc, er, ec);
	//bool rLegal = rook.Islegal(sr, sc, er, sc);
	bool isH = (isHorizontalMove(sr, er) && isHorizPathClear(sr, sc, er, ec));
	bool isV = (isVerticalMove(sc, ec) && isVerticalPathClear(sr, sc, er, ec));
	bool isD = isDiagonalMove(sr, sc, er, sc) && isDiagonalPathClear(sr, sc, er, ec);
	return isH || isV || isD;
}

char Queen::getMySym() {
	if (c == BLACK) {
		return 'Q';
	}
	else if (c == WHITE) {
		return 'q';
	}
	return '0';
}