
/* Dynamic Programming Solution  */

#include<stdio.h>

void count( int S[], int m, int n )
{
    int i, j, x, y;

    // We need n+1 rows as the table is consturcted in bottom up manner using
    // the base case 0 value case (n = 0)
    int table[n+1][m];

    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
    {
        table[0][i] = 1;
        printf(" %d ",table[0][i]);
    }
    printf("\n");

    // Fill rest of the table enteries in bottom up manner
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;

            // total count
            table[i][j] = x + y;
            printf(" %d ", table[i][j]);
        }
        printf("\n");
    }
   // return table[n][m-1];
}


int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    count(arr,m,n);
 //   printf(" %d ", count(arr, m, n));
    return 0;
}
