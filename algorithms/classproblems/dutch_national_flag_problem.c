

#include <stdio.h>

void main()
{
	void dutchFlagSort(int[],int,int,int);
	int array_count, array_high, array_low, loop_count;
	int colourarray[11] = {0,2,2,0,1,1,2,2,0,0,1};
        array_count = 11; array_high = 2; array_low = 0;
	for(loop_count = 0; loop_count < array_count; loop_count++)
	{
		printf("%d\n",colourarray[loop_count]);
	}
        dutchFlagSort(colourarray,array_count,array_high,array_low);
}


void dutchFlagSort(int inArray[], int arraySize, int high, int low)
{
	int loop_count;
	if (arraySize == 0)
	    return;
	int lower = 0;
	while (inArray[lower] == low && lower < arraySize)
	    lower++;
	int upper = arraySize - 1;
	while (inArray[upper] == high && upper >= 0)
	    upper--;
	int temp = 0;
	int pivot;
	for (pivot = lower; pivot <= upper;)
	{
	    if (inArray[pivot] == low)
	    {
	      temp = inArray[pivot];
	      inArray[pivot] = inArray[lower];
	      inArray[lower] = temp;
	      pivot++;
	      lower++;
	    }
	    else if (inArray[pivot] == high)
	    {
	      temp = inArray[pivot];
	      inArray[pivot] = inArray[upper];
	      inArray[upper] = temp;
	      upper--;
	    }
	    else
	      pivot++;
	  }
	for(loop_count = 0; loop_count < arraySize; loop_count++)
	{
		printf("%d\n",inArray[loop_count]);
	}
}
