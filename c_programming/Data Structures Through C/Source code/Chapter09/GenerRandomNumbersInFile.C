/* Program that creates random numbers in a given file. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main( )
{
	FILE *fp ;
	char str [ 67 ] ;
	int i, noofr, j ;

	clrscr( ) ;

	printf ( "Enter file name: " ) ;
	scanf ( "%s", str ) ;

	printf ( "Enter number of records: " ) ;
	scanf ( "%d", &noofr ) ;

	fp = fopen ( str, "wb" ) ;
	if ( fp == NULL )
	{
		printf ( "Unable to create file." ) ;
		getch( ) ;
		exit ( 0 ) ;
	}

	randomize( ) ;

	for ( i = 0 ; i < noofr ; i++ )
	{
		j = random ( 1000 ) ;
		fwrite ( &j, sizeof ( int ), 1, fp ) ;
		printf ( "%d\t", j ) ;
	}

	fclose ( fp ) ;

	printf ( "\nFile is created. \nPress any key to continue." ) ;

	getch( ) ;
}