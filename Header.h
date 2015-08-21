#pragma once
#include <Windows.h>
#include "param.h"


/*変数宣言*/
extern int i, j, k, l;
extern int mazepanel[WIDTH][HIGHT];
extern int searchpanel[WIDTH][HIGHT];
extern int mazevector[WIDTH][HIGHT];

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
int Direction(void); //0:UP 1:LEFT 2:DOWN 3:RIGHT
bool MineLeaving(void); //掘り残しがあるときtrueを返す

/*freeflow*/
void FreeFlow(void);

/*迷路探索*/
bool Search(int x, int y);

/*配列並べ替え*/
void shuffle(int ary[], int size);

int WallCountUp(int, int); //周囲の壁の数をカウントする