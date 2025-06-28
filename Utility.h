#pragma once

#define blue 1
#define green 2
#define red 4
#define purple 5
#define yellow 6
#define gray 8
#define lblue 9
#define lgreen 10
#define laqua 11
#define lred 12
#define lpurple 13
#define lyellow 14
#define bwhite 15
#define White 7
#define Black 0

void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoxy(int x, int y);
void setClr(int tcl, int bcl);
enum COLOR { BLACK, WHITE };

