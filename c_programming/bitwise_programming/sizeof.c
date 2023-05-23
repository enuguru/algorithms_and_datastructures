
#include <stdio.h>

int main()
{
	int count;
	unsigned int x = (unsigned int)~0;
	for(count = 1;(x=x>>1) > 0; count++)
		;
	printf("The size of the integer is %d bits or %d bytes\n",count,count/8);
	return 0;
}
