#include <time.h>
#include <string>
#include <iostream>
#include <Windows.h>

#include "Chess.h"
#include "Player.h"
#include "Board.h"

#include "Utility.h"
using namespace std;

class Board;
class Player;

string Player1Name = "jessie";
string Player2Name = "elliot";


void anyErrMsg() {
	gotoxy(0,94);
	setClr(4, 0);
}

Chess::Chess() {

	players[0] = new Player(Player1Name, BLACK);
	players[1] = new Player(Player2Name, WHITE);

	B = new Board();
	srand(time(0));
	turn = rand() % 2;
}

void Chess::turnMsg(Player& player) {
	gotoxy(0, 10);	setClr(7, 0);
	cout << "--" << player.getName() << "'s turn--";
}

void Chess::turnChange(int& turn) {
	if (turn == 0) {
		turn = 1;
		return;
	}
	else if(turn == 1){
		turn = 0;
		return;
	}
	else {
		gotoxy(96, 2); 	setClr(7, 0);
		cout << "turn change error";
		return;
	}
}


bool Chess::isValidSourceSel() {

	//check bounds
	if (!isWithinBounds(sr,sc)) {
		//anyErrMsg();
		gotoxy(96, 2); 	setClr(7, 0);
		cout << "out of bounds";
		return false;
	}

	//check if player selected own piece to move	// should be own piece
	Piece* selectedPiece = B->getPiece(sr, sc);
	if (selectedPiece == nullptr) {
		gotoxy(96, 2); 	setClr(7, 0);
		cout << "No piece selected";
		return false;
	}
	else {
		if (static_cast<COLOR>(turn) != selectedPiece->getColor()) {
			gotoxy(96, 2); 	setClr(7, 0);
			cout << "not player's piece";
			return false;
		}
	}
	return true;
}

bool Chess::isWithinBounds(int r, int c) {
	//check bounds
	if (!(r >= 0 && r <= 7)) {
		gotoxy(96, 2); 	setClr(7, 0);
		cout << "row out of bounds";
		return false;
	}
	if (!(c >= 0 && c <= 7)) {
		gotoxy(96, 2); 	setClr(7, 0);
		cout << "col out of bounds";
		return false;
	}
	return true;
}

bool Chess::isValidDestSel() {

	//bound check
	if (!isWithinBounds(er, ec)) {
		return false;
	}

	Piece* selectedPiece = B->getPiece(er, ec);
	//empty space is fine too
	if (selectedPiece == nullptr) {
		return true;
	}
	//own piece? shouldnt be!

	if (static_cast<COLOR>(turn) == selectedPiece->getColor()) {
		gotoxy(96, 2); 	setClr(7, 0);
		cout << "own piece alreay here";
		return false;
	}
	return true;
}

void Chess::updateBoard() {
	Piece* sourcePiece = B->getPiece(sr, sc);
	B->setPiece(er, ec, sourcePiece);			//assigning pointer
	B->getPiece(er, ec)->setCoord(er, ec);		//updating coord of that obj OR move()
	B->setPiece(sr, sc, nullptr);				//nullptr at  source loc, not really any need to update coord, they will be updated if  a piece moves here
}

void Chess::reflect_Changes() {
	//dest is at er,ec now
	gotoxy(ec, er);			//	gotoxy(er, ec); OLD 
	B->getPiece(er,ec)->print();
	//nullptr at src, board been already updated
	gotoxy(sc, sr);			// 	gotoxy(sr, sc);
	cout << "-";

	//gotoxy(er, ec);
	//B->getPiece(sr,sc)->print();
	//gotoxy(sr, sc);
	//cout << "-";
}


void Chess::computeHighlight() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (B->getPiece(i, j) != nullptr) {
				if (B->getPiece(i, j)->getColor() != static_cast<COLOR>(turn)) {
					if (B->getPiece(sr, sc)->Islegal(sr, sc, i, j))
						HPs[i][j] = 1;
					else
						HPs[i][j] = 0;
				}
				else
					HPs[i][j] = 0;
			}
			else {
				if (B->getPiece(sr, sc)->Islegal(sr, sc, i, j))
					HPs[i][j] = 1;
				else
					HPs[i][j] = 0;
			}
		}
	}
}

void Chess::unHighlight() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			HPs[i][j] = 0;
		}
	}
	B->displayBoard();	
}

void Chess::highlight() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (HPs[i][j] == 1) {
				gotoxy(j, i);
				setClr(11, 0);
				cout << "X";
			}
		}
	}
	setClr(11, 0);
}

void Chess::printHPs() {
	setClr(7, 0);
	gotoxy(0, 14);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			cout << HPs[i][j]; // << " ";
		cout << endl;
	}
}

void Chess::findKing(int& kr, int& kc) {
	kr = 0, kc = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (B->getPiece(sr, sc) != nullptr) {
				if (B->getPiece(sr, sc)->getColor() != B->getPiece(i, j)->getColor()) {
					if (B->getPiece(i, j)->am_i_king()) {			// (B->getPiece(i, j)->getMySym() == 'K' || B->getPiece(i, j)->getMySym() == 'k') 
						kr = i, kc = j;
						return;
					}
				}
			}
		}
	}
}

bool Chess::check() {
	int kr = 0, kc = 0;
	int tempTurn = turn;
	turnChange(tempTurn);
	findKing(kr, kc);
	turnChange(tempTurn);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (B->getPiece(i, j) != nullptr) {
				if (B->getPiece(i, j)->getColor() != B->getPiece(i, j)->getColor()) {
					if (B->getPiece(i, j)->Islegal(i, j, kr, kc))
						return true;
				}
			}
		}
	}
	return false;
}

//int a = 0, b = 0;
//getRowColbyLeftClick(a, b);
//cout << a << "," << b << endl;
//gotoxy(b, a);
//cout << "ello there mate";

void Chess::game_loop() {
	do {
		do {
			do {
				do {
					getRowColbyLeftClick(sr, sc);
				} while (!isValidSourceSel());
				gotoxy(38, 0); 	setClr(7, 0);
				cout << "Src selected " << sr << "," << sc << endl;
				computeHighlight();
				highlight();
				printHPs();

				getRowColbyLeftClick(er, ec);
				unHighlight();
			} while (!isValidDestSel());

			gotoxy(38, 0); 	setClr(7, 0);
			cout << "Dest selected" << er << "," << ec << endl;

		} while (!(B->getPiece(sr, sc)->Islegal(sr, sc, er, ec)));
	
		updateBoard();
		B->displayBoard();
		turnChange(turn);
	} while (1);
}

void Chess::play() {
	B->initBoard();
	B->displayBoard();
	turnMsg(*players[turn]);
	game_loop();

}


//void allMovementChecks() {
//	for (int i = 0; i < 8; i++) {
//							for (int j = 0; j < 8; j++) {
//								if (B->getPiece(i, j) != nullptr) {
//									if (B->getPiece(i, j)->getColor() != static_cast<COLOR>(turn)) {
//										if (B->getPiece(sr, sc)->DPathClarity(sr, sc, i, j) || B->getPiece(sr, sc)->isDiagonalMove(sr, sc, er, ec) ||
//											((B->getPiece(sr, sc)->isHorizontalMove(sr, er) && B->getPiece(sr, sc)->isHorizPathClear(sr, sc, i, j))
//												|| (B->getPiece(sr, sc)->isVerticalMove(sc, ec) && B->getPiece(sr, sc)->isVerticalPathClear(sr, sc, i, j))))
//											HPs[i][j] = 1;
//										else
//											HPs[i][j] = 0;
//									}
//									else
//										HPs[i][j] = 0;
//								}
//								else {
//									if (B->getPiece(sr, sc)->DPathClarity(sr, sc, i, j) || B->getPiece(sr, sc)->isDiagonalMove(sr, sc, er, ec) ||
//										((B->getPiece(sr, sc)->isHorizontalMove(sr, er) && B->getPiece(sr, sc)->isHorizPathClear(sr, sc, er, sc))
//										|| (B->getPiece(sr, sc)->isVerticalMove(sc, ec) && B->getPiece(sr, sc)->isVerticalPathClear(sr, sc, er, sc))))
//										HPs[i][j] = 1;
//									else
//										HPs[i][j] = 0;
//								}
//							}
//						}
//
//
//
//}