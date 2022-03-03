#include <iostream>
using namespace std;
void leader_array(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]<arr[j])
				break;
		}
		if(j==n)
			cout<<arr[i]<<endl;
	}
}

int main()
{
	int arr[]={10,20,1,2,9},n;
	n=sizeof(arr)/sizeof(arr[0]);
	leader_array(arr,n);
	return 0;
}
