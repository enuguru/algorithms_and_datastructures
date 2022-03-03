
/* This uses the kernighan algorithm for counting bits */

#include <stdio.h>

int count_bits(int num)
{
    int count = 0;
    while(num)
    {
        count = count + (num & 1);
        num = num>>1;
    }
    return count;
}


int main()
{
    int set_bits;
    set_bits = count_bits(7);
    printf("The number of set bits is %d\n",set_bits);
    return 0;
}
