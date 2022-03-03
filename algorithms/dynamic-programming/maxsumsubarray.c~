
/*
Algorithmic Paradigm: Dynamic Programming

The implementation handles the case when all numbers in array are negative.
*/

#include<stdio.h>

int max(int x, int y)
{
    return (y > x)? y : x;
}

int maxSubArraySum(int a[], int size)
{
    int max_so_far = a[0], i;
    int curr_max = a[0];

    for (i = 1; i < size; i++)
    {
        curr_max = max(a[i], curr_max+a[i]);
        //printf(" %d",curr_max);
        max_so_far = max(max_so_far, curr_max);
        printf(" %d",max_so_far);
    }
    return max_so_far;
}


int main()
{
    int a[] =  {-2, -3, 4, 5, -4, 23, 1, -7, 2}; // -2, -2, 4, 5, 28, 29, 22, 24
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    printf("Maximum contiguous sum is %d\n", max_sum);
    return 0;
}
