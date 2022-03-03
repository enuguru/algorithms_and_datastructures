
#include<stdio.h>

void fib(int n)
{
    /* Declare an array to store fibonacci numbers. */
    int f[n+1];
    int i;

    /* 0th and 1st number of the series are 0 and 1*/
    f[0] = 0;
    f[1] = 1;  

    for (i = 2; i <= n; i++) // f[0] = 0  f[1] = 1 f[2]=1 f[3]= 2 f[4]=3
    {
        /* Add the previous 2 numbers in the series
           and store it */
        f[i] = f[i-1] + f[i-2];
        printf(" %d ",f[i]);
    }

    //return f[n];
}

int main ()
{
    int count = 10;
    fib(10);
    /*
    for(count =0; count<20; count++)
    {
        printf("%d\n", fib(count));
    }
    */
    return 0;
}
