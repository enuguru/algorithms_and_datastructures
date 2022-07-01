// Program on stack
// Towers of Hanoi

#include <iostream.h>

void main()
{
	int n = 3 ;
	void move ( int, char, char, char ) ;
	move ( n, 'A', 'B', 'C' ) ;
}

void move ( int n, char sp, char ap, char ep )
{
     if ( n == 1 )
          cout << "\nMove from " << sp << " to " << ep  ;
     else
     {
	  move ( n - 1, sp, ep, ap ) ;
	  move ( 1, sp, ' ', ep ) ;
	  move ( n - 1, ap, sp, ep ) ;
     }
}