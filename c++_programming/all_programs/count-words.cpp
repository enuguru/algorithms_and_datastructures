#include <iostream>
#define IN 0
#define OUT 1
using namespace std;
int count_words(char *s)
{
	int wc=0,state=OUT;
	while(*s)
	{
		if(*s==' '|| *s=='\n' || *s=='\t')
			state=OUT;
		else if(state==OUT)
		{
			wc++;
			state=IN;
		}
		++s;
	}
	return wc;
}

int main()
{
	char s[]="one two     three\n four\tfive";
	cout<<count_words(s)<<endl;
	return 0;
}

				



