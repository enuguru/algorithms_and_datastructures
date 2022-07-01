/* Program that creates random numbers in a given file. */

#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main( )
{
	FILE *fp ;
	char str[67] ;
	int i, noofr, j ;

	clrscr( ) ;

	cout << "Enter file name: " ;
	cin >> str ;

	cout << "Enter number of records: " ;
	cin >> noofr ;

	fp = fopen ( str, "wb" ) ;
	if ( fp == NULL )
	{
		cout << "Unable to create file." ;
		exit ( 0 ) ;
	}

	randomize( ) ;

	for ( i = 0 ; i < noofr ; i++ )
	{
		j = random ( 1000 ) ;
		fwrite ( &j, sizeof ( int ), 1, fp ) ;
		cout << j << "\t" ;
	}

	fclose ( fp ) ;

	cout << "\nFile is created. \nPress any key to continue." ;
}