
#include <stdio.h>
main()
{
    int lcm(int,int);
    int p = 45;
    int q = 30;
    int s;
    s = lcm(p,q);
    printf("The LCM of two numbers %d  %d  is  %d\n",p,q,s);
}
    
 
// this is an algorithm (Euclid's algorithm to find the LCM)

int lcm(int num1, int num2)
{
    if (num1 % num2 == 0)
      return num1;

    if (num2 % num1 == 0)
      return num2;
      
    int n = (num1 <= num2) ? num2 : num1;
    
    for (; ; n++)
    {
      if(n % num1 == 0 && n % num2 == 0)
         return n;
    }
}
