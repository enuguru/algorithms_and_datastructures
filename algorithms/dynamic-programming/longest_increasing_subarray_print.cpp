
// C++ solution

#include <bits/stdc++.h>
using namespace std;

void findLongestConseqSubarr(vector<int>& v)
{
	int ans = 0, count = 0,
        start = 0, end = 0, x, y;

	for (int i = 0; i < v.size(); i++) {

		if (i > 0 && v[i] == v[i - 1] + 1) {
			count++;
			end = i;
		}
		else {
			start = i;
			count = 1;
		}

		if (ans < count) {
			ans = count;
			x = start;
			y = end;
		}
	}

	for (int i = x; i <= y; i++)
		cout << v[i] << ", ";
}


int main()
{
	vector<int> arr = { 1, 9, 3, 4, 20, 2 };
	findLongestConseqSubarr(arr);
	return 0;
}
