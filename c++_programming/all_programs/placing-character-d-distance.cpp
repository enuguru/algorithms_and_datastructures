#include <iostream>
#include <string>
#define ASCII 256
using namespace std;

int next_char(int freq[],int dist[])
{
	int max=INT_MIN;
	int i;
	for(i=0;i<ASCII;i++)
	{
		if((dist[i]<=0 && freq[i]>0) && 
		 	(max==INT_MIN || freq[i]>freq[max]))

			max=i;
	}
	return max;
}

int rearrange_characters(char str[],char out[],int d,int n)
{
	int i,j,k;
	int freq[ASCII]={0};
	int dist[ASCII]={0};

	for(i=0;i<n;i++)
		freq[str[i]]++;
	
	
	for(i=0;i<n;i++)
	{
		j=next_char(freq,dist);
		if(j==INT_MIN)
			return 0;
		out[i]=j;
		freq[j]--;
		dist[j]=d;
		for(k=0;k<ASCII;k++)
			dist[k]--;
	}
	out[n]='\0';
	return 1;
}

int main()
{
	char str[]="aaaabbbcc";
	int n=strlen(str);
	char out[n];
	if(rearrange_characters(str,out,2,n))
		cout<<out<<endl;
	else
		cout<<"Invalid String"<<endl;

	return 0;
}

