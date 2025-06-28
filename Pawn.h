#pragma once
#include "Piece.h"

class Piece;
class Board;

class Pawn :
    public Piece {

protected:
    bool firstMove = true;

public:
    Pawn(int r, int c, COLOR clr, Board* _b);
    void print();
    bool Islegal(int sr, int sc, int er, int ec);
    char getMySym();
    void setFirstMove(bool isFmove);

};

