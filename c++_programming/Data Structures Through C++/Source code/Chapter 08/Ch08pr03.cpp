// Program: Ch08pr03
// Program with inorder, preorder and postorder functions

#include <iostream.h>

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
		static void insert ( btreenode **sr, int num ) ;
		void traverse( ) ;
		static void inorder ( btreenode *sr  ) ;
		static void preorder ( btreenode *sr ) ;
		static void postorder ( btreenode *sr ) ;
		static void del ( btreenode *sr ) ;
		~btree( ) ;
} ;

// initialises data member
btree :: btree( )
{
	root = NULL ;
}

// build tree by calling insert( )
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
		return ;
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
	return ;
}

// traverses btree
void btree :: traverse( )
{
	cout << "\nIn-order   Traversal: " ;
	inorder ( root ) ;

	cout << "\nPre-order  Traversal: " ;
	preorder ( root ) ;

	cout << "\nPost-order Traversal: " ;
	postorder ( root ) ;
}

// traverse a binary search tree in a LDR (Left-Data-Right) fashion
void btree :: inorder ( btreenode *sr )
{
	if ( sr != NULL )
	{
		inorder ( sr -> leftchild ) ;

		// print the data of the node whose
		// leftchild is NULL or the path
		// has already been traversed
		cout << "\t" << sr -> data ;

		inorder ( sr -> rightchild ) ;
	}
	else
		return ;
}

// traverse a binary search tree in a DLR (Data-Left-right) fashion
void btree :: preorder ( btreenode *sr )
{
	if ( sr != NULL )
	{
		// print the data of a node
		cout << "\t" << sr -> data ;
		// traverse till leftchild is not NULL
		preorder ( sr -> leftchild ) ;
		// traverse till rightchild is not NULL
		preorder ( sr -> rightchild ) ;
	}
	else
		return ;
}

// traverse a binary search tree in LRD (Left-Right-Data) fashion
void btree :: postorder ( btreenode *sr )
{
	if ( sr != NULL )
	{
		postorder ( sr -> leftchild ) ;
		postorder ( sr -> rightchild ) ;
		cout << "\t" << sr -> data ;
	}
	else
		return ;
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
	int req, i = 1, num ;

	cout << "Specify the number of items to be inserted: " ;
	cin >> req ;

	while ( i++ <= req )
	{
		cout << "Enter the data: " ;
		cin >> num ;
		bt.buildtree ( num ) ;
	}

    bt.traverse( ) ;
}

