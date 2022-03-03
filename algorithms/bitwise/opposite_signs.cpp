
#include <iostream>
#include <bitset>
using namespace std;

// main function
int main()
{
	int x = 4;
 	int y = -8;

 	cout << x << "  in binary is " << bitset<64>(x) << endl;
 	cout << y << " in binary is " << bitset<64>(y) << endl;

 	// true iff x and y have opposite signs
	bool isOpposite = ((x ^ y) < 0);

	if (isOpposite)
		cout << x << " and " << y << " have opposite signs" << endl;
	else
		cout << x << " and " << y << " don't have opposite signs" << endl;

	return 0;
}
