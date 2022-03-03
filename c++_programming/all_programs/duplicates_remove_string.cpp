#include <iostream>
#include <cstring>
using namespace std;
void remove_duplicates(char *str,int n)
{
	int i,j,index=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(str[i]==str[j])
				break;
		}
		if(j==i)
			str[index++]=str[i];
	}
}

int main()
{
	char str[]="badri narayanan";
	int m=sizeof(str);
	cout<<m<<endl;
	remove_duplicates(str,m);
	cout<<str<<endl;
	return 0;
}
