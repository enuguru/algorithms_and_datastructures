
#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
	if (x != y)
	{
		x = x ^ y;
		y = x ^ y;
		x = x ^ y;
	}
}

// main function
int main()
{
	int x = 3, y = 4;

	cout << "Before swap: x = " << x << " and y = " << y << endl;
	swap(x, y);
	cout << "\nAfter swap: x = " << x << " and y = " << y << endl;

	return 0;
}
