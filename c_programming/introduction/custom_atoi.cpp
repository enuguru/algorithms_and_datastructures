
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int myAtoi(string ascStr) 
{
        long int i=0;
	bool isNegative = false;
        long long int intNum=0;

        while(i<ascStr.size() && ascStr[i]==' ')
            i++;

        if(ascStr[i]=='-')
        {
            isNegative=true;
            i++;
        }
        else if(ascStr[i]=='+')
        {
            i++;
        }

        while(i<ascStr.size() && (ascStr[i]-'0')>=0 && (ascStr[i]-'9'<=9) && intNum<=INT_MAX)
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

        return isNegative?-intNum:intNum;
            
}


int main()
{
	long int intNumRet = myAtoi("  -00456");
	cout << " The number is "<< intNumRet <<" \n";
	return 0;
}
