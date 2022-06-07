/* CH8PR3.C: Program to implement a binary search tree. */

#include <stdio.h>
#include <conio.h>
#include <alloc.h>
struct btreenode
{
	struct btreenode *leftchild ;
	int data ;
	struct btreenode *rightchild ;
} ;

void insert ( struct btreenode **, int ) ;
void inorder ( struct btreenode * ) ;
void preorder ( struct btreenode * ) ;
void postorder ( struct btreenode * ) ;

void main( )
{
	struct btreenode *bt ;
	int req, i = 1, num ;

	bt = NULL ;  /* empty tree */

	clrscr( ) ;
	printf ( "Specify the number of items to be inserted: " ) ;
	scanf ( "%d", &req ) ;

	while ( i++ <= req )
	{
		printf ( "Enter the data: " ) ;
		scanf ( "%d", &num ) ;
		insert ( &bt, num ) ;
	}

	printf ( "\nIn-order   Traversal: " ) ;
	inorder ( bt ) ;

	printf ( "\nPre-order  Traversal: " ) ;
	preorder ( bt ) ;

	printf ( "\nPost-order Traversal: " ) ;
	postorder ( bt ) ;
}

/* inserts a new node in a binary search tree */
void insert ( struct btreenode **sr, int num )
{
	if ( *sr == NULL )
	{
		*sr = malloc ( sizeof ( struct btreenode ) ) ;

		( *sr ) -> leftchild = NULL ;
		( *sr ) -> data = num ;
		( *sr ) -> rightchild = NULL ;
		return ;
	}
	else  /* search the node to which new node will be attached */
	{
		/* if new data is less, traverse to left */
		if ( num < ( *sr ) -> data )
			insert ( &( ( *sr ) -> leftchild ), num ) ;
		else
			/* else traverse to right */
			insert ( &( ( *sr ) -> rightchild ), num ) ;
	}
	return ;
}

/* traverse a binary search tree in a LDR (Left-Data-Right) fashion */
void inorder ( struct btreenode *sr )
{
	if ( sr != NULL )
	{
		inorder ( sr -> leftchild ) ;

		/* print the data of the node whose leftchild is NULL or the path
		   has already been traversed */
		printf ( "\t%d", sr -> data ) ;

		inorder ( sr -> rightchild ) ;
	}
	else
		return ;
}

/* traverse a binary search tree in a DLR (Data-Left-right) fashion */
void preorder ( struct btreenode *sr )
{
	if ( sr != NULL )
	{
		/* print the data of a node */
		printf ( "\t%d", sr -> data ) ;
		/* traverse till leftchild is not NULL */
		preorder ( sr -> leftchild ) ;
		/* traverse till rightchild is not NULL */
		preorder ( sr -> rightchild ) ;
	}
	else
		return ;
}


/* traverse a binary search tree in LRD (Left-Right-Data) fashion */
void postorder ( struct btreenode *sr )
{
	if ( sr != NULL )
	{
		postorder ( sr -> leftchild ) ;
		postorder ( sr -> rightchild ) ;
		printf ( "\t%d", sr -> data ) ;
	}
	else
		return ;
}