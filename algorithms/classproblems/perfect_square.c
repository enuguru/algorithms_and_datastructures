
#include <stdio.h>

int main()
{
   void perfect_square();
   perfect_square();
}

void perfect_square()
{
    int i,j;
    for(i = 1; i <= 100; i++)
    {
        for(j = 1; j <=i; j++)
        {
            if( (j * j) == i)
            {
               printf(" %d",i);
            }
        }
    }
    printf("\n");
} 
