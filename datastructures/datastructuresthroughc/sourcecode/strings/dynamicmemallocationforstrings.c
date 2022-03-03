/* CH3PR4.C: Program to allocate memory dynamically for strings, and store
			 their addresses in array of pointers to strings. */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <string.h>

void main( )
{
	char *name[5] ;
	char str[20] ;
	int i ;

	clrscr( ) ;

	for ( i = 0 ; i < 5 ; i++ )
	{
		printf ( "Enter a String: " ) ;
		gets ( str ) ;
		name[i] = ( char * ) malloc ( strlen ( str ) + 1 ) ;
		strcpy ( name[i], str ) ;
	}

	printf ( "\nThe strings are:" ) ;

	for ( i = 0 ; i < 5 ; i++ )
		printf ( "\n%s", name[i] ) ;

	for ( i = 0 ; i < 5 ; i++ )
		free ( name[i] ) ;

	getch( ) ;
}