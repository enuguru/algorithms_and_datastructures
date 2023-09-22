
#include <stdio.h>

int main()
{
	void funcone();
	void functwo();
	void functhree();
	void (*fptr[3])() = { funcone, functwo, functhree };
	(*fptr[0]) ();
	(*fptr[1]) ();
	(*fptr[2]) ();
	void (*(*afptr)[3])();
	afptr = &fptr;
	return 0;

}

void funcone()
{
	printf("Iam in function one\n");
}

void functwo()
{
	printf("Iam in function two\n");
}


void functhree()
{
	printf("Iam in function three\n");
}

