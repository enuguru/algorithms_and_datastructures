

     #include<stdio.h>
     void main()
    {
    int i=0,j=1,k,l;
   for(l=0;l<6;l++)
   {
    k=i+j;
    i=j;
    j=k;
    printf("%d\n",k);
    }
    }

