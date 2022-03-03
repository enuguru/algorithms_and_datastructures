#include <iostream>
using namespace std;
int majority(int arr[],int n)
{
	int maxcount,count=0,element;
	int i,j;
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(arr[i]==arr[j])
				count++;
			if(count>n/2)
			{
				maxcount=count;
				element=arr[i];
			}
		}
	}
	return element;
}

int main()
{
	int arr[]={10,4,4,4,8},n;
	n=sizeof(arr)/sizeof(arr[0]);
	cout<<majority(arr,n)<<endl;
	return 0;
}
