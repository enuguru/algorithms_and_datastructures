
// brute force algorithm - 3 for loops

#include<stdio.h>

int maxSubArraySum(int a[], int size)
{
    int max_so_far = 0;
    int sum;
    int n = size;
    for(int i = 0; i<n; i++)
    {
       for(int j = i; j<n; j++)
       {  
          sum = 0;
          for(int k = i; k<=j; k++)
             sum = sum + a[k];
          if(sum > max_so_far)
             max_so_far = sum;
       }
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
