
#include <stdio.h>

int main()
{
	void funcone();
	void functwo();
	void functhree();
	void funcfour();
	void funcfive();
	void funcsix();
	void funcseven();
	void funceight();
	void funcnine();
	void functen();
	void funceleven();
	void functwelve();

	void (*fptr[3][4])() = { 
		                  { funcone, functwo, functhree, funcfour },

			          { funcfive, funcsix, funcseven, funceight },

	                          { funcnine, functen, funceleven, functwelve }
	                       };
	(*fptr[0][0])();
	(*fptr[1][0])();
	(*fptr[2][2])();

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


void funcfour()
{
	printf("Iam in function four\n");
}

void funcfive()
{
	printf("Iam in function five\n");
}


void funcsix()
{
	printf("Iam in function six\n");
}


void funcseven()
{
	printf("Iam in function seven\n");
}



void funceight()
{
	printf("Iam in function eight\n");
}


void funcnine()
{
	printf("Iam in function nine\n");
}


void functen()
{
	printf("Iam in function ten\n");
}


void funceleven()
{
	printf("Iam in function eleven\n");
}


void functwelve()
{
	printf("Iam in function twelve\n");
}





