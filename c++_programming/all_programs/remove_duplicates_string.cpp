#include <iostream>
#include <string>
using namespace std;
char *remove_duplicates(char str[],int n)
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
	str[index]='\0';
	return str;
}

int main()
{
	char str[]="geeksforgeeks";
	int n=strlen(str);
	cout<<remove_duplicates(str,n)<<endl;
	return 0;
}
