#include <iostream>
#include <string>
#define ASCII 256
using namespace std;
void print_list(char str[][50],char *list)
{
	int *map=(int *)calloc(sizeof(int),ASCII);
	int i,j,count,z;
	for(i=0;*(list+i);i++)
		map[(*list+i)]=1;

	for(i=0;i<4;i++)
	{
		for(j=0,count=0;*(str[i]+j);j++)
		{
			if(map[*(str[i]+j)])
			{
				count++;
				map[*(str[i]+j)]=0;
			}
		}
		if(count==3)
			cout<<str[i]<<endl;
		for(z=0;*(list+z);z++)
			map[*(list+z)]=1;
	}
}

int main()
{
	char list[]="sun";
	char str[][50]={"unsorted","sunday","cat","sss"};
	cout<<sizeof(str)/sizeof(str[0])<<endl;
	print_list(str,list);
	return 0;
}
