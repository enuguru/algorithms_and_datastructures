
#include <stdio.h>

void generate_perfect_numbers()
{
	int num, val, range, sum;
	printf("Give a number\n");
	scanf("%d",&range);
	for(num = 2; num < range; num++)
	{
		sum = 0;
		for(val=1; val < num; val++)
		{
			if(num%val == 0)
			{
				sum = sum + val; 
			}
		}
		if(sum == num)
			printf("%d ",num);
	}
}


int main()
{
	generate_perfect_numbers();
	return 0;
}
