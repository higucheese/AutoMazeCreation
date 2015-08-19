#include "Header.h"
#include "param.h"

bool Search(int x, int y) {
	if (x == Goal.x && y == Goal.y) {
		mazepanel[x][y] = 2;
		return true;
	}
	
	searchpanel[x][y] = 1;

	if (mazepanel[x + 1][y] == 0 && searchpanel[x + 1][y] != 1) {
		if (Search(x + 1, y) == true) {
			mazepanel[x][y] = 2;
			return true;
		}
	}
	if (mazepanel[x][y + 1] == 0 && searchpanel[x][y + 1] != 1) {
		if (Search(x, y + 1) == true) {
			mazepanel[x][y] = 2;
			return true;
		}
	}
	if (mazepanel[x][y - 1] == 0 && searchpanel[x][y - 1] != 1) {
		if (Search(x, y - 1) == true) {
			mazepanel[x][y] = 2;
			return true;
		}
	}
	if (mazepanel[x - 1][y] == 0 && searchpanel[x - 1][y] != 1) {
		if (Search(x - 1, y) == true) {
			mazepanel[x][y] = 2;
			return true;
		}
	}
	return false;
}