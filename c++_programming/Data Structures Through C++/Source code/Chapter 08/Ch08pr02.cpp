// Program: Ch08pr02
// Program to build a binary search tree from an array

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

		char *a ;

	public :

		btree ( char *ar, int size ) ;
		void insert ( int index ) ;
		static node* buildtree ( char *arr, int index ) ;
		void display( ) ;
		static void inorder ( node *sr ) ;
		~btree( ) ;
		static void del ( node *sr ) ;

} ;

// initialises data members
btree :: btree ( char *ar, int size )
{
	root = NULL ;
	a = new char[size] ;

	for ( int i = 0 ; i < size ; i++ )
		* ( a + i ) = ar[i] ;
}

// builds tree by calling buildtree
void btree :: insert ( int index )
{
	root = buildtree ( a, index ) ;
}

// builds a binary tree
node* btree :: buildtree ( char *arr, int index )
{
	node *temp = NULL ;

	if ( * ( arr + index ) != '\0' )
	{
		temp = new node ;
		temp -> left = buildtree ( arr, 2 * index + 1 ) ;
		temp -> data = * ( arr + index ) ;
		temp -> right = buildtree ( arr, 2 * index + 2 ) ;
	}
	return temp ;
}

// calls inorder to traverse a tree
void btree :: display( )
{
    inorder ( root ) ;
}

// displays data in a binary tree
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
	delete a ;
	del ( root ) ;
}

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
	char arr[] = {
				'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0', '\0', 'H', '\0',
				'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',	'\0', '\0'
				} ;

	int sz = sizeof ( arr ) ;

	btree bt ( arr, sz )  ;
	bt.insert ( 0 ) ;

	cout << "\nIn-order Traversal: " << endl ;
	bt.display( ) ;
}

