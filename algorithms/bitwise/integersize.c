
#include <stdio.h>
int main()
{
	unsigned int z = (unsigned int) ~0;
	int count;
	for(count=0; z > 0; count++)
        	z=z>>1;
	printf("The size of integer is %d\n",count);
	return 0;
}
