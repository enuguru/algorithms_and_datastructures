
// how to compile - gcc externheader.h externone.c externtwo.c

#include "externheader.h"
#include <stdio.h>

int p = 10;

int main()
{
	void functiontwo();
	void newfunction();
	p = p + 10;
	printf("from main %d \n", p);
	newfunction();
	functiontwo();
	return 0;
}

void newfunction()
{
	printf("from newfunction %d \n", p);
}
