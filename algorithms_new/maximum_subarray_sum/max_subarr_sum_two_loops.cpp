
#include <iostream>
using namespace std;

int getmaxsubarraysum(int a[],int n)
{
	int maxsubarraysum = 0;
	for(int i=0; i<n; i++)
	{
		int subarraysum = 0;
		for(int j=i; j<n; j++)
		{

			subarraysum = subarraysum + a[j];

			if(subarraysum > maxsubarraysum)
				maxsubarraysum = subarraysum;

		}
	}
	return maxsubarraysum;
}

int main()
{
	int max;
	int arr[] = { 23, 3, -56, 7, 32, 11, 5 };
	max = getmaxsubarraysum(arr,7);
	cout << max << " \n";
	return 0;
}
