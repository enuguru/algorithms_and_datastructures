
#include <stdio.h>

int find_parity(int num)
{
    int parity = 0;
    while(num)
    {
        parity = parity ^ 1;
        num = num & (num-1);
    }
    return parity;
}


int main()
{
    int numparity;
    int num;
    printf("Give a number to find parity\n");
    scanf("%d",&num);
    numparity = find_parity(num);
    if(numparity==1)
	printf("It is odd parity\n");
    else
        printf("It is even parity");
    return 0;
}
