#include <iostream>
using namespace std;
int top=-1,arr[10],n;
void push(int element)
{
	if(top>=n-1)
	{
		cout<<"Stack is full";
		return;
	}
	arr[++top]=element;
}

int pop()
{
	if(top<0)
		cout<<"The stack is empty";
	return(arr[top--]);
}

void display()
{
	int i;
	for(i=top;i>=0;i--)
		cout<<arr[i]<<"\n";
}

int main()
{
	cout<<"Enter the number of elements in the stack";
	cin>>n;
	int j,ele;
	for(j=1;j<=n;j++)
	{
		cout<<"Enter the element to be inserted";
		cin>>ele;
		push(ele);
	}

	display();
	return 0;
}
	
