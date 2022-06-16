

#include <stdio.h>


int main()
{
	int x = 7;
	void newfunc(int);
	void (*fptr)(int) = &newfunc;
	(*fptr)(x);
	newfunc(7);
	return 0;

}


void newfunc(int p)
{
	printf("\n This is new function \n");
}
