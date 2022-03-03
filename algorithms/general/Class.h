
#ifndef __CLASS_H__
#define __CLASS_H__

struct X
{
	int* vptr;
	char className[8];
	int x;
};

/* Prototypes of functions that deal with struct X */
void X_Ctor();
void X_Dtor();
void X_One();
void X_Two();
void X_Three();

struct Y
{
	int* vptr;
	char className[8];
	int x;
	int y;
};

/* Prototypes of functions that deal with struct Y */
void Y_Ctor();
void Y_Dtor();
void Y_One();
void X_Two();
void X_Three();

struct Z
{
	int* vptr;
	char className[8];
	int x;
	int y;
	int z;
};

/* Prototypes of functions that deal with struct Z */
void Z_Ctor();
void Z_Dtor();
void Y_One();
void Z_Two();
void X_Three();

#endif
