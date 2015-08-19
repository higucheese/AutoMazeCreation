#include <iostream>
#include <windows.h>

#include "param.h"

using namespace std;

int i, j;
int mazepanel[WIDTH][HIGHT];
coordinate Start(1, 1), Goal(WIDTH - 2, HIGHT - 2);

int main(void) {
	
	/*****ñ¿òHçÏê¨******/

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

	/*****ï\é¶ïîï™*****/


	return 0;
}