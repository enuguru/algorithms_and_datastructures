

#include <stdio.h>
#include <malloc.h>

#include "Class.h"

int ECX;

void main()
{
	int nChoice;
	struct X* pClass = NULL;

	int* vptr;
	int* vtbl;
	typedef void (*FPTR)();

	FPTR Dtor;
	FPTR One;
	FPTR Two;
	FPTR Three;

	do
	{
		printf("\n1. Class X");
		printf("\n2. Class Y");
		printf("\n3. Class Z");
		printf("\n0. Exit\n");
		printf("\nEnter Choice: ");

		scanf("%d", &nChoice);
		printf("\n");

		switch (nChoice)
		{
		case 0:
			break;

		case 1:
			pClass = malloc(sizeof(struct X));
			
			ECX = (int)pClass;
			X_Ctor();

			break;

		case 2:
			pClass = malloc(sizeof(struct Y));
			
			ECX = (int)pClass;
			Y_Ctor();

			break;

		case 3:
			pClass = malloc(sizeof(struct Z));
			
			ECX = (int)pClass;
			Z_Ctor();

			break;

		default:
			printf("\nInvalid Choice\n");
		}

		if (pClass)
		{
			vptr = (int*)pClass;
			vtbl = (int*)*vptr;

			Dtor = (FPTR)*(vtbl + 0);
			One = (FPTR)*(vtbl + 1);
			Two = (FPTR)*(vtbl + 2);
			Three = (FPTR)*(vtbl + 3);

			One();
			Two();
			Three();

			Dtor();
			free(pClass);
			pClass = NULL;
		}
	}
	while (nChoice);
}

