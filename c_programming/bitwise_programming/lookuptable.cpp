// CPP program to illustrate Compute the parity of a
// number using XOR
#include <bits/stdc++.h>

// Generating the look-up table while pre-processing
#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
#define LOOK_UP P6(0), P6(1), P6(1), P6(0)

// LOOK_UP is the macro expansion to generate the table
unsigned int table[256] = { LOOK_UP };

// Function to find the parity
int Parity(int num)
{
	// Number is considered to be of 32 bits
	int max = 16;

	// Dividing the number into 8-bit
	// chunks while performing X-OR
	while (max >= 8) {
		num = num ^ (num >> max);
		max = max / 2;
	}

	// Masking the number with 0xff (11111111)
	// to produce valid 8-bit result
	return table[num & 0xff];
}


int main()
{
	unsigned int num = 1742346774;

	// Result is 1 for odd parity, 0 for even parity
	bool result = Parity(num);

	// Printing the desired result
	result ? std::cout << "Odd Parity" :
			std::cout << "Even Parity";

	return 0;
}
