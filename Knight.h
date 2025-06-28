#pragma once
#include "Piece.h"

class Piece;
class Board;

class Knight :
    public Piece {

public:
    Knight(int r, int c, COLOR clr, Board* _b);
    void print();
    bool Islegal(int sr, int sc, int er, int ec);
    char getMySym();

    Knight& operator=(const Knight& other);

};

