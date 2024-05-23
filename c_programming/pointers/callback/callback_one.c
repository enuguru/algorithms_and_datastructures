#include <stdio.h>

int what(int x, int y, int z, int (*op)(int, int, int))
{
    return op(x, y, z);
}


int add(int x, int y, int z)
{
    return x + y+z;
}


int mul(int x, int y, int z)
{
    return x * y * z;
}


int main()
{
     int (*p)(int, int, int);
     p = add; // p = &add; Both are equivalent
     int res = p(2,3,4); // (*p)(2, 3, 4); //Both are equivalent
     printf("result is %d\n", res);
     p = mul;
     res = p(2,3,4);
     printf("result is %d\n", res);
     // function name can be directly passed as argument to function with callback
     printf("sum is %d\n", what(1, 3, 4, add));
     printf("product is %d\n", what(5, 3, 4, mul));
     return 0;
}
