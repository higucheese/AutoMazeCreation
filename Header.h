#pragma once
#include <Windows.h>
#include "param.h"


/*変数宣言*/
extern int i, j;
extern int mazepanel[WIDTH][HIGHT];
extern int searchpanel[WIDTH][HIGHT];

/*クラス*/
class coordinate {//座標表示
public:
	int x = 0, y = 0;
	coordinate(int X, int Y) {
		if (x < WIDTH) x = X;
		if (y < HIGHT) y = Y;
	}
};

extern coordinate Start, Goal;

/*穴掘り法*/
void Anahori(void);

/*迷路探索*/
bool Search(int x, int y);