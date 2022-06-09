
#include <stdio.h>

int count_bits(int num)
{
    int count = 0;
    while(num)
    {
        count = count + 1;
        num = num & (num-1);
    }
    return count;
}


int main()
{
    int set_bits;
    int var;
    printf("Give a number \n");
    scanf("%d",&var);
    set_bits = count_bits(var);
    printf("The number of set bits is %d\n",set_bits);
    return 0;
}
