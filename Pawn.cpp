#include "Pawn.h"
#include "utility.h"
#include <iostream>
using namespace std;

class Piece;

Pawn::Pawn(int r, int c, COLOR clr, Board* _b) :Piece{ r,c,clr,_b }, firstMove(true){

}

void Pawn::print() {
	cout << ((this->c == BLACK) ? 'P' : 'p');
}

void Pawn::setFirstMove(bool isFmove) {
    firstMove = isFmove;
}

bool Pawn::Islegal(int sr, int sc, int er, int ec) {
    int dr = er - sr;
    int dc = ec - sc;
    int numOfMoves = (firstMove) ? 2 : 1;

    if (c == WHITE) {
        // one stepforward
        if (dr == -1 && dc == 0) {
            setFirstMove(false);
            return true;
        }
        // two step forward first move
        else if (dr == -2 && dc == 0 && sr == 6) {
            setFirstMove(false); 
            return true;
        }
        // Capturing diagonally
        else if (abs(dr) == 1 && abs(dc) == 1) {
            if (b->getPiece(er, ec) != nullptr && b->getPiece(er, ec)->getColor() != c) {
                return true;
            }
        }
        return false;
    }
    else if (c == BLACK) {
        if (dr == 1 && dc == 0) {
            setFirstMove(false); 
            return true;
        }
        else if (dr == 2 && dc == 0 && sr == 1) {
            setFirstMove(false); 
            return true;
        }
        else if (abs(dr) == 1 && abs(dc) == 1) {
            if (b->getPiece(er, ec) != nullptr && b->getPiece(er, ec)->getColor() != c) {
                return true;
            }
        }
        return false;
    }
    return false;
}



char Pawn::getMySym() {
	if (c == BLACK) {
		return 'P';
	} 
	else if (c == WHITE) {
		return 'p';
	}
	return '0';

}


























//bool Pawn::Islegal(int sr, int sc, int er, int ec) {
//	int numOfMoves = (firstMove) ? 2 : 1;
//	int dr = er - sr;
//	int dc = ec - sc;
//	if (dr == 1 && dc == 0) {
//		if (this->c == BLACK) {
//			if (er < sr) {
//				return false; 
//			}
//			return dr == 1 || dr == 2;
//		}
//		else if (this->c == WHITE) {
//			if (er > sr) {
//				return false;
//			}
//			return abs(dr) == numOfMoves;
//		}
//	}
//	else if ((abs(dr) == 1 && abs(dc) == 1)) {
//		if (b->getPiece(er, ec) != nullptr) {
//			if (b->getPiece(er, ec)->getColor() != c) {
//				return true;
//			}	
//		}
//	}
//	return false;
//}