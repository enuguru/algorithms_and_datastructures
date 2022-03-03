
/* In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation

T(n) = T(n-1) + T(n-2)

Method 1 ( Use recursion )
A simple method that is a direct recusrive implementation
mathematical recurance relation given above.  */


#include<stdio.h>
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main ()
{
    int n;
    for(n =0; n<20; n++)
    {
        printf("%d\n", fib(n));
    }
    getchar();
    return 0;
}
