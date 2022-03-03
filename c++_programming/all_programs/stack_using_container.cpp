#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;
	int n;
	cout<<"Enter the number of elements";
	cin>>n;
	for(int i=0;i<n;i++)
		s.push(i);
	s.pop();
	cout<<s.top()<<endl;
	return 0;
}
