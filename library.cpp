#include<stdlib.h>
#include "Header.h"

void shuffle(int ary[], int size)
{
	for (int i = 0; i<size; i++)
	{
		int j = rand() % size;
		int t = ary[i];
		ary[i] = ary[j];
		ary[j] = t;
	}
}