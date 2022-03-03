/* CH3PR1.C: Program to perform some basic operations on string. */

#include <stdio.h>
#include <conio.h>
#include <string.h>

int xstrlen ( char * ) ;
void xstrcpy ( char *, char * ) ;
void xstrcat ( char *, char * ) ;
int xstrcmp ( char *, char * ) ;
void show ( char * ) ;

void main( )
{
	char s1[ ] = "kicit" ;
	char s2[ ] = "Nagpur" ;
	char s3[20] ;
	int len ;

	clrscr( ) ;

	printf ( "\nString s1: %s", s1 ) ;
	len = xstrlen ( s1 ) ;
	printf ( "\nlength of the string s1: %d", len ) ;

	printf ( "\nString s2: %s", s2 ) ;

	xstrcpy ( s3, s1 ) ;
	printf ( "\nString s3 after copying s1 to it: %s", s3 ) ;

	xstrcat ( s3, s2 ) ;
	printf ( "\nString s3 after concatenation: %s", s3 ) ;

	if ( xstrcmp ( s1, s2 ) == 0 )
		printf ( "\nThe strings s1 and s2 are similar" ) ;
	else
		printf ( "\nThe strings s1 and s2 are not similar" ) ;

	getch( ) ;
}

/* finds the length of the string */
int xstrlen ( char *s )
{
	int l = 0 ;
	while ( *s )
	{
		l++ ;
		s++ ;
	}
	return l ;
}

/* copies source string s to the target string t */
void xstrcpy ( char *t, char *s )
{
	while ( *s )
	{
		*t = *s ;
		t++ ;
		s++ ;
	}
	*t = '\0' ;
}

/* concatenates the two strings */
void xstrcat ( char *t, char *s )
{
	while ( *t )
		t++ ;
	while ( *s )
		*t++ = *s++ ;
	*t = '\0' ;
}

/* compares two strings s and t for equality */
int xstrcmp ( char *s, char *t )
{
	while ( *s == *t )
	{
		if ( ! ( *s ) )
			return 0 ;
		s++ ;
		t++ ;
	}
	return ( *s - *t ) ;
}