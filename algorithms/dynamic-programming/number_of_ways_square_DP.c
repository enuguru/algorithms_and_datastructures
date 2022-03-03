
#include <stdio.h>

void main()
{
    void number_of_ways();
    number_of_ways();
    printf("\n");
}


void number_of_ways()
{
        int outer,inner,i,j;
        static int A[5][6];
        int n = 5; int m =6;
	for( outer = 0; outer < n; ++outer)
	{
		for(inner = 0; inner < m; ++inner)
		{
                   if((inner  == 0) || (outer == 0))
                      A[outer][inner] = 1;
                   else
	              A[outer][inner] = A[outer][inner] + (A[outer-1][inner] + A[outer][inner-1]);
                      printf("%d ",A[outer][inner]);
		}
                printf("\n");
	}
}
