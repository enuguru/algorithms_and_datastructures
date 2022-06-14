
#include <stdio.h>

int main()
{
	// Note that fun() is not declared
	//float fun();
	int b=7;
	printf("%f\n", fun(b));
	return 0;
}


int fun(int p)
{
   return 10.5;
}
