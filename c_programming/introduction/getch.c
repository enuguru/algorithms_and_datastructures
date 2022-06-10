// C program to implement
// the putch() functions
#include <conio.h>
#include <stdio.h>

// Driver code
int main()
{
	char ch;
	printf("Enter any character:\n ");

	// Reads a character from the keyboard
	ch = getch();

	printf("\nEntered character is: ");

	// Displays that character on the console
	putch(ch);
	return 0;
}
