
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	int x = 4;
 	cout << x << " + " << 1 << " is " << -~x << endl;

	x = -5;
 	cout << x << " + " << 1 << " is " << -~x << endl;

	x = 0;
 	cout << x << " + " << 1 << " is " << -~x << endl;

	return 0;
}
