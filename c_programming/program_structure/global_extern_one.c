
#include <stdio.h>
//#include "global_extern_two.c"

static int x = 90;

void newfuncone()
{
	x = x + 20;
}

int main()
{
	void newfuncone();
	void newfunctwo();
	x = x + 10;
	printf("The value of x is %d \n",x);
	newfuncone();
	newfunctwo();
	printf("The value of x is %d \n",x);
	return 0;
}
