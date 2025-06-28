#pragma once
#include "Piece.h"

class Piece;
class Board;

class King :
    public Piece {

public:
    King(int r, int c, COLOR clr, Board* _b);
    void print();
    bool Islegal(int sr, int sc, int er, int ec);
    char getMySym();

    bool am_i_king();

};
