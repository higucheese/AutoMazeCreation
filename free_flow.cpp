#include <Windows.h>

#include "Header.h"
#include "param.h"
#include "CursorPos.h"

int FlowDirection(int); //‘OX‰ñŒ@‚Á‚½•ûŒü‚Ì‹t•ûŒü‚ÍŒ@‚ç‚È‚¢‚æ‚¤‚É‚µ‚Ä‚¢‚é
bool BottiLeaving(void);
void BottiConnect(void); //ˆêƒ}ƒX‚¾‚¯c‚Á‚½‚Æ‚±‚ë‚ğ‰½‚Æ‚©‚·‚é
void DestMine(int, int, int, int);
coordinate Mine(0, 0); //Œ@‚éêŠ


void FreeFlow(void) {
	for (k = 0; k < WIDTH; k++) {
		for (l = 0; l < HIGHT; l++) {
			if (!(k == 0 || l == 0 || k == WIDTH - 1 || l == HIGHT - 1)) {
				mazepanel[k][l] = 1;
			}
		}
	}
	//Œ@‚èn‚ß‚é‰ŠúˆÊ’uŒˆ‚ß
	do {
		Mine.x = rand() % (WIDTH - 1);
	} while (Mine.x % 2 == 0);
	do {
		Mine.y = rand() % (HIGHT - 1);
	} while (Mine.y % 2 == 0);

	bool canmine[4] = { true, true, true, true };//true:‚»‚Ì•ûŒü‚ÍŒ@‚é‚±‚Æ‚ª‚Å‚«‚é‚©‚à‚µ‚ê‚È‚¢
	int onebeforedir = Direction(), twobeforedir = Direction(), forbiddendir;
	int c;
	while (MineLeaving()) {
		mazepanel[Mine.x][Mine.y] = 0;
		forbiddendir = (twobeforedir + 2) % 4;
		canmine[forbiddendir] = false;

		switch (FlowDirection(forbiddendir)) {
		case 0:
			if (Mine.y - 2 > 0 && mazepanel[Mine.x][Mine.y - 2] != 0 && canmine[0] == true) {
				mazepanel[Mine.x][Mine.y - 1] = 0;
				Mine.y -= 2;
				twobeforedir = onebeforedir;
				onebeforedir = 0;
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
				twobeforedir = onebeforedir;
				onebeforedir = 1;
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
				twobeforedir = onebeforedir;
				onebeforedir = 2;
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
				twobeforedir = onebeforedir;
				onebeforedir = 3;
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
			} while (Mine.x % 2 == 0 || Mine.y % 2 == 0 || mazepanel[Mine.x][Mine.y] == 0);
			for (c = 0; c < 4; c++) {
				canmine[c] = true;
			}
		}
	}
	/*while (BottiLeaving()) {
		BottiConnect();
	}*/
}

int FlowDirection(int forbiddendir) {
	int temp;
	do {
		temp = rand() % 4;
	} while (temp == forbiddendir);
	return temp;
}

bool BottiLeaving(void) {
	int bottipanel = 0;
	int tx, ty, count;
	for (k = 1; k < WIDTH - 1; k++) {
		for (l = 1; l < HIGHT - 1; l++) {
			searchpanel[k][l] = 0;
			count = 0;
			for (tx = -1; tx <= 1; tx++) {
				for (ty = -1; ty <= 1; ty++) {
					if (mazepanel[tx + k][ty + l] == 1) count++;
				}
			}
			if (count == 8) {
				searchpanel[k][l] = 1;
				bottipanel++;
			}
		}
	}
	if (bottipanel > 0) return true;
	else return false;
}

void BottiConnect(void) {
	for (k = 1; k < WIDTH - 1; k++) {
		for (l = 1; l < HIGHT - 1; l++) {
			if (searchpanel[k][l] == 1) {
				coordinate Dest(0, 0);
				do {
					Dest.x = rand() % (WIDTH - 1);
					Dest.y = rand() % (HIGHT - 1);
				} while (Dest.x % 2 == 0 || Dest.y % 2 == 0 || mazepanel[Dest.x][Dest.y] == 1);
				DestMine(k, l, Dest.x, Dest.y);
			}
		}
	}
}

void DestMine(int x1, int y1, int x2, int y2) {
	int t;
	int *p;
	int distx, disty, vx, vy, distance;
	if (x2 >= x1) {
		distx = x2 - x1;
		vx = 3;
	}
	else {
		distx = x1 - x2;
		vx = 1;
	}
	if (y2 >= y1) {
		disty = y2 - y1;
		vy = 2;
	}
	else {
		disty = y1 - y2;
		vy = 0;
	}
	distx /= 2;
	disty /= 2;
	distance = distx + disty;
	p = new int[distance];
	if (p == NULL) return;
	for (t = 0; t < distance; t++) {
		if (t < distx) {
			p[t] = vx;
		}
		else {
			p[t] = vy;
		}
	}

	shuffle(p, distance);

	coordinate MineTemp(x1, y1);

	for (t = 0; t < distance; t++) {
		int q, r;
		switch (p[t]) {
		case 0:
			for (q = 1; q <= 3; q++) {
				for (r = -1; r <= 1; r += 2) {
					if (q < 3) {
						mazepanel[MineTemp.x][MineTemp.y - q] = 0;
					}
					else {
						mazepanel[MineTemp.x][MineTemp.y - q] = 1;
					}
					mazepanel[MineTemp.x + r][MineTemp.y - q] = 1;
				}
			}
			MineTemp.y -= 2;
			break;
		case 1:
			for (q = 1; q <= 3; q++) {
				for (r = -1; r <= 1; r += 2) {
					if (q < 3) {
						mazepanel[MineTemp.x - q][MineTemp.y] = 0;
					}
					else {
						mazepanel[MineTemp.x - q][MineTemp.y] = 1;
					}
					mazepanel[MineTemp.x - q][MineTemp.y + r] = 1;
				}
			}
			MineTemp.x -= 2;
			break;
		case 2:
			for (q = 1; q <= 3; q++) {
				for (r = -1; r <= 1; r += 2) {
					if (q < 3) {
						mazepanel[MineTemp.x][MineTemp.y + q] = 0;
					}
					else {
						mazepanel[MineTemp.x][MineTemp.y + q] = 1;
					}
					mazepanel[MineTemp.x + r][MineTemp.y + q] = 1;
				}
			}
			MineTemp.y += 2;
			break;
		case 3:
			for (q = 1; q <= 3; q++) {
				for (r = -1; r <= 1; r += 2) {
					if (q < 3) {
						mazepanel[MineTemp.x + q][MineTemp.y] = 0;
					}
					else {
						mazepanel[MineTemp.x + q][MineTemp.y] = 1;
					}
					mazepanel[MineTemp.x + q][MineTemp.y + r] = 1;
				}
			}
			MineTemp.x += 2;
			break;
		default:
			break;
		}
	}
	delete[] p;
}