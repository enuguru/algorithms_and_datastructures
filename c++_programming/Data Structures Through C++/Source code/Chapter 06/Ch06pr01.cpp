// Program Ch06pr01
// Program implements array as a stack

#include <iostream.h>

const int MAX = 10 ;

class stack
{
	private :

		int arr[MAX] ;
		int top ;

	public :

		stack( ) ;
		void push ( int item ) ;
		int pop( ) ;
} ;

// initializes data member
stack :: stack( )
{
	top = -1 ;
}

// adds an element to the stack
void stack :: push ( int item )
{
	if ( top == MAX - 1 )
	{
		cout << endl << "Stack is full" ;
		return ;
	}
	top++ ;
	arr[top] = item ;
}

// removes an element from the stack
int stack :: pop( )
{
	if ( top == -1 )
	{
		cout << endl << "Stack is empty" ;
		return NULL ;
	}
	int data = arr[top] ;
	top-- ;
	return data ;
}

void main( )
{
	stack s ;

	s.push ( 11 ) ;
	s.push ( 23 ) ;
	s.push ( -8 ) ;
	s.push ( 16 ) ;
	s.push ( 27 ) ;
	s.push ( 14 ) ;
	s.push ( 20 ) ;
	s.push ( 39 ) ;
	s.push ( 2 ) ;
	s.push ( 15 ) ;
	s.push ( 7 ) ;

	int i = s.pop( ) ;
	cout << "\n\nItem popped: " << i ;

	i = s.pop( ) ;
	cout << "\nItem popped: " << i ;

	i = s.pop( ) ;
	cout << "\nItem popped: " << i ;

	i = s.pop( ) ;
	cout << "\nItem popped: " << i ;

	i = s.pop( ) ;
	cout << "\nItem popped: " << i ;
}
