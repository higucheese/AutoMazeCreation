#pragma once
#include <Windows.h>
#include "param.h"


/*�ϐ��錾*/
extern int i, j;
extern int mazepanel[WIDTH][HIGHT];
extern int searchpanel[WIDTH][HIGHT];

/*�N���X*/
class coordinate {//���W�\��
public:
	int x = 0, y = 0;
	coordinate(int X, int Y) {
		if (x < WIDTH) x = X;
		if (y < HIGHT) y = Y;
	}
};

extern coordinate Start, Goal;

/*���@��@*/
void Anahori(void);

/*���H�T��*/
bool Search(int x, int y);