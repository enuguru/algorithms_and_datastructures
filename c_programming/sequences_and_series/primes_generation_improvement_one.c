
#include <stdio.h>

void generate_primes()
{
	int num, flag, val, range;
	printf("Give a number\n");
	scanf("%d",&range);
	for(num = 2; num < range; num++)
	{
		flag = 0;
		for(val=2; val <= (int)num/2; val++)
		{
			if(num%val ==0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("%d ",num);
	}
}


int main()
{
	generate_primes();
	return 0;
}
