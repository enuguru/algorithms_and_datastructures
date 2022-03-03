
#include <stdio.h>

int myprint(int num)
{
	int x = 5;
	num = num + x;
	return num;
}

int main()
{
int q;
int m;
scanf("%d",&q);
m = myprint(q);
printf("%d\n",m);
}
