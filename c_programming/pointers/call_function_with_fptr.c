
#include <stdio.h>

void newfun(int a)
{
	printf("Value of a is %d\n", a);
}

int main()
{
	// fun_ptr is a pointer to function fun()
	void (*fun_ptr)(int) = &newfun;
	newfun(10);

	(*fun_ptr)(10);

	return 0;
}
