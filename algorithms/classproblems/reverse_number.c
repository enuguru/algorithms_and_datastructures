
#include <stdio.h>

void main()
{
    int reverse_num = 0;
    int rem = 0;
    int num = 67;

    while(num != 0)
    {
        reverse_num = reverse_num * 10;
        reverse_num = reverse_num + (num % 10);
        num = num / 10;
    }
    printf("the reverse of number 67 is %d \n",reverse_num);
}
