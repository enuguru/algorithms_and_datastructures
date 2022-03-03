
#include <stdio.h>

int hasDupes (unsigned int n) {
    // Flag to indicate digit has been used.

    int i, used[10];

    // Must have dupes if more than ten digits.

    if (n > 9999999999)
        return 1;

    // Initialise dupe flags to false.

    for (i = 0; i < 10; i++)
        used[i] = 0;

    // Process all digits in number.

    while (n != 0) {
        // Already used? Return true.

        if (used[n%10])  // you can cache n%10 if compiler not too smart.
            return 1;

        // Otherwise, mark used, go to next digit.

        used[n%10] = 1;  // and you would use cached value here.
        n /= 10;
    }

    // No dupes, return false.

    return 0;
}


int main()
{
    unsigned int number;
    for(number = 1; number <=600; number++)
    {
    if(!hasDupes(number*number))
    {
       printf("The number has no duplicates\n");
       printf("%d  ",number);
       printf("%d  ",number*number);
    }
    }
    return 0;
}
