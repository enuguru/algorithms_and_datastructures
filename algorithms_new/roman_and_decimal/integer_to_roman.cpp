
#include <iostream>
#include <string>
using namespace std;

string intToRoman(int intNum) 
{
        int nodeNumbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romanchars[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	string romannumber;
        for(int i = 0; i < 13 && intNum > 0; i++) 
	{
            int intervalue = intNum / nodeNumbers[i];
            intNum = intNum % nodeNumbers[i];
            while(intervalue--) 
		    romannumber = romannumber + romanchars[i];
        }
        return romannumber;
}


int main()
{
	string retRomanNum;
	retRomanNum = intToRoman(3041);
	cout << retRomanNum << " \n";
	return 0;
}
