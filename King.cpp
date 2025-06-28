#include "King.h"
#include "utility.h"
#include "Queen.h"
#include <iostream>
using namespace std;

class Piece;

King::King(int r, int c, COLOR clr, Board* _b) :Piece{ r,c,clr,_b } {

}

void King::print() {
	cout << ((this->c == BLACK) ? 'K' : 'k');
}


bool King::Islegal(int sr, int sc, int er, int ec) {
	int dc = abs(ec - sc);
	int dr = abs(er - sr);
	if (dr <= 1 && dc <= 1) {
		/*Queen q(pr, pc, getColor(), b);
		return q.Islegal(sr, sc, er, ec);*/
		bool isH = (isHorizontalMove(sr, er) && isHorizPathClear(sr, sc, er, ec));
		bool isV = (isVerticalMove(sc, ec) && isVerticalPathClear(sr, sc, er, ec));
		bool isD = isDiagonalMove(sr, sc, er, sc) && isDiagonalPathClear(sr, sc, er, ec);
		return isH || isV || isD; 
	}
	return 0;
}

char King::getMySym() {
	if (c == BLACK) {
		return 'K';
	}
	else if (c == WHITE) {
		return 'k';
	}
	return '0';
}

bool King::am_i_king() {
	return true;
}