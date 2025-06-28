#include "Knight.h"
#include "utility.h"
#include <iostream>
using namespace std;

class Piece;

Knight::Knight(int r, int c, COLOR clr, Board* _b) :Piece{ r,c,clr,_b } {

}

void Knight::print() {
	cout << ((this->c == BLACK) ? 'N' : 'n');
}

Knight& Knight::operator=(const Knight& other) {
    if (this != &other) {
        Piece::operator=(static_cast<const Piece&>(other)); // call base class assignment operator
    }
    return *this;
}


bool Knight::Islegal(int sr, int sc, int er, int ec) {
    int dr = abs (er - sr);
    int dc = abs (ec - sc);
    return (dr == 1 && dc == 2) || (dr == 2 && dc == 1);
}

char Knight::getMySym() {
	if (c == BLACK) {
		return 'N';
	}
	else if (c == WHITE) {
		return 'n';
	}
	return '0';
}