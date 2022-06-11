
// program to show the use of local variable
#include <stdio.h>

int main()
{
        int x = 35;
	void new_function(int);
	printf("Hello World\n");
	printf("from the main function %d\n",x);
	new_function(7);
	return 0;
}


void new_function(int a)
{
	printf("from the new function %d\n", a);
	//printf("from the new function %d\n", x);
}
