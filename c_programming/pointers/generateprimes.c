
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of primes you want to generate: ");
    scanf("%d",&n);
    
    // create an array of n elements
    int primes[n];
    
    // initialize the array with 0
    for(int i=0;i<n;i++)
    {
        primes[i] = 0;
    }
    
    // initialize the first two elements with 1
    primes[0] = 1;
    primes[1] = 1;
    
    // find the square root of n
    int root = sqrt(n);
    
    // loop through the array
    for(int i=2;i<=root;i++)
    {
        // if the element is 0, then it is a prime
        if(primes[i] == 0)
        {
            // loop through the array and mark all the multiples of i as 1
            for(int j=i*i;j<n;j+=i)
            {
                primes[j] = 1;
            }
        }
    }
    
    // print the primes
    for(int i=0;i<n;i++)
    {
        if(primes[i] == 0)
        {
            printf("%d ",i);
        }
    }
    printf("\n");
    
    return 0;
}
