#include <Windows.h>

#include "Header.h"
#include "param.h"
#include "CursorPos.h"

int k, l;

void Anahori(void) {
	for (k = 0; k < WIDTH; k++) {
		for (l = 0; l < HIGHT; l++) {
			if (!(k == 0 || l == 0 || k == WIDTH - 1 || l == HIGHT - 1)) {
				mazepanel[k][l] = 1;
			}
		}
	}

	coordinate Mine(0, 0); //Œ@‚éêŠ
	
	//Œ@‚èŽn‚ß‚é‰ŠúˆÊ’uŒˆ‚ß
	do {
		Mine.x = rand() % (WIDTH - 1);
	} while (Mine.x % 2 == 0);
	do {
		Mine.y = rand() % (HIGHT - 1);
	} while (Mine.y % 2 == 0);

	bool canmine[4] = {true, true, true, true};//true:‚»‚Ì•ûŒü‚ÍŒ@‚é‚±‚Æ‚ª‚Å‚«‚é‚©‚à‚µ‚ê‚È‚¢

	while (MineLeaving()) {
		mazepanel[Mine.x][Mine.y] = 0;
		int c;
		switch (Direction()) {
		case 0:
			if (Mine.y - 2 > 0 && mazepanel[Mine.x][Mine.y - 2] != 0 && canmine[0] == true) {
				mazepanel[Mine.x][Mine.y - 1] = 0;
				Mine.y -= 2;
				for (c = 0; c < 4; c++) {
					canmine[c] = true;
				}
			}
			else {
				canmine[0] = false;
			}
			break;
		case 1:
			if (Mine.x - 2 > 0 && mazepanel[Mine.x - 2][Mine.y] != 0 && canmine[1] == true) {
				mazepanel[Mine.x - 1][Mine.y] = 0;
				Mine.x -= 2;
				for (c = 0; c < 4; c++) {
					canmine[c] = true;
				}
			}
			else {
				canmine[1] = false;
			}
			break;
		case 2:
			if (Mine.y + 2 < HIGHT - 1 && mazepanel[Mine.x][Mine.y + 2] != 0 && canmine[2] == true) {
				mazepanel[Mine.x][Mine.y + 1] = 0;
				Mine.y += 2;
				for (c = 0; c < 4; c++) {
					canmine[c] = true;
				}
			}
			else {
				canmine[2] = false;
			}
			break;
		case 3:
			if (Mine.x + 2 < WIDTH - 1 && mazepanel[Mine.x + 2][Mine.y] != 0 && canmine[3] == true) {
				mazepanel[Mine.x + 1][Mine.y] = 0;
				Mine.x += 2;
				for (c = 0; c < 4; c++) {
					canmine[c] = true;
				}
			}
			else {
				canmine[3] = false;
			}
			break;
		default:
			break;
		}
		if (!canmine[0] && !canmine[1] && !canmine[2] && !canmine[3]) {
			do {
				Mine.x = rand() % (WIDTH - 1);
				Mine.y = rand() % (HIGHT - 1);
			} while (Mine.x % 2 == 0 || Mine.y % 2 == 0 || mazepanel[Mine.x][Mine.y] == 1);
			for (c = 0; c < 4; c++) {
				canmine[c] = true;
			}
		}
	}

}

int Direction(void) {
	int temp;
	temp = rand() % 4;
	return temp;
}

bool MineLeaving(void) {
	int tx, ty, count;
	for (k = 1; k < WIDTH - 1; k++) {
		for (l = 1; l < HIGHT - 1; l++) {
			count = 0;
			for (tx = -1; tx <= 1; tx++) {
				for (ty = -1; ty <= 1; ty++) {
					if (mazepanel[tx + k][ty + l] == 1) count++;
				}
			}
			if (count >= SEARCHNUM) return true;
		}
	}
	return false;
}