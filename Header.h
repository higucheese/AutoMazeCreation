#pragma once
#include <Windows.h>
#include "param.h"


/*�ϐ��錾*/
extern int i, j, k, l;
extern int mazepanel[WIDTH][HIGHT];
extern int searchpanel[WIDTH][HIGHT];
extern int mazevector[WIDTH][HIGHT];

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
int Direction(void); //0:UP 1:LEFT 2:DOWN 3:RIGHT
bool MineLeaving(void); //�@��c��������Ƃ�true��Ԃ�

/*freeflow*/
void FreeFlow(void);

/*���H�T��*/
bool Search(int x, int y);

/*�z����בւ�*/
void shuffle(int ary[], int size);

int WallCountUp(int, int); //���͂̕ǂ̐����J�E���g����