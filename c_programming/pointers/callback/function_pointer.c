
#include <stdio.h>

int main()
{
	int x = 7;
	void newfunc(void (*)());
	void functwo();
	void (*fptr)() = &functwo;
	//functwo();
	//(*fptr)();
	newfunc(fptr);
	return 0;

}


void functwo()
{
	printf("Iam in function two\n");
}

void newfunc(void (*fptr)())
{
	(*fptr)();
	printf("\n This is new function \n");
}
