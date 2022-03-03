#include <iostream>
using namespace std;
#define ONE 1
#define TWO 2
void character_removal(char str[],int n)
{
	int i,j,state=ONE;
	for(i=0;str[i]!='\0';i++)
	{
		if(state==ONE && str[i]


