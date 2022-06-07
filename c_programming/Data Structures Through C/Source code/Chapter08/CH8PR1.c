/* CH8PR1.C: Program to build a binary search tree from arrays. */

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
	struct node *left ;
	char data ;
	struct node *right ;
} ;

struct node * buildtree ( int ) ;
void inorder ( struct node * ) ;

char arr[ ] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0', '\0', 'H' } ;
int   lc[ ] = {  1,   3,   5,   -1,   9,  -1,  -1,   -1,   -1,  -1 } ;
int   rc[ ] = {  2,   4,   6,   -1,  -1,  -1,  -1,   -1,   -1,  -1 } ;

void main( )
{
	struct node *root ;

	clrscr( ) ;

	root = buildtree ( 0 ) ;
	printf ( “In-order Traversal:\n” ) ;
	inorder ( root ) ;

	getch( ) ;
}

struct node * buildtree ( int index )
{
	struct node *temp = NULL ;
	if ( index != -1 )
	{
		temp = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
		temp -> left = buildtree ( lc[index] ) ;
		temp -> data = arr[index] ;
		temp -> right = buildtree ( rc[index] ) ;
	}
	return temp ;
}

void inorder ( struct node *root )
{
	if ( root != NULL )
	{
		inorder ( root -> left ) ;
		printf ( "%c\t", root -> data ) ;
		inorder ( root -> right ) ;
	}
}