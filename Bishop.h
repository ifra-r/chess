#pragma once
#include "Piece.h"

class Piece;
class Board;

class Bishop :
    public Piece {

public:
    Bishop(int r, int c, COLOR clr, Board* _b);
    void print();
    bool Islegal(int sr, int sc, int er, int ec);
    char getMySym();
};