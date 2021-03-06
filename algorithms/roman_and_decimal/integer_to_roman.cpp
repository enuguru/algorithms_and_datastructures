
#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num) 
{
        int nodes[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string chars[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}, result;
        for(int i = 0; i < 13 && num > 0; i++) 
	{
            int value = num / nodes[i];
            num = num % nodes[i];
            while(value--) 
		    result = result + chars[i];
        }
        return result;
}


int main()
{
	string newstr;
	newstr = intToRoman(3041);
	cout << newstr << " \n";
	return 0;
}
