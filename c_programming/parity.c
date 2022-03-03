
# include "stdio.h"

int count_bits(int x)
{
	int numbits = 0;
	while(x != 0)
	{
		numbits = numbits + (x & 1);
		x = x >> 1;
	}
	return numbits;
}


int main()
{

	int p = 23;
	int q = count_bits(p);
	printf("%d\n",q);
	return 0;
}
