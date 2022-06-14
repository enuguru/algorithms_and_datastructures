
// program to show the use of global variable 
#include <stdio.h>

int x = 35;

int main()
{
	void new_function(int);
	printf("Hello World\n");
	x = x + 10;
	printf("from the main function %d\n",x);
	new_function(7);
	return 0;
}

int q = 45;

void new_function(int a)
{
	printf("from the new function %d\n", x);
	printf("from the new function %d\n", a);
	printf("from the new function %d\n", q);
}
