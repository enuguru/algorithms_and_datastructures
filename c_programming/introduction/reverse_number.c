
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
	long int number;
	long int rever_number = 0;
	int remainder;
	bool isNegative = false;

	printf("Give a number  ");
	scanf("%d",&number);
	int value = number;

	if(number > INT_MAX || number < INT_MIN)
	{	
		printf("The given number %d is either too big or too small \n",number);
		return 0;
	}

	if(number < 0)
	{
		number = number * -1;
		isNegative = true;
	}

	while(number != 0)
	{
		remainder = number % 10;
		rever_number = rever_number * 10  +  remainder;
		number = number / 10;
	}

	if(isNegative)
		rever_number = rever_number * -1;

	printf("The given number is %d  \n",value);
	printf("The reversed number is %d  \n",rever_number);

	return 0;
}
