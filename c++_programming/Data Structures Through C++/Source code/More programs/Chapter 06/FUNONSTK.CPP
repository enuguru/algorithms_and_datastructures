/* to show the use of stack in function calls */
#include <iostream.h>
#include <stdlib.h>
#include <dos.h>

unsigned int far *ptr ;
void ( *p )( void ) ;

void f1 ( void ) ;
void f2 ( void ) ;

main( )
{
	f1( ) ;
	f2( ) ;

	cout <<  "\nback to main..." ;
	exit ( 1 ) ;
}

void f1 ( void )
{
	ptr = ( unsigned int far * ) MK_FP ( _SS, _SP + 2 ) ;
	cout << endl << *ptr ;

	p = ( void ( * )( ) ) MK_FP ( _CS, *ptr ) ;
	( *p )( ) ;
	cout <<  "\nI am f1( ) function " ;
}

void f2 ( void )
{
	cout << "\nI am f2( ) function" ;
}
