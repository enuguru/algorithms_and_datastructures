#include <iostream>
#define __STDC_LIMIT_MACROS
#include <climits>
using namespace std;

long int reverse(long int x) {
        long int output=0;
        bool isNegative=false;
        if(x<0)
        {
            isNegative=true;
            x*=-1;
        }
            
        
        while(x)
        {
            output=output*10+x%10;
            x/=10;
        }
        if(output>INT_MAX || output<INT_MIN)
            return 0;
        return isNegative?(output*-1):output;
    }

int main()
{
int x = 0;
x = reverse(453);
cout << x << "\n";
return 0;
}
