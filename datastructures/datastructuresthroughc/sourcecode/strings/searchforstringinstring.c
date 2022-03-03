/* CH3PR5.C: Program to search for a string into another string. */

#include <stdio.h>
#include <conio.h>
#include <string.h>

int xstrsearch ( char *, char * ) ;
void show( ) ;

void main( )
{
	char s1[ ] = "NagpurKicit" ;
	char s2[ ] = "Kicit" ;
	int pos ;

	clrscr( ) ;

	printf ( "String s1: %s\n", s1 ) ;

	printf ( "String s2: %s\n", s2 ) ;

	/* search if s2 is present in s1 */
	pos = xstrsearch ( s1, s2 ) ;
	printf ( "\nThe pattern string is found at position: %d\n", pos ) ;

	getch( ) ;
}

/* searches for the given pattern s2 into the string s1 */
int xstrsearch ( char * s1, char * s2 )
{
	int i, j, k ;
	int l1 = strlen ( s1 ) ;
	int l2 = strlen ( s2 ) ;

	for ( i = 0 ; i <= l1 - l2 ; i++ )
	{
		j = 0 ;
		k = i ;
		while ( ( s1[k] == s2[j] ) && ( j < l2 ) )
		{
			k++ ;
			j++ ;
		}
		if ( j == l2 )
			return i ;
	}
	return -1 ;
}