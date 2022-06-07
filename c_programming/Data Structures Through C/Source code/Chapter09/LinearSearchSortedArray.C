/* Linear search in a sorted array. */

#include <stdio.h>
#include <conio.h>

void main( )
{
	int arr[10] = { 1, 2, 3, 9, 11, 13, 17, 25, 57, 90 } ;
	int i, num ;

	clrscr( ) ;

	printf ( "Enter number to search: " ) ;
	scanf ( "%d", &num ) ;

	for ( i = 0 ; i <= 9 ; i++ )
	{
		if ( arr[9] < num || arr[i] >= num )
		{
			if ( arr[i] == num )
				printf ( "The number is at position %d in the array.", i ) ;
			else
				printf ( "Number is not present in the array." ) ;
			break ;
		}
	}

	getch( ) ;
}
