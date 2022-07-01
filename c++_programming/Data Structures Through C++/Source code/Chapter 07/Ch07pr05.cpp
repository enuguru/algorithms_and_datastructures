// Program Ch07pr05
// Program that implements a priority queue using an array

#include <iostream.h>
#include <string.h>

const int MAX = 5 ;

class pque
{
	private :

		struct data
		{
			char job[MAX] ;
			int prno ;
			int ord ;
		} d[MAX] ;

		int front, rear ;

	public :

		pque( ) ;
		void add ( data dt ) ;
		data remove( ) ;
} ;

// initialises data members
pque :: pque( )
{
	front = rear = -1 ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		strcpy ( d[i].job, '\0' ) ;
		d[i].prno = d[i].ord = 0 ;
	}
}

// adds item to the priority queue
void pque :: add ( data dt )
{
	if ( rear == MAX - 1 )
	{
		cout << "\nQueue is full" ;
		return ;
	}

	rear++ ;
	d[rear] = dt ;

	if ( front == -1 )
	front = 0 ;

	data temp ;
	for ( int i = front ; i <= rear ; i++ )
	{
		for ( int j = i + 1 ; j <= rear ; j++ )
		{
			if ( d[i].prno > d[j].prno )
			{
				temp = d[i] ;
				d[i] = d[j] ;
				d[j] = temp ;
			}
			else
			{
				if ( d[i].prno == d[j].prno )
				{
					if ( d[i].ord > d[j].ord )
					{
						temp = d[i] ;
						d[i] = d[j] ;
						d[j] = temp ;
					}
				}
			}
		}
	}
}

// removes item from priority queue
data pque :: remove( )
{
	data  t ;
	strcpy ( t.job, "" ) ;
	t.prno = 0 ;
	t.ord = 0 ;

	if ( front == -1 )
	{
		cout << "\nQueue is Empty" << endl ;
		return t ;
	}

	t = d[front] ;
	d[front] = t ;
	if ( front == rear )
		 front = rear = -1 ;
	else
		 front++ ;

	return  t ;
}

void main( )
{
	pque q ;

	data dt ;
	int j = 0 ;

	cout << "Enter Job description (max 4 chars) and its priority" << endl ;
	cout << "Lower the priority number, higher the priority" ;
	cout << "Job      Priority" << endl ;

	for ( int i = 0 ; i < MAX ; i++ )
	{
		cin >> dt.job >> dt.prno ;
		dt.ord = j++ ;
		q.add ( dt ) ;
	}
	cout << endl ;

	cout << "Process jobs prioritywise" << endl ;
	cout << "Job   Priority" << endl ;

	for ( i = 0 ; i < MAX ; i++ )
	{
		data temp  =  q.remove( ) ;
		cout << temp.job << "             " << temp.prno << endl ;
	}
	cout << endl ;
}
