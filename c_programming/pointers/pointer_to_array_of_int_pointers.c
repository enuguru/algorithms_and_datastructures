

#include <stdio.h>

int main()
{
	int x = 10;
	int y = 45;
	int z = 56;
	int *arrofintptrs[3] = { &x, &y, &z};
	int *(*aptr)[3] = &arrofintptrs;
	printf("%d %d %d ",*(*aptr)[0],*(*aptr)[1],*(*aptr)[2]);
}

