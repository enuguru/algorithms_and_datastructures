
#include <iostream>
using namespace std;

int maxSubarraySum(int a[],int n)
{
	int currmax=a[0];
	int maxsofar=a[0];
        for(int i=1; i<n; i++)
	{
		currmax = max(a[i],currmax+a[i]);
		maxsofar=max(maxsofar,currmax);
	}
	return maxsofar;
}


int main()
{
	int maxsum = 0;
	int arr[] = { -5, -7, 23, -5, 12, -45 };
	int size = sizeof(arr) / sizeof(arr[0]);
	maxsum = maxSubarraySum(arr,size);
	cout << maxsum;
	return 0;
}


