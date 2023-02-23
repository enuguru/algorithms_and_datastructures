/* Program to demonstrate time taken by function fun() */
#include <stdio.h>
#include <time.h>

// A function that terminates when enter key is pressed
void fun()
{
	int flag,count,num,val;
	num = 1000;
	printf("fun() starts \n");
	for(count = 1; count < num; count++)
	{
		flag = 0;
		for(val = 2; val < count; val++)
		{
			if((count % val) == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			printf("%d ",count);
		}
	}
}

// The main program calls fun() and measures time taken by fun()
int main()
{
	// Calculate the time taken by fun()
	clock_t t;
	t = clock();
	fun();
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

	printf("fun() took %f seconds to execute \n", time_taken);
	return 0;
}
