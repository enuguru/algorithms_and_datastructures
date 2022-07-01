
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
		cout << "The given number is either too big or too small ";
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

	cout << "\n" << "The given number is " << value << "\n";
	cout << "The reversed number is " << rever_number << "\n";

	return 0;
}
