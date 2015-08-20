#include <iostream>
#include <windows.h>
#include <time.h>

#include "Header.h"
#include "param.h"
#include "CursorPos.h"

using namespace std;

int i, j;
int mazepanel[WIDTH][HIGHT];
int searchpanel[WIDTH][HIGHT];
int mazevector[WIDTH][HIGHT];
coordinate Start(1, 1), Goal(WIDTH - 2, HIGHT - 2);

inline void InitRand();

int main(void) {
	while (1) {
		InitRand();

		/*****���H�쐬******/

		//�ǐ���
		for (i = 0; i < WIDTH; i++) {
			for (j = 0; j < HIGHT; j++) {
				if (i == 0 || j == 0 || i == WIDTH - 1 || j == HIGHT - 1) {
					mazepanel[i][j] = 1;
				}
				else {
					mazepanel[i][j] = 0;
				}
			}
		}
		/*freeflow*/
		if (!FreeFlow()) {
			continue;
		}

		/*
		���H��@
		for (i = 0; i < WIDTH; i++) {
			for (j = 0; j < HIGHT; j++) {
				searchpanel[i][j] = 0;
			}
		}
		Search(Start.x, Start.y); //������R�����g�A�E�g����Ɖ�@���\������Ȃ��Ȃ�
		*/

		/*****�\������*****/

		for (i = 0; i < WIDTH; i++) {
			for (j = 0; j < HIGHT; j++) {
				setCursorPos(2 * i, j);
				switch (mazepanel[i][j]) {
				case 1:
					cout << "��";
					break;
				case 2:
					cout << "�{";
					//cout << mazevector[i][j];
					break;
				default:
					break;
				}
				if (searchpanel[i][j] == 1) {
					setCursorPos(2 * i, j);
					cout << "��";
				}
			}
		}
		getchar();
		for (i = 0; i < WIDTH; i++) {
			for (j = 0; j < HIGHT; j++) {
				setCursorPos(2 * i, j);
				cout << "�@";
			}
		}
	}

	return 0;
}

inline void InitRand() {
	srand((unsigned int)time(NULL));
}

int WallCountUp(int x, int y) {
	int tx, ty, count = 0;
	for (tx = -1; tx <= 1; tx++) {
		for (ty = -1; ty <= 1; ty++) {
			if (mazepanel[tx + k][ty + l] == 1) count++;
		}
	}
	return count;
}