// Program Ch10pr01
// Program to implement the depth first search algorithm.

#include <iostream.h>

#define TRUE 1
#define FALSE 0

const int MAX = 8 ;

struct node
{
	int data ;
	node *next ;
} ;

class graph
{
	private :

		int visited[MAX] ;

	public :

		graph( ) ;
		void dfs ( int v, node **p ) ;
		node* getnode_write ( int val ) ;
		void del ( node *n ) ;
} ;

// initialises data member
graph :: graph( )
{
    for ( int i = 0 ; i < MAX ; i++ )
        visited[i] = FALSE ;
}

// function that has implemented
// depth first search algorithm
void graph :: dfs ( int v, node **p )
{
	node *t ;
	visited[v - 1] = TRUE ;

	cout << v << "\t" ;

	t = * ( p + v - 1 ) ;

	while ( t != NULL )
	{
		if ( visited[t -> data - 1] == FALSE )
			dfs ( t -> data, p ) ;
		else
			t = t -> next ;
	}
}

// creates a node
node* graph :: getnode_write ( int val )
{
	node *newnode = new node ;
	newnode -> data = val ;
	return newnode ;
}

// deallocates memory
void graph :: del ( node *n )
{
	node *temp ;

	while ( n != NULL )
	{
		temp = n -> next ;
		delete n ;
		n = temp ;
	}
}

void main( )
{
	node *arr[MAX] ;
	node *v1, *v2, *v3, *v4 ;

	graph g ;
	v1 = g.getnode_write ( 2 ) ;
	arr[0] = v1 ;
	v1 -> next = v2 = g.getnode_write ( 3 ) ;
	v2 -> next = NULL ;

	v1 = g.getnode_write ( 1 ) ;
	arr[1] = v1 ;
	v1 -> next = v2 = g.getnode_write ( 4 ) ;
	v2 -> next = v3 = g.getnode_write ( 5 ) ;
	v3 -> next = NULL ;

	v1 = g.getnode_write ( 1 ) ;
	arr[2] = v1 ;
	v1 -> next = v2 = g.getnode_write ( 6 ) ;
	v2 -> next = v3 = g.getnode_write ( 7 ) ;
	v3 -> next = NULL ;

	v1 = g.getnode_write ( 2 ) ;
	arr[3] = v1 ;
	v1 -> next = v2 = g.getnode_write ( 8 ) ;
	v2 -> next = NULL ;

	v1 = g.getnode_write ( 2 ) ;
	arr[4] = v1 ;
	v1 -> next = v2 = g.getnode_write ( 8 ) ;
	v2 -> next = NULL ;

	v1 = g.getnode_write ( 3 ) ;
	arr[5] = v1 ;
	v1 -> next = v2 = g.getnode_write ( 8 ) ;
	v2 -> next = NULL ;

	v1 = g.getnode_write ( 3 ) ;
	arr[6] = v1 ;
	v1 -> next = v2 = g.getnode_write ( 8 ) ;
	v2 -> next = NULL ;

	v1 = g.getnode_write ( 4 ) ;
	arr[7] = v1 ;
	v1 -> next = v2 = g.getnode_write ( 5 ) ;
	v2 -> next = v3 = g.getnode_write ( 6 ) ;
	v3 -> next = v4 = g.getnode_write ( 7 ) ;
	v4 -> next = NULL ;

	cout << endl ;
	g.dfs ( 1, arr ) ;

	for ( int i = 0 ; i < MAX ; i++ )
		g.del ( arr[i] ) ;
}

