
#include <iostream>
using namespace std;
static const bool ParityTable256[256] =
{
#   define P2(n) n, n^1, n^1, n
#   define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
#   define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
    P6(0), P6(1), P6(1), P6(0)
};

int main()
{
unsigned char b = 7;  // byte value to compute the parity of
bool parity = ParityTable256[b];
cout << parity;
cout << "\n";

// OR, for 32-bit words:
unsigned int v = 67;
v ^= v >> 16;
v ^= v >> 8;
parity = ParityTable256[v & 0xff];
cout << parity;
cout << "\n";

return 0;
}
/*
// Variation:
unsigned char * p = (unsigned char *) &v;
parity = ParityTable256[p[0] ^ p[1] ^ p[2] ^ p[3]];

*/
