
#include <stdio.h>

int main()
{
   void myfunc();
   myfunc();
   myfunc();
   myfunc();
}

void myfunc()
{
    static int p = 50;
    printf(" The value of p is %d\n",p);
    p = p + 1;
}
