
#include<stdio.h>

#define CUBE(a) (a)*(a)*(a)

int main ()
{
    int i, j;
    i = CUBE (2);
    j = CUBE (2 + 3);
    printf ("i =  %d j = %d", i, j);
    return 0;
}
