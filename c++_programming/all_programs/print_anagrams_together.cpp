#include <iostream>
#include <string>
using namespace std;
class Word
{
	public:
	int index;
	char *str;
};

class Duparray
{
	public:
	int size;
	Word *array;
};

void create_duplicate_array(char *str[],int size)
{
	Duparray *duparray=new Duparray();
	duparray->size=size;
	duparray->array=new Word[(duparray->size*sizeof(Word))];
	int i;
	for(i=0;i<size;i++)
	{
		duparray->array[i].str=new char[(strlen(str[i]+1))];
		duparray->array[i].index=i;
		strcpy(duparray->array[i].str,str[i]);
	}
	
	sort(duparray->array[0],duparray->array[size-1]);
	

	
}


int main()
{
	char *word_arr[]={"cat","dog","tac","god","act"};
	int size=sizeof(word_arr)/sizeof(word_arr[0]);
	create_duplicate_array(word_arr,size);
	return 0;
}

