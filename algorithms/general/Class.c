
#include "Class.h"

#include <stdio.h>
#include <string.h>

extern int ECX;

void* X_vtable[] =
{
	X_Dtor,
	X_One,
	X_Two,
	X_Three
};

void X_Ctor()
{
	int* vptr;
	char* className;
	int* x;

	vptr = (int*)ECX;
	className = (char*)(ECX + 4);
	x = (int*)(ECX + 4 + 8);

	*vptr = (int)X_vtable;
	strcpy(className, "class X");
	*x = 100;

	printf("Constructor of class X. x = %d\n", *x);
}

void X_Dtor()
{
	int* vptr;
	int* x;

	vptr = (int*)ECX;
	x = (int*)(ECX + 4 + 8);

	*vptr = (int)X_vtable;
	*x = 100;

	printf("Destructor of class X. x = %d\n", *x);
}

void X_One()
{
	char* className = (char*)(ECX + 4);
	int* x = (int*)(ECX + 4 + 8);

	*x = 101;

	printf("One() defined in class X. Instantiated class - %s. x = %d\n", className, *x);
}

void X_Two()
{
	char* className = (char*)(ECX + 4);
	int* x = (int*)(ECX + 4 + 8);

	*x = 102;

	printf("Two() defined in class X. Instantiated class - %s. x = %d\n", className, *x);
}

void X_Three()
{
	char* className = (char*)(ECX + 4);
	int* x = (int*)(ECX + 4 + 8);

	*x = 103;

	printf("Three() defined in class X. Instantiated class - %s. x = %d\n", className, *x);
}

void* Y_vtable[] =
{
	Y_Dtor,
	Y_One,
	X_Two,
	X_Three
};

void Y_Ctor()
{
	int* vptr;
	char* className;
	int* x;
	int* y;

	X_Ctor();

	vptr = (int*)ECX;
	className = (char*)(ECX + 4);
	x = (int*)(ECX + 4 + 8);
	y = (int*)(ECX + 4 + 8 + 4);

	*vptr = (int)Y_vtable;
	strcpy(className, "class Y");
	*y = 200;

	printf("Constructor of class Y. x = %d, y = %d\n", *x, *y);
}

void Y_Dtor()
{
	int* vptr;
	int* x;
	int* y;

	vptr = (int*)ECX;
	x = (int*)(ECX + 4 + 8);
	y = (int*)(ECX + 4 + 8 + 4);

	*vptr = (int)Y_vtable;
	*y = 200;

	printf("Destructor of class Y. x = %d, y = %d\n", *x, *y);

	X_Dtor();
}

void Y_One()
{
	char* className = (char*)(ECX + 4);
	int* x = (int*)(ECX + 4 + 8);
	int* y = (int*)(ECX + 4 + 8 + 4);

	*y = 201;

	printf("One() overridden in class Y. Instantiated class - %s. x = %d, y = %d\n", className, *x, *y);
}

void* Z_vtable[] =
{
	Z_Dtor,
	Y_One,
	Z_Two,
	X_Three
};

void Z_Ctor()
{
	int* vptr;
	char* className;
	int* x;
	int* y;
	int* z;

	Y_Ctor();

	vptr = (int*)ECX;
	className = (char*)(ECX + 4);
	x = (int*)(ECX + 4 + 8);
	y = (int*)(ECX + 4 + 8 + 4);
	z = (int*)(ECX + 4 + 8 + 4 + 4);

	*vptr = (int)Z_vtable;
	strcpy(className, "class Z");
	*z = 300;

	printf("Constructor of class C. x = %d, y = %d, z = %d\n", *x, *y, *z);
}

void Z_Dtor()
{
	int* vptr;
	int* x;
	int* y;
	int* z;

	vptr = (int*)ECX;
	x = (int*)(ECX + 4 + 8);
	y = (int*)(ECX + 4 + 8 + 4);
	z = (int*)(ECX + 4 + 8 + 4 + 4);

	*vptr = (int)Z_vtable;
	*z = 300;

	printf("Destructor of class Z. x = %d, y = %d, z = %d\n", *x, *y, *z);

	Y_Dtor();
}

void Z_Two()
{
	char* className = (char*)(ECX + 4);
	int* x = (int*)(ECX + 4 + 8);
	int* y = (int*)(ECX + 4 + 8 + 4);
	int* z = (int*)(ECX + 4 + 8 + 4 + 4);

	*z = 302;

	printf("Two() overridden in class Z. Instantiated class - %s. x = %d, y = %d, z = %d\n", className, *x, *y, *z);
}

