
#include <stdio.h>

int main()
{
    void PrintSpiral();
    PrintSpiral();
    return 0;
}


void PrintSpiral()
{
    int top,bottom,left,right;
    int columns,loopcount,rows,direction;
    columns = 5;
    rows = 4;
    int twoD_Array[4][5] =  {
        {2, 4, 6,  8, 21},
        {5, 9, 12, 16, 33},
        {2, 11, 5,  9, 79},
        {3, 2,  1,  8, 53}
    };

    top=0;
    bottom = rows-1;
    left = 0;
    right = columns-1;
    direction = 0;
    while( top <= bottom  &&  left <= right)
    {
        if(direction == 0)
        {
            for( loopcount = left; loopcount <= right; loopcount++)
                printf("%d ", twoD_Array[top][loopcount]);
            top++;
            direction = 1;
        }
        else if( direction == 1)
        {
            for( loopcount = top; loopcount <= bottom; loopcount++)
                printf("%d ", twoD_Array[loopcount][right]);
            right--;
            direction = 2;
        }
        else if(direction == 2)
        {
            for( loopcount = right; loopcount >= left; loopcount--)
                printf("%d ", twoD_Array[bottom][loopcount]);
            bottom--;
            direction = 3;
        }
        else if(direction == 3)
        {
            for( loopcount = bottom; loopcount >= top; loopcount--)
                printf("%d ", twoD_Array[loopcount][left]);
            left++;
            direction = 0;
        }
    }
    printf("\n");
}
