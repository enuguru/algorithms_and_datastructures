
#include <iostream>
#include <string>
#define ASCII 256
using namespace std;
void print_list(char list[][50],char *word)
{
	int i,j,count,k;
	int *map=(int *)calloc(ASCII,sizeof(int));
	int word_size=strlen(word);
	for(i=0;*(word+i);i++)
		map[*(word+i)]++;

	for(i=0;i<4;i++)
	{
		for(j=0,count=0;*(list[i]+j);j++)
		{
			if(map[*(list[i]+j)])
			{
				count++;
				map[*(list[i]+j)]=0;
			}
		}
		if(count==word_size)
			cout<<list[i]<<endl;

		for(k=0;*(word+k);k++)
			map[*(word+k)]++;
	}
}

int main()
{
	char word[]="sun";
	char list[][50]={"sunday","unsorted","sss","badri"};
	print_list(list,word);
	return 0;
}


