// Program Ch08pr04
// Program with insert and remove operation

#include <iostream.h>

#define TRUE 1
#define FALSE 0

class btree
{

	private :

		struct btreenode
		{
			btreenode *leftchild ;
			int data ;
			btreenode *rightchild ;
		} *root ;

	public :

		btree( ) ;
        void buildtree ( int num ) ;
		static void insert ( btreenode **sr, int ) ;
		static void search ( btreenode **sr, int num, btreenode **par,
					  btreenode **x, int *found ) ;
        void remove ( int num ) ;
		static void rem ( btreenode **sr, int ) ;
        void display( ) ;
		static void inorder ( btreenode *sr ) ;
        ~btree( ) ;
        static void del ( btreenode *sr ) ;
} ;

// initialises data members
btree :: btree( )
{
	root = NULL ;
}

// calls insert( ) to build tree
void btree :: buildtree ( int num )
{
	insert ( &root, num ) ;
}

// inserts a new node in a binary search tree
void btree :: insert ( btreenode **sr, int num )
{
	if ( *sr == NULL )
	{
		*sr = new btreenode ;

		( *sr ) -> leftchild = NULL ;
		( *sr ) -> data = num ;
		( *sr ) -> rightchild = NULL ;
	}
	else  // search the node to which new node will be attached
	{
		// if new data is less, traverse to left
		if ( num < ( *sr ) -> data )
			insert ( & ( ( *sr ) -> leftchild ), num ) ;
		else
			// else traverse to right
			insert ( & ( ( *sr ) -> rightchild ), num ) ;
	}
}

// calls rem to delete node
void btree :: remove ( int num )
{
	rem ( &root, num ) ;
}

// deletes a node from the binary search tree
void btree :: rem ( btreenode **sr, int num )
{
	int found ;
	btreenode *parent, *x, *xsucc ;

	// if tree is empty
	if ( *sr == NULL )
	{
		cout << "\nTree is empty" ;
		return ;
	}

	parent = x = NULL ;

	// call to search function to find the node to be deleted
	search ( sr, num, &parent, &x, &found ) ;

	// if the node to deleted is not found
	if ( found == FALSE )
	{
		cout << "\nData to be deleted, not found" ;
		return ;
	}

	// if the node to be deleted has two children
	if ( x -> leftchild != NULL && x -> rightchild != NULL )
	{
		parent = x ;
		xsucc = x -> rightchild ;

		while ( xsucc -> leftchild != NULL )
		{
			parent = xsucc ;
			xsucc = xsucc -> leftchild ;
		}

		x -> data = xsucc -> data ;
		x = xsucc ;
	}

	// if the node to be deleted has no child
	if ( x -> leftchild == NULL && x -> rightchild == NULL )
	{
		if ( parent -> rightchild == x )
			parent -> rightchild = NULL ;
		else
			parent -> leftchild = NULL ;

		delete x ;
		return ;
	}

	// if the node to be deleted has only rightchild
	if ( x -> leftchild == NULL && x -> rightchild != NULL )
	{
		if ( parent -> leftchild == x )
			parent -> leftchild = x -> rightchild ;
		else
			parent -> rightchild = x -> rightchild ;

		delete x ;
		return ;
	}

	// if the node to be deleted has only left child
	if ( x -> leftchild != NULL && x -> rightchild == NULL )
	{
		if ( parent -> leftchild == x )
			parent -> leftchild = x -> leftchild ;
		else
			parent -> rightchild = x -> leftchild ;

		delete x ;
		return ;
	}
}

// returns the address of the node to be deleted,
// address of its parent and whether the node is found or not
void btree :: search ( btreenode **sr, int num, btreenode **par,
		btreenode **x, int *found )
{
	btreenode *q ;

	q = *sr ;
	*found = FALSE ;
	*par = NULL ;

	while ( q != NULL )
	{
		// if the node to be deleted is found
		if ( q -> data == num )
		{
			*found = TRUE ;
			*x = q ;
			return ;
		}

		*par = q ;

		if ( q -> data > num )
			q = q -> leftchild ;
		else
			q = q -> rightchild ;
	}
}

// calls inorder( ) to traverse tree
void btree :: display( )
{
	inorder ( root ) ;
}

// traverse a binary search tree in a LDR (Left-Data-Right) fashion
void btree :: inorder ( btreenode *sr )
{
	if ( sr != NULL )
	{
		inorder ( sr -> leftchild ) ;

		// print the data of the node whose
		// leftchild is NULL or the path  has
		// already been traversed
		cout << sr -> data << "\t" ;

		inorder ( sr -> rightchild ) ;
	}
}

// calls del to deallocate memory
btree :: ~btree( )
{
	del ( root ) ;
}

// deletes nodes of a binary tree
void btree :: del ( btreenode *sr )
{
	if ( sr != NULL )
	{
		del ( sr -> leftchild ) ;
		del ( sr -> rightchild ) ;
	}
	delete sr ;
}

void main( )
{
	btree bt ;
	int req, i = 0, num, a[ ] = { 11, 9, 13, 8, 10, 12, 14, 15, 7 } ;

	while ( i <= 8 )
	{
		bt.buildtree ( a[i] ) ;
		i++ ;
	}

	cout << "Binary tree before deletion:\n" ;
	bt.display( ) ;

	bt.remove ( 10 ) ;
	cout << "\nBinary tree after deletion:\n"  ;
	bt.display( ) ;

	bt.remove ( 14 ) ;
	cout << "\nBinary tree after deletion:\n" ;
	bt.display( ) ;

	bt.remove ( 8 ) ;
	cout << "\nBinary tree after deletion:\n" ;
	bt.display( ) ;

	bt.remove ( 13 ) ;
	cout << "\nBinary tree after deletion:\n" ;
	bt.display( ) ;
}

