#include "Piece.h"
#include "Board.h"

//#include <iostream>
//#include <string>
//#include <time.h>

class Board;

Piece::Piece(int r, int c, COLOR clr, Board* _b) {
	this->pr = r;
	this->pc = c;
	this->c = clr;
	this->b = _b;
}

int Piece::getpr(){
    return pr;
}
int Piece::getpc(){
    return pc;
}
void Piece::setpr(int r){
    pr = r;
}
void Piece::setpc(int c) {
    pc = c;
}

void Piece::setCoord(int r, int c) {
    pr = r;
    pc = c;
}
COLOR Piece::getColor() const {
	return this->c;
}
Piece& Piece::operator=(const Piece& other) {
    if (this != &other) {
        this->pr = other.pr;
        this->pc = other.pc;
        this->c = other.c;
        this->b = other.b;
    }
    return *this;
}
bool Piece::isHorizontalMove(int sr, int er) {
    return  sr == er;
}
bool Piece::isVerticalMove(int sc, int  ec) {
    return sc == ec;
}
bool Piece::isDiagonalMove(int sr, int sc, int er, int  ec) {
    int dr = abs(er - sr);
    int dc = abs(ec - sc);
    return dr = dc;
}
bool Piece::isHorizPathClear(int sr, int sc, int er, int ec) {

    if (!isHorizontalMove(sr,er))
        return false;

    //if (ec > sc)   //----> movement
    //{
    //    for (int i = sc + 1; i < ec; i++) {
    //        if (b->getPiece(sr,i) != nullptr)
    //            return false;
    //    }
    //}
    //else {      // <---- movement
    //    for (int i = ec + 1; i < sc; i++) {
    //        if (b->getPiece(sr, i) != nullptr)
    //            return false;
    //    }
    //}
    int start = (ec > sc) ? sc + 1 : ec + 1;
    int end = (ec > sc) ? ec : sc;
    for (int i = start; i < end; i++) {
        if (b->getPiece(sr, i) != nullptr)
            return false;
    }
    return true;
}
bool Piece::isVerticalPathClear(int sr, int sc, int er, int ec) {
    if (!isVerticalMove(sc,ec))
        return false;
    int start = (er > sc) ? sr + 1 : er + 1;
    int end = (er > sc) ? er : sr;
    for (int r = start; r < end; r++) {
        if (b->getPiece(r, sc) != nullptr)
            return false;
    }
    return true;
}

bool Piece::am_i_king() {
    return false;
}

bool Piece::DPathClarity(int sr, int sc, int er, int ec) {
    int dr = er - sr;
    int dc = ec - sc;

    if (abs(dr) != abs(dc))
        return false;

    if (dr < 0 && dc > 0) {
        //i
        for (int i = 1; i < abs(dr); i++) {
            if (b->getPiece(sr - i, sc + i) != nullptr)
                return false;
        }
    }
    else if (dr < 0 && dc < 0) {
        //ii
        for (int i = 1; i < abs(dr); i++) {
            if (b->getPiece(sr - i, sc - i) != nullptr)
                return false;
        }
    }
    else if (dr > 0 && dc < 0) {
        //iii
        for (int i = 1; i < abs(dr); i++) {
            if (b->getPiece(sr + i, sc - i) != nullptr)
                return false;
        }
    }
    else if (dr > 0 && dc > 0) {
        //iv
        for (int i = 1; i < abs(dr); i++) {
            if (b->getPiece(sr + i, sc + i) != nullptr)
                return false;
        }
    }
    return true;
}

bool Piece::isDiagonalPathClear(int sr, int sc, int er, int ec) {
    return DPathClarity(sr, sc, er, ec);
}

//void Piece::highlight_DPC(int sr, int sc, bool HPs[][8]) {
//    for (int r = 0; r < 8; r++) {
//        for (int c = 0; c < 8; c++) {
//            if (HPs[r][c] == 1) {
//
//
//                if (b->getPiece(sr, sc) != nullptr && b->getPiece(sr, sc)->getColor() != b->getPiece(sr, sc)->getColor()) {
//                    if (DPathClarity(sr, sc, r, c))
//                        HPs[r][c] = 1;
//                    else
//                        HPs[r][c] = 0;
//                }
//            }
//        }
//    }
//}

//void Piece::highlight_Dmove(int sr, int sc, bool HPs[][8]) {
//    for (int r = 0; r < 8; r++) {
//        for (int c = 0; c < 8; c++) {
//            int dr = abs(r - sr);
//            int dc = abs(c - sc);
//            if (dr == dc)
//                HPs[r][c] = 1;
//            else
//                HPs[r][c] = 0;
//
//        }
//    }
//}
