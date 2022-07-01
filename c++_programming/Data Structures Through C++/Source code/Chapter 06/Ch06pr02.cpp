// Program Ch06pr02
// Program implements linked list as a stack

#include <iostream.h>

class stack
{
	private :

    	// structure containing data part and linkpart
		struct node
		{
			int data ;
			node *link ;
		} *top ;

	public :

		stack( ) ;
		void push ( int item ) ;
		int pop( ) ;
		~stack( ) ;
} ;

// initializes data member
stack :: stack( )
{
	top = NULL ;
}

// adds a new node to the stack as linked list
void stack :: push ( int item )
{
	node *temp ;
	temp = new node ;

	if ( temp == NULL )
		cout << endl << "Stack is full" ;

	temp -> data = item ;
	temp -> link = top ;
	top = temp ;
}

// pops an element from the stack
int stack :: pop( )
{
	if ( top == NULL )
	{
		cout << endl << "Stack is empty" ;
		return NULL ;
	}

	node *temp ;
	int item ;

	temp = top ;
	item = temp -> data ;
	 top = top -> link ;

	delete temp ;
	return item ;
}

// deallocates memory
stack :: ~stack( )
{
	if ( top == NULL )
		return ;

	node *temp ;
	while ( top != NULL )
	{
		temp = top ;
		top = top -> link ;
		delete temp ;
	}
}

void main( )
{
	stack s ;

	s.push ( 14 ) ;
	s.push ( -3 ) ;
	s.push ( 18 ) ;
	s.push ( 29 ) ;
	s.push ( 31 ) ;
	s.push ( 16 ) ;

	int i = s.pop( ) ;
	cout << "\nItem popped: " << i ;

	i = s.pop( ) ;
	cout << "\nItem popped: " << i ;

	i = s.pop( ) ;
	cout << "\nItem popped: " << i ;
}

