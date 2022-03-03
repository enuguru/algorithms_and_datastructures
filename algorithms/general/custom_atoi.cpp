
#include <iostream>
#include <climits>
using namespace std;

int myAtoi(string s) 
{
        long int i=0;
        long long int sign=1;
        long long int n=0;
        while(i<s.size() && s[i]==' ')
            i++;
        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }
        while(i<s.size() && (s[i]-'0')>=0 && (s[i]-'9'<=9) && n<=INT_MAX)
        {
            n=10*n+(s[i]-'0');
            i++;
        }

        if(n>INT_MAX)
        {
            if(sign==-1)
                return INT_MIN;
            else
                return INT_MAX;
        }
        return n*sign;
            
}

int main()
{
	long int num = myAtoi("  -00456");
	cout << " The number is "<< num <<" \n";
	return 0;
}
