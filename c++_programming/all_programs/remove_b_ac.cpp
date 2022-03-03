#include <iostream>
#define ONE 1
#define TWO 2
using namespace std;
void remove_characters(char *s)
{
	int state=ONE;
	int i,j=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(state==ONE && s[i]!='a' && s[i]!='b')
		{
			s[j]=s[i];
			j++;
		}

		if(state==TWO && s[i]!='c')
		{
			s[j]='a';
			j++;
			if(s[i]!='a' && s[i]!='b' )
			{
				s[j]=s[i];
				j++;
			}
		}

		state=(s[i]=='a')?TWO:ONE;
	}
	if(state==TWO)
	{
		s[j]='a';
		j++;
	}
	s[j]='\0';
}
int main()
{
	char s[]="react";
	remove_characters(s);
	cout<<s<<endl;
	return 0;
}


