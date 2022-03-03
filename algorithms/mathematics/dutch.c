
#include<stdio.h>
#include <iostream>
#include<string.h>
using namespace std;

struct ball
{
       char colour[6];
       int value;
};

void swap(ball &a, ball &b)
{
     ball temp=a;
     a=b;
     b=temp;
}

void assign(ball a[], int n)
{
     int i;
     for (i=0; i<n; i++)
     {
         if (strcmp(a[i].colour, "red")==0)
            a[i].value=0;
         else if (strcmp(a[i].colour, "green")==0)
            a[i].value=1;
         else if (strcmp(a[i].colour, "blue")==0)
            a[i].value=2;
         else
            a[i].value=-1;
     }
}  

int main()
{
    int n, i, j;
    cin>>n;
    int r=0, b=n-1;
    ball a[n];
    for (i=0;i<n; i++)
    {cin>>a[i].colour;}
    assign(a, n);
    for (i=0; (i<=b); i++)
    {
        if (a[i].value==0)
           {swap(a[i],a[r]);
            r++;
            if ((a[i].value==0)||(a[i].value==2))
            i--;
           }
        if (a[i].value==2)
           {swap(a[i],a[b]);
            b--;
            if ((a[i].value==0)||(a[i].value==2))
            i--;
           }
        //for (j=0;j<n;j++)
        //cout<<a[j].colour<<' ';
        //cout<<'\t'<<r<<i<<b;
        //for (j=0;j<n;j++);
        //cout<<a[j];
        cout<<endl;
    }
    //cout<<endl;
    for (i=0;i<n;i++)
        cout<<a[i].colour<<' ';
    
    getch();   
    
    return 0;
}
