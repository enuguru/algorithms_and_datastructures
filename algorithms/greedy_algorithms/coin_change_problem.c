
#include <stdio.h>

void main()
{

    void coin_change();
    coin_change();

}

/* this function actually hardcodes the changeamount amount and coins */
/* array to prove the algorithm */

void coin_change()
{
    int coincount = 0; int coinindex =0; int sel =0; int changeamount = 117;
    int coinselect[20] = { 0 }; int coins[4] = { 25, 10, 5, 1};
    int loopcount,changeamountorig; changeamountorig = changeamount; 
   
    /*  this while loop calculates the changeamount */

    while(changeamount != 0)
    {
        if((changeamount - coins[coinindex]) >= 0)
        {
            coinselect[sel] = coins[coinindex];
            coincount = coincount + 1;  sel = sel + 1;
            changeamount = changeamount - coins[coinindex];
        }
        else
            coinindex++;
    }

    /* these lines of code print the result, this can be refactoried to a separate function */

    printf("The change amount is %d\n",changeamountorig);
    printf("The number of coins selected are");
    printf(" %d\n",coincount);
    printf("The coins selected are");
    for(loopcount = 0; loopcount < 20; loopcount++)
    {
       if(coinselect[loopcount] != 0)
        printf(" %d ",coinselect[loopcount]);  
       else
         break;
    }
    printf("\n");
}
