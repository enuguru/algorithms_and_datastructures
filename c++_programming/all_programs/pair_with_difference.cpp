#include <iostream>
using namespace std;
void pair_difference(int arr[],int n,int size)
{
	int i=0,j=1,flag=0;
	while(i<size && j<size)
	{
		if(i!=j && arr[j]-arr[i]==n)
		{
			cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
			flag=1;
			break;
		}
		else if(arr[j]-arr[i]<n)
			j++;
		else
			i++;
	}
	if(flag==0)
		cout<<"No such pair exists"<<endl;
}
	
int main()
{
	int arr[]={1,8,19,100,200};
	int size=sizeof(arr)/sizeof(arr[0]);
	int n;
	n=12;
	pair_difference(arr,n,size);
	return 0;
}
