
#include <iostream>
using namespace std;

bool findparity(unsigned long x)
{
     bool result = 0;
     while(x)
     {
         result = result ^ 1;
         x = x & (x-1);
     }
     return result;
}


int main()
{
   bool x;
   int p;
   cin >> p;
   x = findparity(p);
   if(x)
      cout << endl << "The number " << p << " is odd parity" << endl;
   else
      cout << endl << "The number " << p << " is even parity" << endl;
}
