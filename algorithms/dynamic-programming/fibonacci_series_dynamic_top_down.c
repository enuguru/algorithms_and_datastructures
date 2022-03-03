
#include<stdio.h>

int saveF[100] = { 0 };;

int main ()
{
    int fib(int);
    int count;
    for(count =0; count<20; count++)
    {
        printf("%d\n", fib(count));
    }
    getchar();
    return 0;
}


int fib(int i)
{
    if(saveF[i] > 0)
        return saveF[i];
    if (i <= 1)
        return i;
    saveF[i] = fib(i-1) + fib(i-2);
    return saveF[i];
}
