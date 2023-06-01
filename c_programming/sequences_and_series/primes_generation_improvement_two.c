
#include <stdio.h>
#include <math.h>

void generate_primes()
{
	int num, flag, val, range;
	printf("Give a number\n\n");
	scanf("%d",&range);
	for(num = 2; num < range; num++)
	{
		flag = 0;
		for(val=2; val <= sqrt(num); val++)
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
