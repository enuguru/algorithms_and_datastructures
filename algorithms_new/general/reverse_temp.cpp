
#include <iostream>
#include <climits>
using namespace std;

int reverse(int numInput)
{
	int rem = 0;
	bool isNegative = false;
	int numOutput = 0;

	if(numInput < 0)
	{
		isNegative = true;
		numInput = -numInput;
	}
	while(numInput > 0)
	{
		rem = numInput % 10;
		numOutput = numOutput * 10 + rem;
		numInput = numInput / 10;
	}

	if(numInput > INT_MAX)
	{
		return 0;
	}
	return isNegative?-numOutput:numOutput;
}


int main()
{
	int numRet = 0;
	numRet = reverse(-453);
	cout << numRet << endl;
	return 0;
}
