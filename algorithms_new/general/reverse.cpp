
#include <iostream>
//#define __STDC_LIMIT_MACROS
#include <climits>
using namespace std;

long int reverse(long int numInput) 
{
        long int numOutput = 0;
        bool isNegative = false;
        if(numInput < 0)
        {
            isNegative = true;
            numInput = numInput * -1;
        }
            
        
        while(numInput)
        {
            numOutput = numOutput * 10 + numInput % 10;
            numInput = numInput / 10;
        }
        if(numOutput > INT_MAX || numOutput < INT_MIN)
            return 0;
        return isNegative?(numOutput * -1):numOutput;
}


int main()
{
	int numReturn = 0;
	numReturn = reverse(-453);
	cout << numReturn << "\n";
	return 0;
}
