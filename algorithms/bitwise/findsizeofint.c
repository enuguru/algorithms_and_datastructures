

#include <stdio.h>

int findintsize()
{
	int count;
	int v = ~0;
	printf("%0x",v);
	for(count = 1; ((v=v>>1) > 0); count = count +1,printf("%d",count));
	return count;
}


int main()
{
	int sizeofint;
	sizeofint = findintsize();
	printf("The size of the integer is %d \n",sizeofint);
	return 0;
}
