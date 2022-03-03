#include<iostream>
using namespace std;
unsigned add(int a,int b)
{
	unsigned carry;
	while(b)
	{
		carry=a&b;
		a^=b;
		b=carry<<1;
	}
	return a;
}
unsigned multiply(int x , int y)
{
	unsigned result=0;
	while(x)
	{
		if(x&1)
		{
			result=add(x,y);
		}
		x>>=1;
		y<<=1;
	}
	return result;
}

int main()
{
	int n1=10,n2=20;
	cout<<multiply(n1,n2)<<endl;
	return 0;
}
