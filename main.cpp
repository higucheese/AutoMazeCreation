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
coordinate Start(1, 1), Goal(WIDTH - 2, HIGHT - 2);

inline void InitRand();

int main(void) {

	InitRand();
	
	/*****ñ¿òHçÏê¨******/

	//ï«ê∂ê¨
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

	/*åäå@ÇËñ@*/
	Anahori();

	/*ñ¿òHâñ@*/
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HIGHT; j++) {
			searchpanel[i][j] = 0;
		}
	}
	Search(Start.x, Start.y);

	/*****ï\é¶ïîï™*****/
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HIGHT; j++) {
			setCursorPos(i, j);
			switch (mazepanel[i][j]) {
			case 1:
				cout << "#";
				break;
			case 2:
				cout << "+";
				break;
			default:
				break;
			}
			if (i == Start.x && j == Start.y) {
				setCursorPos(i, j);
				cout << "S";
			}
			if (i == Goal.x && j == Goal.y) {
				setCursorPos(i, j);
				cout << "G";
			}
		}
	}

	getchar();
	return 0;
}

inline void InitRand() {
	srand((unsigned int)time(NULL));
}