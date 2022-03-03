#include <iostream>
#include <string>
using namespace std;
#define MAX_CHAR 256

int nextChar(int freq[],int dist[])
{
	int max=INT_MIN;
	int i;
	for(i=0;i<MAX_CHAR;i++)
	{
		if((dist[i]<=0 && freq[i]>0) && (max==INT_MIN || freq[i]>freq[max]))
			max=i;
	}
	return max;
}

int rearrange(char str[],char out[],int n,int k)
{
	int freq[MAX_CHAR]={0};
	int dist[MAX_CHAR]={0};
	int i,j,b;
	for(i=0;i<n;i++)
		freq[str[i]]++;
	for(i=0;i<n;i++)
	{
		j=nextChar(freq,dist);
		if(j==INT_MIN)
			return 0;
		out[i]=j;
		freq[j]--;
		dist[j]=k;
		for(b=0;b<MAX_CHAR;b++)
			dist[b]--;
	}
	out[i]='\0';
	return 1;
}

int main()
{
	char str[]="aaabccb";
	int n=strlen(str);
	char out[n];
	if(rearrange(str,out,n,2))
		cout<<out<<endl;
	else
		cout<<"Cannot be rearranged"<<endl;
	return 0;
}

