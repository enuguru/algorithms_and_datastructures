

#include <stdio.h>

int main()
{
	int arr[3] = {32,45,79};
	int (*arrptr)[3] = &arr;
	for(int index=0;index<3;index++)
	{
		printf("The value at index %d is %d \n",index, (*arrptr)[index]);
		printf("The address at index %d is %d \n",index, arrptr[index]);
		printf("The address at index %d is %d \n",index, (*arrptr)+index);
	}
}
