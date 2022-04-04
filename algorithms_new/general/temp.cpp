
#include <iostream>
using namespace std;

char *custom_itoa(int numInput, char *ascStr, int base)
{

	int numInput;
	int index;

	if( numInput == 0)
	{
		ascStr[index++] = '0';
		ascStr[index] = '\0';
		return ascStr;
	}

	if( numInput < 0 && base == 10)
	{
		isNegative = true;
		index++;
	}

	while( numInput != 0)
	{
		int rem = numInput % base;
                
		ascStr[index++] =  (rem > 9)? (rem - 9) + 'a':(rem - '0');
		numInput = numInput / base;
	}
        
}



int main()
{
	int ascStrRet[100];
	cout << "Base:10 " << custom_itoa(1357, ascStrRet, 10) << endl;
	cout << "Base:10 " << custom_itoa(1357, ascStrRet, 10) << endl;
	cout << "Base:2 " << custom_itoa(1357, ascStrRet, 2) << endl;
	cout << "Base:8 " << custom_itoa(1357, ascStrRet, 8) << endl;
	cout << "Base:16 " << custom_itoa(1357, ascStrRet, 16) << endl;
	return 0;
}
