// Extra Program
// Program on deque that implements a linked list

#include <iostream.h>
#include <conio.h>
#include <alloc.h>

struct node
{
	int data ;
	node *link ;
} ;

class dqueue
{
	private :

		node *front, *rear ;

	public :

		dqueue( ) ;
		void addqatend ( int item ) ;
		void addqatbeg ( int item ) ;
		int delqatbeg( ) ;
		int delqatend( ) ;
		void display( ) ;
		int count( ) ;
		~dqueue( ) ;
} ;

dqueue :: dqueue( )
{
	front = rear = NULL ;
}

void dqueue :: addqatend ( int item )
{
	node *temp ;

	temp = new node ;
	temp -> data = item ;
	temp -> link = NULL ;

	if ( front == NULL )
		front = temp ;
	else
		rear -> link = temp ;
	rear = temp ;
}

void dqueue :: addqatbeg ( int item )
{
	node *temp ;
	int *q ;
	temp = new node ;
	temp -> data = item ;
	temp -> link = NULL ;

	if ( front == NULL )
		front = rear = temp ;
	else
	{
		temp -> link = front ;
		front = temp ;
	}
}

int dqueue :: delqatbeg ( )
{
	node *temp = front ;
	int item ;
	if ( temp == NULL )
	{
		cout << endl << "queue is empty " ;
		return 0 ;
	}
	else
	{
		temp = front ;
		item = temp -> data ;
		front = temp -> link ;
		delete ( temp ) ;

		if ( temp == NULL )
			rear = NULL ;
		return ( item ) ;
	}
}

int dqueue :: delqatend (  )
{
	node *temp , *rleft, *q ;
	int item ;
	temp = front ;
	if ( rear == NULL )
	{
		cout << endl << " queue is empty ";
		return 0 ;
	}
	else
	{
		while ( temp != rear )
		{
			rleft = temp ;
			temp = temp -> link ;
		}
		q = rear ;
		item = q -> data ;
		delete ( q ) ;
		rear = rleft ;
		( rear ) -> link = NULL ;
		if ( rear == NULL )
			front = NULL ;
		return ( item ) ;
	}
}

void dqueue :: display( )
{
	node *temp = front ;

	cout << endl << "front->" ;
	while ( temp != NULL )
	{
		if ( temp -> link == NULL )
		{
			cout << "  " << temp -> data ;
			cout << " <- rear" ;
		}
		else
			cout << "  " << temp -> data ;
		temp = temp -> link ;
	}
	cout << endl ;
}

int dqueue :: count ( )
{
	int c = 0 ;
	node *temp = front ;
	while ( temp != NULL )
	{
		temp = temp -> link ;
		c++ ;
	}
	return c ;
}

dqueue :: ~dqueue( )
{
	if ( front == NULL )
		return ;
	node *temp ;
	while ( front != NULL )
	{
		temp = front ;
		front = front -> link ;
		delete temp ;
	}
}

void main( )
{
	dqueue a ;

	a.addqatend ( 11 ) ;
	a.addqatbeg ( 10 ) ;
	a.addqatend ( 12 ) ;
	a.addqatbeg ( 9 ) ;
	a.addqatend ( 13 ) ;
	a.addqatbeg ( 8 ) ;
	a.addqatend ( 14 ) ;
	a.addqatbeg ( 7 ) ;

	a.display( ) ;

	int n = a.count( ) ;
	cout << endl << "Total elements " << n ;

	int i = a.delqatbeg( ) ;
	cout << "\nItem extracted = " << i ;

	i = a.delqatbeg( ) ;
	cout << "\nItem extracted = " << i ;

	i = a.delqatbeg( ) ;
	cout << "\nItem extracted = " << i ;

	i =	 a.delqatend( ) ;
	cout << "\nItem extracted = " << i ;

	a.display( ) ;
	n = a.count( ) ;
	cout << endl << "Elements Left " << n ;
}