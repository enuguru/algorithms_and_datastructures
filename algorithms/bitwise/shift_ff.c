

#include <stdio.h>

int main()
{
	unsigned int x = (unsigned int)~0;
	x = x >> 1;
	printf("The value of x is %d\n",x);
}
