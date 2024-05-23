// fun.c contains the below code

#include<stdio.h>

void mymap(int a[],int b[],int n,int (*p)(int))
{
//int n = (sizeof(a)/sizeof(*a));// array degenerates to a pointer at runtime. Think about size of pointer
//printf("n is %d\n",n);
for(int i = 0;i<n;i++)
{ b[i] = (*p)(a[i]); }
}


void disp(const int a[],int n)
{
for(int i = 0;i<n;i++)
{
printf("%d ",a[i]);
}
}


void myfilter(const int a[],int b[],int n,int *m, int (*op)(int))
{
int count = 0;
for(int i = 0;i<n;i++)
{
if(op(a[i]))
{
b[count] = a[i];
count++;
}
}
*m = count;
}


int is_greater_than_22(int x)
{ return x > 22; }


int myreduce(int a[],int n,int (*op)(int,int))
{
int res = 0;
for(int i = 0;i<n;i++)
//for(int i = 0;i<n-1;i++)
{
//res = op(a[i],a[i+1]) // logical error
//res = op(res,a[i+1]) // logical error
res = op(res,a[i]);
}
return res;
}
