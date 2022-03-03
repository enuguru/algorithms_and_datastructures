
#include <iostream>
using namespace std;

long swapbits(long x, const int &first, const int &second)
{
     if(((x >> first) & 1) != ((x >> second) & 1))
          x = x ^ (( 1L << first ) | (1L << second));
     return x;
}


int main()
{
   long y;
   long z;
   int first, second;
   cin >> y;
   cout << endl << "which bits you want to swap " << endl;
   cout << endl << "enter the first bit position " << endl;
   cin >> first;
   cout << endl << "enter the second bit position " << endl;
   cin >> second;
   z = swapbits(y,first,second);
   cout << endl << "The number after swap is " << z << endl;
}
