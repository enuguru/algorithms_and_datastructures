//client_callback.c contains the below code
#include<stdio.h>
#include "fun.h"

int incr(int x)
{
    return x+1;
}

int is_even(int x)
{
    return x%2 == 0;
}

int add(int x,int y)
{
    return x+y;
}

int main()
{
int a[] = {11,22,33,44,55};
int n = sizeof(a)/sizeof(*a);
int b[n];
printf("a is --------\n");
disp(a,n);
mymap(a,b,n,incr);
printf("\nb is ------- \n");
disp(b,n);
/*int c = myfilter(a,b,n,is_even); // write appropriate implementation in fun.c for
myfilter function returning integer
printf("\nb is ------- \n");
disp(b,c);*/
int m;
myfilter(a,b,n,&m,is_even); // this myfilter function doesn't return any value

printf("\nb is ------- \n");
disp(b,m);
myfilter(a,b,n,&m,is_greater_than_22);
printf("\nb is ------- \n");
disp(b,m);
int result = myreduce(a,n,add);
printf("Result is %d\n",result);
return 0;
}
