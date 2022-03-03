#include <iostream>
using namespace std;
int increasing_decreasing(int arr[],int low,int high)
{
	if(low==high)
		return arr[low];
	if((high==low+1) && arr[low]>=arr[high])
		return arr[low];

	if((high==low+1) && arr[low]<=arr[high])
		return arr[high];

	int mid=(low+high)/2;
	if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
		return arr[mid];
	
	if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1])
		return increasing_decreasing(arr,low,mid-1);
	
	else if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1])
		return increasing_decreasing(arr,mid+1,high);
}

int main()
{
	int arr[]={100,200,300,400};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<increasing_decreasing(arr,0,n-1)<<endl;
	return 0;
}
