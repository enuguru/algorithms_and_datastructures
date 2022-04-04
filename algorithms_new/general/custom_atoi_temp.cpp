
#include <iostream>
#include <climits>
using namespace std;

int myAtoi(string ascStr) 
{
        long int i=0;
        long long int sign=1;
        long long int intNum=0;
	bool isNegative = false;

        while(i<ascStr.size() && ascStr[i]==' ')
            i++;

        if(ascStr[i]=='-')
        {
            isNegative = true;
            i++;
        }
        else if(ascStr[i]=='+')
        {
            i++;
        }

        while(i<ascStr.size() && (ascStr[i]-'0')>=0 && (ascStr[i]-'0'<=9) && intNum<=INT_MAX)
        {
            intNum=10*intNum+(ascStr[i]-'0');
            i++;
        }

        if(intNum>INT_MAX)
        {
            if(isNegative==true)
                return INT_MIN;
            else
                return INT_MAX;
        }

        return (isNegative==true)?-intNum:intNum;
            
}


int main()
{
	long int intNumRet = myAtoi("  +00456");
	cout << " The number is "<< intNumRet <<" \n";
	return 0;
}
