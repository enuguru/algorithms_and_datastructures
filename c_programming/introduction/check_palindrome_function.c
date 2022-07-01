
#include <stdio.h>
#include <climits.h>

void check_palindrome(long int number)
{
	long int rever_number = 0;
	int remainder;
	bool isNegative = false;

	printf("Give a number  ");
	scanf("%d",&number);
	int value = number;

	if(number > INT_MAX || number < INT_MIN)
	{
		printf("The given number %d is either too big or too small \n");
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
	if(rever_number == value)
		printf("The given number %d is a palindrome \n",value);
	else
		printf("The given number %d is not a palindrome \n",value);
}


int main()
{
	check_palindrome(-454);
	return 0;
}
