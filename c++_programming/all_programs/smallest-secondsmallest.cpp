#include <iostream>
using namespace std;
void smallest_secondsmallest(int arr[],int n)
{
	int first=INT_MAX,second=INT_MAX,i;
	for(i=0;i<n;i++)
	{
		if(arr[i]<first)
		{
			second=first;
			first=arr[i];
		}
		else if(arr[i]<second && arr[i]!=first)
			second=arr[i];
	}

	cout<<"First smallest "<<first<<" "<<"second smallest "<<second<<endl;
}

int main()
{
	int arr[]={10,11,1,1,20},n;
	n=sizeof(arr)/sizeof(arr[0]);
	smallest_secondsmallest(arr,n);
	return 0;
}
