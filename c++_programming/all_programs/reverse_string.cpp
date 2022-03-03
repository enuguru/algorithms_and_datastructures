#include <iostream>
using namespace std;
int main()
{
	char str[80];
	cout<<"Enter a string"<<endl;
	cin.getline(str,80);
	int l,temp,i,j;
	for(l=0;str[l]!='\0';l++);
	for(i=0,j=l-1;i<l/2;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}

	cout<<str<<endl;
	return 0;
}


