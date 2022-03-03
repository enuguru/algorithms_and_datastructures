#include <iostream>
#include <unordered_map>
using namespace std;
void odd_occurence(int arr[],int n)
{
	int i;
	unordered_map<int,int> m;
	for(i=0;i<n;i++)
		m[arr[i]]++;

	for(auto i:m)
	{
		if(i.second%2!=0)
			cout<<i.first<<endl;
	}
	
}

int main()
{
	int arr[]={10,10,11,11,45,45,50,50,100};
	int n=sizeof(arr)/sizeof(arr[0]);
	odd_occurence(arr,n);
	return 0;
}
