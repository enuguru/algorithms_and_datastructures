/* CH7PR5.C: Program that implements a priority queue using an array. */

#include <stdio.h>
#include <conio.h>

#define MAX 5

struct data
{
	char job[MAX] ;
	int prno ;
	int ord ;
} ;

struct pque
{
	struct data d[MAX] ;
	int front ;
	int rear ;
} ;

void initpque ( struct pque * ) ;
void add ( struct pque *, struct data ) ;
struct data delete ( struct pque * ) ;

void main( )
{
	struct pque q ;
	struct data dt, temp ;
	int i, j = 0 ;

	clrscr( ) ;

	initpque ( &q ) ;

	printf ( "Enter Job description (max 4 chars) and its priority\n" ) ;
	printf ( "Lower the priority number, higher the priority\n" ) ;
	printf ( "Job     Priority\n" ) ;

	for ( i = 0 ; i < MAX ; i++ )
	{
		scanf ( "%s %d", &dt.job, &dt.prno ) ;
		dt.ord = j++ ;
		add ( &q, dt ) ;
	}
	printf ( "\n" ) ;

	printf ( "Process jobs prioritywise\n" ) ;
	printf ( "Job\tPriority\n" ) ;

	for ( i = 0 ; i < MAX ; i++ )
	{
		temp  = delete ( &q ) ;
		printf ( "%s\t%d\n", temp.job, temp.prno ) ;
	}
	printf ( "\n" ) ;

	getch( ) ;
}

/* initialises data members */
void initpque ( struct pque *pq )
{
	int i ;

	pq -> front = pq -> rear = -1 ;
	for ( i = 0 ; i < MAX ; i++ )
	{
		strcpy ( pq -> d[i].job, '\0' ) ;
		pq -> d[i].prno = pq -> d[i].ord = 0 ;
	}
}

/* adds item to the priority queue */
void add ( struct pque *pq, struct data dt )
{
	struct data temp ;
	int i, j ;

	if ( pq -> rear == MAX - 1 )
	{
		printf ( "\nQueue is full." ) ;
		return ;
	}

	pq -> rear++ ;
	pq -> d[pq -> rear] = dt ;

	if ( pq -> front == -1 )
		pq -> front = 0 ;

	for ( i = pq -> front ; i <= pq -> rear ; i++ )
	{
		for ( j = i + 1 ; j <= pq -> rear ; j++ )
		{
			if ( pq -> d[i].prno > pq -> d[j].prno )
			{
				temp = pq -> d[i] ;
				pq -> d[i] = pq -> d[j] ;
				pq -> d[j] = temp ;
			}
			else
			{
				if ( pq -> d[i].prno == pq -> d[j].prno )
				{
					if ( pq -> d[i].ord > pq -> d[j].ord )
					{
						temp = pq -> d[i] ;
						pq -> d[i] = pq -> d[j] ;
						pq -> d[j] = temp ;
					}
				}
			}
		}
	}
}

/* removes item from priority queue */
struct data  delete ( struct pque *pq )
{
	struct data  t ;
	strcpy ( t.job, "" ) ;
	t.prno = 0 ;
	t.ord = 0 ;

	if ( pq -> front == -1 )
	{
		printf ( "\nQueue is Empty.\n" ) ;
		return t ;
	}

	t = pq -> d[pq -> front] ;
	pq -> d[pq -> front] = t ;
	if ( pq -> front == pq -> rear )
		 pq -> front = pq -> rear = -1 ;
	else
		 pq -> front++ ;

	return  t ;
}