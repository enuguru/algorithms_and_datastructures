// Program Ch10pr03
// Program to find the minimum cost of a spanning tree.

#include <iostream.h>

const int MAX = 5 ;

struct lledge
{
	int v1, v2 ;
	float cost ;
	lledge *next ;
} ;

int stree[MAX] ;
int count[MAX] ;
int mincost ;

lledge* create ( int cr1, int vr2, int cs ) ;
lledge* kminstree ( lledge *root, int n ) ;
int getrval ( int i ) ;
void combine ( int i, int j ) ;
void del ( lledge *root ) ;

lledge* kminstree ( lledge *root, int n )
{
	lledge *temp = NULL ;
	lledge *p, *q ;
	int noofedges = 0 ;
	int i, p1, p2 ;

	for ( i = 0 ; i < n ; i++ )
		stree[i] = i ;
	for ( i = 0 ; i < n ; i++ )
		count[i] = 0 ;

	while ( ( noofedges < ( n - 1 ) ) && ( root != NULL ) )
	{
		p = root ;

		root = root -> next ;

		p1 = getrval ( p -> v1 ) ;
		p2 = getrval ( p -> v2 ) ;

		if ( p1 != p2 )
		{
			combine ( p -> v1, p -> v2 ) ;
			noofedges++ ;
			mincost += p -> cost ;
			if ( temp == NULL )
			{
				temp = p ;
				q = temp ;
			}
			else
			{
				q -> next = p ;
				q = q -> next ;
			}
			q -> next = NULL ;
		}
	}
	return temp ;
}

int getrval ( int i )
{
	int j, k, temp ;
	k = i ;
	while ( stree[k] != k )
		k = stree[k] ;
	j = i ;
	while ( j != k )
	{
		temp = stree[j] ;
		stree[j] = k ;
		j = temp ;
	}
	return k ;
}

void combine ( int i, int j )
{
	if ( count[i] < count[j] )
		stree[i] = j ;
	else
	{
		stree[j] = i ;
		if ( count[i] == count[j] )
			count[j]++ ;
	}
}

void del ( lledge *root )
{
	lledge *temp ;

	while ( root != NULL )
	{
		temp = root -> next ;
		delete root ;
		root = temp ;
	}
}

void main( )
{
	lledge *temp, *root ;
	int i ;

	root = new lledge ;

	root -> v1 = 4 ;
	root -> v2 = 3 ;
	root -> cost = 1 ;
	temp = root -> next = new lledge ;

	temp -> v1 = 4 ;
	temp -> v2 = 2 ;
	temp -> cost = 2 ;
	temp -> next = new lledge ;

	temp = temp -> next ;
	temp -> v1 = 3 ;
	temp -> v2 = 2 ;
	temp -> cost = 3 ;
	temp -> next = new lledge ;

	temp = temp -> next ;
	temp -> v1 = 4 ;
	temp -> v2 = 1 ;
	temp -> cost = 4 ;
	temp -> next = new lledge ;

	root = kminstree ( root, MAX ) ;

	for ( i = 1 ; i < MAX ; i++ )
		cout << "\nstree[" << i << "] -> " << stree[i] ;
	cout << "\nThe minimum cost of spanning tree is " << mincost ;

	del ( root ) ;
}
