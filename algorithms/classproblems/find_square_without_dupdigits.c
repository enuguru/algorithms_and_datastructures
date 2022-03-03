
#include <stdio.h>

static int used[10];  /* this is a global variable since all functions want to use this */
              /* static because this is only seen within this file */

/* see how small the main function is, in a well written program the main just calls the */
/* functions, does not do anything else */

int main()
{
    int num, sqr,bool;
    for(num = 300; num < 1000; num++) /* I am checking from 300 to 1000 becuase it is the possible range */
    {
        int hasDuplicate(int);
        int hasDuplicatestwo(int,int);
        int check_all_digits(int, int);
        sqr = num * num;
        hasDuplicatestwo(num,sqr);
        if(check_all_digits(num,sqr))
        {
            printf("sqr of %d  is  %d\n",num,sqr);
            return 0;
        }
        else
            continue;
    }

}


/* this function checks if the two numbers have any duplicates among them */

int hasDuplicatestwo(int one, int two)
{
    int usedcount;
    if (one > 9999999999 || two > 999999999)
        return 1;
    for (usedcount = 0; usedcount < 10; usedcount++)
        used[usedcount] = 0;
    while (one != 0) {
        used[one%10] = 1;
        one /= 10;
    }
    while(two != 0)
    {
        while(two != 0)
        {
            if(used[two%10] == 1)
                return 1;
            else
                used[two%10] = 1;
            two /= 10;
        }
    }
    return 0;
}

/* this function is not used now, but if you have only one number to check  you can use this */

int hasDuplicate(int one)
{
    int usedcount;
    if (one > 9999999999)
        return 1;
    for (usedcount = 0; usedcount < 10; usedcount++)
        used[usedcount] = 0;
    while (one != 0) {
        if (used[one%10])
            return 1;
        used[one%10] = 1;
        one /= 10;
    }
    return 0;
}

/* this function checks if all the digits have appeared in the number */

int check_all_digits(int one,int two)
{
    int i;
    for(i=1; i<10; i++)
    {
        if(used[i] == 0)
            return 0;
    }
    return 1;
}
