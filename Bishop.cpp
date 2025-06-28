#include "Bishop.h"
#include "utility.h"
#include <iostream>
using namespace std;

class Piece;

Bishop::Bishop(int r, int c, COLOR clr, Board* _b) :Piece{ r,c,clr,_b } {

}

void Bishop::print() {
	cout << ((this->c == BLACK) ? 'B' : 'b');
}

bool Bishop::Islegal(int sr, int sc, int er, int ec) {
	return isDiagonalMove(sr,sc,er,ec) && isDiagonalPathClear(sr,sc,er,ec);
}

char Bishop::getMySym() {
	if (c == BLACK) {
		return 'B';
	}
	else if (c == WHITE) {
		return 'b';
	}
	return '0';
}

