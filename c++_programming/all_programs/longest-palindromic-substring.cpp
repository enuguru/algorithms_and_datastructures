#include <iostream>
#include <string>
using namespace std;

void print_substr(string str,int l,int h)
{
	for(int i=l;i<=h;i++)
		cout<<str[i];
	cout<<endl;
}

void longest_substring(string s)
{
	int n=s.size();
	int start;
	int arr[n][n];
	memset(arr,0,sizeof(arr));
	int maxlength=1;
	int i,j,k;
	for(i=0;i<n;i++)
		arr[i][i]=1;
	
	maxlength=2;
	for(i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			arr[i][i+1]=1;
			
		}
	}
	
	for(k=3;k<=n;k++)
	{
		for(i=0;i<n-k+1;i++)
		{
			j=i+k-1;
			if(arr[i+1][j-1]==1 && s[i]==s[j])
			{
				arr[i+1][j-1]=1;
				if(k>maxlength)
				{
					start=i;
					maxlength=k;
				}
			}
		}
	}
	
	print_substr(s,start,start+maxlength-1);

}

int main()
{
	string s="geekes";

	longest_substring(s);
	return 0;
}

