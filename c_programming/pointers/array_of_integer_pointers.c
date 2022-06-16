

#include <stdio.h>

int main()
{
	int x = 10;
	int y = 45;
	int z = 56;
	int *arrofintptrs[3] = { &x, &y, &z};
	printf("%d %d %d ",*arrofintptrs[0],*arrofintptrs[1],*arrofintptrs[2]);
}

