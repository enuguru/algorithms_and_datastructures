// Program Ch10pr04
// Program to find the shortest path.

#include <iostream.h>

const int INF = 9999 ;

void main( )
{
	int arr[4][4] ;
	int cost[4][4] = {
						7, 5, 0, 0,
						7, 0, 0, 2,
						0, 3, 0, 0,
						4, 0, 1, 0
					} ;
	int i, j, k, n = 4 ;

	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0; j < n ; j++ )
		{
			if ( cost[i][j] == 0 )
				arr[i][j] = INF ;
			else
				arr[i][j] = cost[i][j] ;
		}
	}

	cout << "Adjacency matrix of cost of edges:\n" ;

	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0; j < n ; j++ )
			cout << arr[i][j] << "\t" ;
		cout << "\n" ;
	}

	for ( k = 0 ; k < n ; k++ )
	{
		for ( i = 0 ; i < n ; i++ )
		{
			for ( j = 0 ; j < n ; j++ )
			{
				if ( arr[i][j] > arr[i][k] + arr[k][j] )
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	cout << "Adjacency matrix of lowest cost between the vertices:\n" ;
	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0; j < n ; j++ )
			cout << arr[i][j] << "\t" ;
		cout << "\n" ;
	}
}