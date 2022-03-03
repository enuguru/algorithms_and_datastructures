

/* Dynamic Programming implementation of
   Max sum problem in a triangle */
#include<bits/stdc++.h>
using namespace std;
#define N 3
 
//  Function for finding maximum sum
int maxPathSum(int tri[][N], int m, int n)
{
     // loop for bottom-up calculation
     for (int i=m-1; i>=0; i--)
     {
        for (int j=0; j<=i; j++)
        {
            // for each element, check both
            // elements just below the number
            // and below right to the number
            // add the maximum of them to it
            if (tri[i+1][j] > tri[i+1][j+1])
                tri[i][j] += tri[i+1][j];
            else
                tri[i][j] += tri[i+1][j+1];
        }
     }
 
     // return the top element
     // which stores the maximum sum
     return tri[0][0];
}
 

int main()
{
   int tri[N][N] = {  {1, 0, 0},
                      {4, 8, 0},
                      {1, 5, 3} };
   cout << maxPathSum(tri, 2, 2) << "\n";
   return 0;
}
