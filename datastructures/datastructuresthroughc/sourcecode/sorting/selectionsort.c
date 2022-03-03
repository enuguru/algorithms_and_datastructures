/* Selection sort. */

#include <stdio.h>
#include <conio.h>

void main( )
{
	int arr[5] = { 25, 17, 31, 13, 2 } ;
	int i, j, temp ;

	clrscr( ) ;

	printf ( "Selection sort.\n" ) ;
	printf ( "\nArray before sorting:\n") ;

	for ( i = 0 ; i <= 4 ; i++ )
		printf ( "%d\t", arr[i] ) ;

	for ( i = 0 ; i <= 3 ; i++ )
	{
		for ( j = i + 1 ; j <= 4 ; j++ )
		{
			if ( arr[i] > arr[j] )
			{
				temp = arr[i] ;
				arr[i] = arr[j] ;
				arr[j] = temp ;
			}
		}
	}

	printf ( "\n\nArray after sorting:\n") ;

	for ( i = 0 ; i <= 4 ; i++ )
		printf ( "%d\t", arr[i] ) ;

	getch( ) ;
}
