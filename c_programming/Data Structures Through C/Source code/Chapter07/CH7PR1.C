/* CH7PR1.C: Program that implements queue as an array. */

#include <stdio.h>
#include <conio.h>

#define MAX 10

void addq ( int *, int, int *, int * ) ;
int delq ( int *, int *, int * ) ;

void main( )
{
	int arr[MAX] ;
	int front = -1, rear = -1, i ;

	clrscr( ) ;

	addq ( arr, 23, &front, &rear ) ;
	addq ( arr, 9, &front, &rear ) ;
	addq ( arr, 11, &front, &rear ) ;
	addq ( arr, -10, &front, &rear ) ;
	addq ( arr, 25, &front, &rear ) ;
	addq ( arr, 16, &front, &rear ) ;
	addq ( arr, 17, &front, &rear ) ;
	addq ( arr, 22, &front, &rear ) ;
	addq ( arr, 19, &front, &rear ) ;
	addq ( arr, 30, &front, &rear ) ;
	addq ( arr, 32, &front, &rear ) ;

	i = delq ( arr, &front, &rear ) ;
	printf ( "\nItem deleted: %d", i ) ;

	i = delq ( arr, &front, &rear ) ;
	printf ( "\nItem deleted: %d", i ) ;

	i = delq ( arr, &front, &rear ) ;
	printf ( "\nItem deleted: %d", i ) ;

	getch( ) ;
}

/* adds an element to the queue */
void addq ( int *arr, int item, int *pfront, int *prear  )
{
	if ( *prear == MAX - 1 )
	{
		printf ( "\nQueue is full." ) ;
		return ;
	}

	( *prear )++ ;
	arr[*prear] = item ;

	if ( *pfront == -1 )
		*pfront = 0 ;
}

/* removes an element from the queue */
int delq ( int *arr, int *pfront, int *prear )
{
	int data ;

	if ( *pfront == -1 )
	{
		printf ( "\nQueue is Empty." ) ;
		return NULL ;
	}

	data = arr[*pfront] ;
	arr[*pfront] = 0 ;
	if ( *pfront == *prear )
		 *pfront = *prear = -1 ;
	else
		 ( *pfront )++ ;

	return  data ;
}