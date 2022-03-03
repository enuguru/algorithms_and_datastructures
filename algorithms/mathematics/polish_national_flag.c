
#include <stdio.h>
int main()
{
    int p,q;
    int count_var,count_var_one;
    enum colour
    {
	red, 
        green
    };
    enum colour col_ball_array[] = {red,green,red,red,green,green,red,green,red,red};
    char *colournames[] = {"red  ","green","red  ","red  ","green","green","red  ","green","red  ","red  "};
    for(count_var = 0; count_var < 10; count_var++)
    {
	printf("%s  ",colournames[count_var]);
    }  
    p = 0;
    q = 9;
    while (p <= q) 
    {
        while((col_ball_array[p] == red) && p<=q) 
        {
            p = p + 1;
        }
        while((col_ball_array[q] == green) && p<=q) 
        {
            q = q -1;
        }
        if(p < q) 
        {
            col_ball_array[p] = red; 
            colournames[p] = "red  "; 
            col_ball_array[q] = green; 
            colournames[q] = "green"; 
        }
    }
    count_var_one =0;
    printf("\n\n");
    for(;count_var_one < 10;count_var_one++)
    {
	printf("%s\n",colournames[count_var_one]);
    }
    return 0;
}
