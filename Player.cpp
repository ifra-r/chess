#include "Player.h"

Player::Player(string n, COLOR clr) {
	this->name = n;
	this->c = clr;
}

string Player::getName() {
	return this->name;
}