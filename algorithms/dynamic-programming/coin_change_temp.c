
#include <stdio.h>

void main()
{

    void get_coin_change();
    get_coin_change();

}


void get_coin_change()
{
    int i,j,m,n,outercount,innercount,coinscount;
    int coins[5] =  { 0, 1, 5, 6, 8};
    static int table[4][12];

    m = 4;
    n = 11;
    for( i =0; i < n+1; i++)
    {
        table[0][i] = i;
        printf("%d ",table[0][i]);
    }
    printf("\n");

    for( i =0; i < m+1; i++)
    {
        table[i][0] = 0;
    }
    for(outercount = 1; outercount < m+1; outercount++)
    {
        printf("0 ");
        for(innercount = 1; innercount < n+1; innercount++)
        {
            if( innercount >= coins[outercount])
            {
                if(table[outercount-1][innercount] < (1 + (table[outercount][innercount-coins[outercount]])))
                    table[outercount][innercount] = table[outercount -1][innercount];
                else
                    table[outercount][innercount] = (1 + (table[outercount][innercount-coins[outercount]]));
            }
            else
            {
                table[outercount][innercount] = table[outercount -1][innercount];
            }
            if(innercount > 9)
            {
                 printf(" ");
            }
            printf("%d ",table[outercount][innercount]);
        }
        printf("\n");
    }
}
