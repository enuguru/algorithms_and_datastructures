
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void check_palindrome(long int number)
{
	long int rever_number = 0;
	int remainder;
	bool isNegative = false;

	printf("Give a number  ");
	scanf("%d",&number);
	int value = number;

	if(number > INT_MAX || number < INT_MIN)
		cout << "The given number is too big or too small ";

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
		cout << "The given number is a palindrome ";
	else
		cout << "The given number is not a palindrome ";
}


int main()
{
	check_palindrome(-454);
	return 0;
}
