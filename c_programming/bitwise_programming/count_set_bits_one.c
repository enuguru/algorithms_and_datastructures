
#include <stdio.h>

int count_bits(int num)
{
    int count = 0;
    while(num)
    {
        if(num & 1)
            count = count + 1;
        num = num>>1;
    }
    return count;
}


int main()
{
    int set_bits;
    int num;
    scanf("%d",&num);
    set_bits = count_bits(num);
    printf("The number of set bits is %d\n",set_bits);
    return 0;
}
