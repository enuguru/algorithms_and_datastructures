
#include<stdio.h>
#define SQR(a) a*a
int main ()
{
    int i, j;
    i = SQR (2);
    j = SQR (2 + 3);   
    printf ("i =  %d j = %d", i, j);
    return 0;
}
