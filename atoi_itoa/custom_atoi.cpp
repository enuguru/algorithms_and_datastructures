
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int myAtoi(char* str)
{
	int res = 0;

	// Iterate through all characters
	// of input string and update result
	// take ASCII character of corresponding digit and
	// subtract the code from '0' to get numerical
	// value and multiply res by 10 to shuffle
	// digits left to update running total
	
	for (int i = 0; str[i] != '\0'; ++i)
		res = res * 10 + str[i] - '0';

	return res;
}


int main()
{
	char str[] = "89789";
	int val = myAtoi(str);
	cout << val;
	return 0;
}


