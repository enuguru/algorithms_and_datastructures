

#include <stdio.h>

int main()
{
	int p = 10;
	int *ptr = &p;
	int **dptr = &ptr;
	printf("The value of p is %d \n",p);
	printf("The size of p is %d bytes \n",sizeof(p));
	printf("The address of p is %p \n",&p);
	printf("The value of ptr is %p \n",ptr);
	printf("The value at ptr is %d \n",*ptr);
	printf("The address of ptr is %p \n",&ptr);
	printf("The size of ptr is %d bytes \n",sizeof(ptr));
	printf("The value of dptr is %p \n",dptr);
	printf("The value at dptr is %p \n",*dptr);
	printf("The value in the value at dptr is %d \n",**dptr);
	printf("The address of dptr is %p \n",&dptr);
	printf("The size of dptr is %d bytes \n",sizeof(dptr));
}
