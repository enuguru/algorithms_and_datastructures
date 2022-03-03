
/* Magic Square */

#include <stdio.h>

int main(void)
{
    int size, col, row, i;
     
    printf("\nThis program creates a \"magic square\" of specified size.");
    printf("\nThe size must be an odd number.");
    printf("\nBeyond size 99 some numbers will have no space between.");
    printf("\nEnter size: ");
    scanf(" %d", &size);
     
    short square[size][size];  /* Declare a two-dimensional array of size x size */
     
    for (row = 0; row < size; ++row)          /*******************************************/
        for (col = 0; col < size; ++col)  /* Give every element in the array value 0 */
            square[row][col] = 0;     /*******************************************/
             
    row = 0;               /***************************************/
    col = size / 2;        /* Place the first number in the array */
    square[row][col] = 1;  /***************************************/
             
    for (i = 2; i <= size * size; ++i)
    {                                       
        if (--row < 0)             /*****************************************************/
            row = (size - 1);  /* Evaluate the indexes to the next position,    */
                                           /* wrapping around to the opposite side, everytime   */
        if (++col > (size - 1))    /* an index goes outside the bounds of the array.    */
            col = 0;           /*****************************************************/
             
        if (square[row][col] != 0)  /* Check if a number is already placed in the new position */
        {
            if (++row > (size - 1))    /***********************************************/
                row = 0;           /* Evaluate indexes to the previous position,  */
                                                   /* wrapping to the opposite side, everytime an */
            if (--col < 0)             /* index goes outside the bounds of the array  */
                col = (size - 1);  /***********************************************/
                 
            while (square[row][col] != 0)    /*****************************************/
                if (++row > (size - 1))  /* Evaluate indexes to the first 0 value */
                    row = 0;         /* element, below the last placed number */
        }                                        /*****************************************/
         
        square[row][col] = i;  /* Place the next number in the array */
    }
         
    for (row = 0; row < size; ++row)
    {
        printf("\n");
        for (col = 0; col < size; ++col)
            printf("%5d", square[row][col]);
    }
    printf("\n");
     
    return 0;
}

