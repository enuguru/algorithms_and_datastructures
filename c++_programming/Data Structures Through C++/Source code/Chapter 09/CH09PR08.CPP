// Program: ch09pr08
// Program to sort array using Binary Tree Sort method

#include <iostream.h>

class btree
{
	private:

		struct btreenode
		{
			struct btreenode *leftchild ;
			int data ;
			struct btreenode *rightchild ;
		} *node ;

	public :

		btree( ) ;
		void buildtree ( int num ) ;
		static void insert ( btreenode **node, int num ) ;
		void display( ) ;
		static void inorder ( btreenode **node ) ;
        ~btree( ) ;
        static void del ( btreenode *sr ) ;
} ;

// initialises data members
btree :: btree( )
{
	node = NULL ;
}

// calls insert
void btree :: buildtree ( int num )
{
    insert ( &node, num ) ;
}

// inserts an element in a tree
void btree :: insert ( btreenode **node, int num )
{
	if ( ( *node ) == NULL )
	{
		( *node ) = new btreenode ;

		( *node ) -> leftchild = NULL ;
		( *node ) -> data = num ;
		( *node ) -> rightchild = NULL ;
	}
	else
	{
		if ( num < ( *node ) -> data )
			 insert ( ( & ( *node ) -> leftchild ), num ) ;
		else
			insert ( ( & ( *node ) -> rightchild ), num ) ;
	}
}

// calls traverse to display elements
void btree :: display( )
{
	if ( node != NULL )
	        inorder ( &node ) ;
}

// traverses tree to display elements
void btree :: inorder ( btreenode **node )
{
	if ( ( *node ) != NULL )
	{
		inorder ( & ( ( *node ) -> leftchild ) ) ;
		cout << ( *node ) -> data << "\t" ;
		inorder ( & ( ( *node ) -> rightchild ) ) ;
	}
}

// calls del to deallocate memory
btree :: ~btree( )
{
	del ( node ) ;
}

// deallocates memory
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

	bt.buildtree ( 11 ) ;
	bt.buildtree ( 2 ) ;
	bt.buildtree ( 9 ) ;
	bt.buildtree ( 13 ) ;
	bt.buildtree ( 57 ) ;
	bt.buildtree ( 25 ) ;
	bt.buildtree ( 17 ) ;
	bt.buildtree ( 1 ) ;
	bt.buildtree ( 90 ) ;
	bt.buildtree ( 3 ) ;

	cout << "\nBinary tree sort.\n" ;
	cout << "\nIn-order traversal of binary tree:\n"  ;
	bt.display( ) ;
}


