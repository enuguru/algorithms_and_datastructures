#include <iostream>
using namespace std;
void duplicate_elements(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[abs(arr[i])]>=0)
			arr[abs(arr[i])]=-arr[abs(arr[i])];
		else
			cout<<abs(arr[i])<<endl;
	}
}

int main()
{
	int arr[]={1,3,5,2,1,5},n;
	n=sizeof(arr)/sizeof(arr[0]);
	duplicate_elements(arr,n);
	return 0;
}
