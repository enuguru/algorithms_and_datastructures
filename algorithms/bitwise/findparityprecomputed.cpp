

#include <iostream>
using namespace std;

short paritythroughprecomputed(const unsigned long &x)
{
    return ( (precomputedparitytbl[x >> 48   ]         ) ^
             (precomputedparitytbl[x >> 32   ] & 0xFFFF) ^
             (precomputedparitytbl[x >> 16   ] & 0xFFFF) ^
             (precomputedparitytbl[x & 0xFFFF]         )   );
}


int main()
{
      int x = 0;
      int p = 23;
      x = paritythroughprecomputed(p);
      cout << x;
}
