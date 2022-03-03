// C++ program to print the elements
// of the vector
#include <iostream>
#include <vector>
using namespace std;

template <typename S>
ostream& operator<<(ostream& os,
					const vector<S>& vector)
{
	// Printing all the elements
	// using <<
	for (auto element : vector) {
		os << element << " ";
	}
	return os;
}

// Driver Code
int main()
{
	// vector containing integer elements
	vector<int> A = { 10, 20, 30,
					40, 50, 60 };

	cout << A << endl;

	return 0;
}
