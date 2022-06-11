
#include <stdio.h>

int x = 35;

int main()
{
	void new_function();
	printf("Hello World\n");
	new_function();
	new_function();
	new_function();
	return 0;
}


void new_function()
{
	static int p;
	p = p + 10;
	printf("%d\n", p);
}
