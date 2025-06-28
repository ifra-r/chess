#include "Rook.h"
#include "utility.h"
#include <iostream>
using namespace std;

class Piece;

Rook::Rook(int r, int c, COLOR clr, Board* _b) :Piece{ r,c,clr,_b } {

}

void Rook::print() {
	cout << ((this->c == BLACK) ? 'R' : 'r');
}

Rook& Rook::operator=(const Rook& other) {
    if (this != &other) {
        Piece::operator=(static_cast<const Piece&>(other)); // call base class assignment operator
    }
    return *this;
}

bool Rook::Islegal(int sr, int sc, int er, int ec) {
	bool isH = (isHorizontalMove(sr, er) && isHorizPathClear(sr, sc, er, ec));
	bool isV = (isVerticalMove(sc, ec) && isVerticalPathClear(sr, sc, er, ec));
	return isH || isV;
}

char Rook::getMySym() {
	if (c == BLACK) {
		return 'R';
	}
	else if (c == WHITE) {
		return 'r';
	}
	return '0';
}
