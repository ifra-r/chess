#include <iostream>

#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"



using namespace std;

Board::Board() {
	initBoard();
}

void Board::initBoard() {
	for (int r = 0; r < 8; r++) {

		for (int c = 0; c < 8; c++) {

			if (r == 1)
				Ps[r][c] = new Pawn(r, c, BLACK, this);
			else if (r == 6)
				Ps[r][c] = new Pawn(r, c, WHITE, this);

			else if ((r == 0 && (c == 0 || c == 7)))
				Ps[r][c] = new Rook(r, c, BLACK, this);
			else if ((r == 7 && (c == 0 || c == 7)))
				Ps[r][c] = new Rook(r, c, WHITE, this);

			else if ((r == 0 && (c == 1 || c == 6)))
				Ps[r][c] = new Knight(r, c, BLACK, this);
			else if ((r == 7 && (c == 1 || c == 6)))
				Ps[r][c] = new Knight(r, c, WHITE, this);

			else if ((r == 0 && (c == 2 || c == 5)))
				Ps[r][c] = new Bishop(r, c, BLACK, this);
			else if ((r == 7 && (c == 2 || c == 5)))
				Ps[r][c] = new Bishop(r, c, WHITE, this);

			else if (r == 0 && c == 3)
				Ps[r][c] = new Queen(r, c, BLACK, this);
			else if (r == 7 && c == 3)
				Ps[r][c] = new Queen(r, c, WHITE, this);

			else if (r == 0 && c == 4)
				Ps[r][c] = new King(r, c, BLACK, this);
			else if (r == 7 && c == 4)
				Ps[r][c] = new King(r, c, WHITE, this);
			else
				Ps[r][c] = nullptr;
		}
	}
}

void Board::displayBoard() {
	setClr(7, 0);
	system("cls");
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (Ps[r][c] == nullptr) {
				cout << "-";
			}
			else {
				Ps[r][c]->print();
			}
		}
		cout << endl;
	}

	gotoxy(96, 0);
	cout << "--error message--";
}

Piece* Board::getPiece(int row, int col) {
	if (row >= 0 && row < 8 && col >= 0 && col < 8) {
		return Ps[row][col];
	}
	else {
		return nullptr;
	}
}


void Board::setPiece(int row, int col, Piece* P) {
	if (row >= 0 && row < 8 && col >= 0 && col < 8) {
		Ps[row][col] = P;
	}
	else {
		cout << "setPiece--- out of bounds";
		return;
	}
}

Piece*& Board::operator()(int row, int col) {
	return this->Ps[row][col];
}