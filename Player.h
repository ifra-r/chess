#pragma once
#include <string>
#include "utility.h"
using namespace std;

class Player {
protected:
	string name;
	COLOR c;

public:
	Player(string n, COLOR clr);
	string getName();
};

