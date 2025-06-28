#pragma once
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Board;
class Player;

class Chess {
	Player* players[2];
	Board* B;
	int turn;
	int sr = 0, sc = 0, er = 0, ec = 0;
	bool isWithinBounds(int r, int c);
public:
	Chess();
	void turnMsg(Player& player);
	void turnChange(int& turn);

	//bool isOwnPiece();
	bool isValidSourceSel();
	bool isValidDestSel();

	void updateBoard();
	void reflect_Changes();

	void play();

//private:
	bool HPs[8][8] = {};

private:
	void computeHighlight();
	void unHighlight();
	void highlight();

	void findKing(int& kr, int& kc);
	bool check();

	void game_loop();

	//fazool funcs to test
	void printHPs();
	


};

