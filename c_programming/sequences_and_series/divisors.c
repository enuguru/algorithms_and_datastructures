
#include <stdio.h>

void generate_divisors()
{
	int num, flag, val, number;
	printf("Give a number\n");
	scanf("%d",&number);
		for(val=1; val <= number; val++)
		{
			if(number%val ==0)
			{
				printf("%d ",val);
			}
		}
}


int main()
{
	generate_divisors();
	return 0;
}
