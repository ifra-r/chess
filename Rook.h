#pragma once
#include "Piece.h"

class Piece;
class Board;

class Rook :
    public Piece {

public:
    Rook(int r, int c, COLOR clr, Board* _b);
    void print();
    bool Islegal(int sr, int sc, int er, int ec);
    char getMySym();
    Rook& operator=(const Rook& other);
};

