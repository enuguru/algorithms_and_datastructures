
#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToInt(string s) 
{
        map<char,int> roman={
                    {'I',1},
                    {'V',5},
                    {'X',10},
                    {'L',50},
                    {'C',100},
                    {'D',500},
                    {'M',1000},
                    
        };
        int n=s.length();
        int i;
        int value=roman[s[n-1]];
        for(i=n-1;i>0;i--)
        {
            if(roman[s[i-1]]<roman[s[i]])
            {
                value=value-roman[s[i-1]];
            }
            else
                value=value+roman[s[i-1]];
        }
        return value;
        
}


int main()
{
	string newstr = "MMMXLI";
	int num = romanToInt(newstr);
	cout << num << " \n";
}
