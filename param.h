#pragma once

const int WIDTH = 75;//Šï”‚É‚·‚é‚±‚Æ
const int HIGHT = 25;//Šï”‚É‚·‚é‚±‚Æ

class coordinate {
public:
	int x, y;
	coordinate(int X, int Y) {
		if (x < CONS_Width) x = X;
		if (y < CONS_Hight) y = Y;
	}
};

//F’è‹`
#define COL_BLACK 0x00
#define COL_BLUE 0x09
#define COL_GREEN 0x0a
#define COL_CYAN 0x0b
#define COL_RED 0x0c
#define COL_VIOLET 0x0d
#define COL_YELLOW 0x0e
#define COL_WHITE 0x0f
#define COL_INTENSITY 0x08
#define COL_RED_MASK 0x04
#define COL_GREEN_MASK 0x02
#define COL_BLUE_MASK 0x01