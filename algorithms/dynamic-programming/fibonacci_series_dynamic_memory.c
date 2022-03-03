
#include<stdio.h>
#include<malloc.h>

int Fibonacci(int);

main()
{
    int n, i = 0, c;

    scanf("%d",&n);

    printf("Fibonacci series\n");

    for ( c = 1 ; c <= n ; c++ )
    {
        printf("%d\n", Fibonacci(i));
        i++;
    }

    return 0;
}


int Fibonacci(int i)
{
    int * fib, j, result;
    if (i < 2) return i;
    fib = malloc(sizeof(int) * (i + 1));
    fib[0] = 0;
    fib[1] = 1;
    for (j = 2; j <= i; j++)
	fib[j] = fib[j-1] + fib[j-2];
    result = fib[i];
    free(fib);
    return result;
}
