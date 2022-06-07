/* Program of towers of hanoi. */

#include <stdio.h>
#include <conio.h>

void move ( int, char, char, char ) ;

void main( )
{
	int n = 3 ;

	clrscr( ) ;

	move ( n, 'A', 'B', 'C' ) ;

	getch( ) ;
}

void move ( int n, char sp, char ap, char ep )
{
	if ( n == 1 )
		printf ("\nMove from %c to %c ", sp, ep ) ;
	else
	{
		move ( n - 1, sp, ep, ap ) ;
		move ( 1, sp, ' ', ep ) ;
		move ( n - 1, ap, sp, ep ) ;
	}
}

