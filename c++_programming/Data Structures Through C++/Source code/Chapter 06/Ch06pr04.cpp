// Program Ch06pr04
// Program to convert an Infix form to Postfix form

#include <iostream.h>
#include <string.h>
#include <ctype.h>

const int MAX = 50 ;

class infix
{
	private :

		char target[MAX], stack[MAX] ;
		char *s, *t ;
		int top ;

	public :

		infix( ) ;
		void setexpr ( char *str ) ;
		void push ( char c ) ;
		char pop( ) ;
		void convert( ) ;
		int priority ( char c ) ;
		void show( ) ;
} ;

// initializes data members
infix :: infix( )
{
	top = -1 ;
	strcpy ( target, "" ) ;
	strcpy ( stack, "" ) ;
	t = target ;
	s = ""  ;
}

// sets s to point to given expr.
void infix :: setexpr ( char *str )
{
	s = str ;
}

// adds an operator to the stack
void infix :: push ( char c )
{
	if ( top == MAX )
		cout << "\nStack is full\n" ;
	else
	{
		top++ ;
		stack[top] = c ;
	}
}

// pops an operator from the stack
char infix :: pop( )
{
	if ( top == -1 )
	{
		cout << "\nStack is empty\n" ;
		return -1 ;
	}
	else
	{
		char item = stack[top] ;
		top-- ;
		return item ;
	}
}

// converts the given expr. from infix to postfix form
void infix :: convert( )
{
	while ( *s )
	{
		if ( *s == ' ' || *s == '\t' )
		{
			s++ ;
			continue ;
		}
		if ( isdigit ( *s ) || isalpha ( *s ) )
		{
			while ( isdigit ( *s ) || isalpha ( *s ) )
			{
				*t = *s ;
				s++ ;
				t++ ;
			}
		}
		if ( *s == '(' )
		{
			push ( *s ) ;
			s++ ;
		}
		char opr ;
		if ( *s == '*' || *s == '+' || *s == '/' || *s == '%' || *s == '-' || *s == '$' )
		{
			if ( top != -1 )
			{
				opr = pop( ) ;
				while ( priority ( opr ) >= priority ( *s ) )
				{
					*t = opr ;
					t++ ;
					opr = pop( ) ;
				}
				push ( opr ) ;
				push ( *s ) ;
			}
			else
				push ( *s ) ;
			s++ ;
		}

		if ( *s == ')' )
		{
			opr = pop( ) ;
			while ( ( opr ) != '(' )
			{
				*t = opr ;
				t++ ;
				opr =  pop( ) ;
			}
			s++ ;
		}
	}

	while ( top != -1 )
	{
		char opr = pop( ) ;
		*t = opr ;
		t++ ;
	}

	*t = '\0' ;
}

// returns the priority of an operator
int infix :: priority ( char c )
{
	if ( c == '$' )
		return 3 ;
	if ( c == '*' || c == '/' || c == '%' )
		return 2 ;
	else
	{
		if ( c == '+' || c == '-' )
			return 1 ;
		else
			return 0 ;
	}
}

// displays the postfix form of given expr.
void infix :: show( )
{
    cout << target ;
}

void main( )
{
	char expr[MAX] ;
	infix q ;

	cout << "\nEnter an expression in infix form: " ;
	cin.getline ( expr, MAX ) ;

	q.setexpr ( expr ) ;
	q.convert( ) ;

	cout << "\nThe postfix expression is: " ;
	q.show( ) ;
}