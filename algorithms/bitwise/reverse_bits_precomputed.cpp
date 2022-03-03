

#include <iostream>
using namespace std;

long reversebitsprecomputed(const unsigned long &x)
{
    return ( (precomputedparitytbl[x >> 48 & 0xFFFF]       ) |
             (precomputedparitytbl[x >> 32 & 0xFFFF]  << 16) |
             (precomputedparitytbl[x >> 16 & 0xFFFF]  << 32) |
             (precomputedparitytbl[x       & 0xFFFF]  << 48)  );
}
