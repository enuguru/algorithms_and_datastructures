
#include<stdio.h>

enum color {
  red,
  green,
  blue
};

int main() 
{
  // Initializing a variable that will hold the enums
  enum color current_color = red;
	printf("Value of red = %d \n", current_color);	

	current_color = green;
	printf("Value of green = %d \n", current_color);	

	current_color = blue;
	printf("Value of blue = %d \n", current_color);	
	return 0;
}


