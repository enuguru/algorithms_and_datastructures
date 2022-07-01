// Program Ch08pr01
// Program to build a binary search tree from arrays

#include <iostream.h>

class btree
{
	private :

		struct node
		{
			node *left ;
			char data ;
			node *right ;
		} *root ;

		char *arr ;
		int *lc ;
		int *rc ;

	public :

		btree ( char *a, int *l, int *r, int size ) ;
        void insert ( int index ) ;
		static node* buildtree ( char *a, int *l, int *r, int index ) ;
		void display( ) ;
		static void inorder ( node *sr ) ;
		~btree( ) ;
		static void del ( node *sr ) ;
} ;

// initialises data members
btree :: btree ( char *a, int *l, int *r, int size )
{
	root = NULL ;

	arr = new char[size] ;
	lc = new int[size] ;
	rc = new int[size] ;

	for ( int i = 0 ; i < size ; i++ )
	{
		* ( arr + i ) = * ( a + i ) ;
		* ( lc + i ) = * ( l + i ) ;
		* ( rc + i ) = * ( r + i ) ;
	}
}

// adds node to a tree by calling buildtree
void btree :: insert ( int index )
{
	root = buildtree ( arr, lc, rc, index ) ;
}

// builds binary tree
node* btree :: buildtree ( char *a, int *l, int *r, int index )
{
	node *temp = NULL ;
	if ( index != -1 )
	{
		temp = new node ;
		temp -> left = buildtree ( a, l, r, * ( l + index ) ) ;
		temp -> data = * ( a + index ) ;
		temp -> right = buildtree ( a, l, r, * ( r + index ) ) ;
	}
	return temp ;
}

// calls inorder to traverse a binary tree
void btree :: display( )
{
	inorder ( root ) ;
}

// displays data stored in a binary tree
void btree :: inorder ( node *sr )
{
	if ( sr != NULL )
	{
		inorder ( sr -> left ) ;
		cout << sr -> data << "\t" ;
		inorder ( sr -> right ) ;
	}
}

// calls del to deallocate memory
btree :: ~btree( )
{
	delete arr ;
	delete lc ;
	delete rc ;
	del ( root ) ;
}

// deletes nodes of a binary tree
void btree :: del ( node *sr )
{
	if ( sr != NULL )
	{
		del ( sr -> left ) ;
		del ( sr -> right ) ;
	}
	delete sr ;
}

void main( )
{
	char a[ ] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0', '\0', 'H' } ;
	int  l[ ] = {  1,   3,   5,   -1,   9,  -1,  -1,   -1,   -1,  -1 } ;
	int  r[ ] = {  2,   4,   6,   -1,  -1,  -1,  -1,   -1,   -1,  -1 } ;

	int sz = sizeof ( a ) ;

	btree bt ( a, l, r, sz ) ;
	bt.insert( 0 ) ;

	cout << "\nIn-order Traversal: " << endl ;
	bt.display( ) ;
}

