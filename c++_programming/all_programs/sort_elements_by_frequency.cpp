#include <iostream>
using namespace std;
struct ele
{
	int index,count,arr;
};

bool mycomp(struct ele a,struct ele b)
{
	return(a.arr<b.arr);
}

bool comp(struct ele a,struct ele b)
{
	if(a.count!=b.count)
		return(a.count<b.count);
	else
		return(a.index>b.index);
}

void sortbyfrequency(int arr[],int n)
{
	struct ele element[n];
	int i,index=0,j;
	for(i=0;i<n;i++)
	{
		element[i].index=i;
		element[i].count=0;
		element[i].arr=arr[i];
	}
	stable_sort(element,element+n,mycomp);
	for(i=1;i<n;i++)
	{
		if(element[i].arr==element[i-1].arr)
		{
			element[i].count+=element[i-1].count+1;
			element[i-1].count=-1;
			element[i].index=element[i-1].index;

		}
		else
			element[i].count=1;
	}

	stable_sort(element,element+n,comp);
	for(i=n-1;i>=0;i--)
	{
		if(element[i].count!=-1)
			for(j=0;j<element[i].count;j++)
				arr[index++]=element[i].arr;
	}

}

int main()
{
	int arr[]={8,8,7,8,7,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	sortbyfrequency(arr,n);
	int i;
	for(i=0;i<n;i++)
		cout<<arr[i]<<endl;
	return 0;
}

