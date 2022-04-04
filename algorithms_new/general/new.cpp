
#include <iostream>
using namespace std;

void reverse(char str[], int length)
{
	int start = 0;
	int end = length -1;
	while(start<end)
	{
		swap(*(str+start),*(str+end));
		start++;
		end--;
	}
}


char *custom_itoa(int numInput, char *ascStrRet, int base)
{
	int index = 0;
	bool isNegative = false;
	if(numInput == 0)
	{
		ascStrRet[index++] = '0';
		ascStrRet[index] = '\0';
		return ascStrRet;
	}

	if(numInput < 0 && base == 10)
	{
		isNegative = true;
		numInput = -numInput;
	}
	
	while(numInput != 0)
	{
		int rem = numInput % base;
		ascStrRet[index++] = (rem>9)?(rem-10) + 'a':(rem + '0');
		numInput = numInput / base;
	}

	if(isNegative)
		ascStrRet[index++] = '-';

	ascStrRet[index] = '\0';
	reverse(ascStrRet,index);

	return ascStrRet;
}


int main()
{
	char ascStr[100];
	cout << "Base:10 " << custom_itoa(1423, ascStr,10) << endl;
	cout << "Base:10 " << custom_itoa(-1423, ascStr,10) << endl;
	cout << "Base:2 " << custom_itoa(1423, ascStr,2) << endl;
	cout << "Base:8 " << custom_itoa(1423, ascStr,8) << endl;
	cout << "Base:16 " << custom_itoa(1423, ascStr,16) << endl;
	return 0;
}
