// Program Ch02pr04
// Program for matrix operations like determinant, singular, etc.

#include <iostream.h>
#include <math.h>

const int MAX = 3 ;

class matrix
{
	private :

		int mat[MAX][MAX] ;

	public :

		matrix( ) ;
		void create( ) ;
		void display( ) ;
		matrix matmul ( matrix &m ) ;
		matrix transpose( ) ;
       		int determinant( ) ;
		int isortho( ) ;
} ;

// initializes the matrix mat with 0
matrix :: matrix( )
{
	for ( int i = 0 ; i < MAX ; i++ )
	{
		for ( int j = 0 ; j < MAX ; j++ )
			mat[i][j] = 0 ;
	}
}

// creates matrix mat
void matrix :: create( )
{
    int n ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		for ( int j = 0 ; j < MAX ; j++ )
		{
			cout << "\nEnter the element: " ;
			cin >> n ;
			mat[i][j] = n ;
		}
	}
}

// displays the contents of matrix
void matrix :: display( )
{
	for ( int i = 0 ; i < MAX ; i++ )
	{
		for ( int j = 0 ; j < MAX ; j++ )
			cout << mat[i][j] << "  " ;
		cout << endl ;
	}
}

// multiplies two matrices
matrix matrix :: matmul ( matrix &m )
{
    matrix m1 ;
	for ( int k = 0 ; k < MAX ; k++ )
	{
		for ( int i = 0 ; i < MAX ; i++ )
		{
			for ( int j = 0 ; j < MAX ; j++ )
				m1.mat[k][i] += mat[k][j] * m.mat[j][i] ;
		}
	}
    return m1 ;
}

// obtains transpose of matrix m1
matrix matrix :: transpose( )
{
    matrix m ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		for ( int j = 0 ; j < MAX ; j++ )
             m.mat[i][j] = mat[j][i] ;
	}
    return m ;
}

// finds the determinant value for given matrix
int matrix :: determinant( )
{
	int sum, j, k, p ;
	sum = 0 ; j = 1 ; k = MAX - 1 ;

	for ( int i = 0 ; i < MAX ; i++ )
	{
	    	p = pow ( -1, i ) ;

	        	if ( i == MAX - 1 )
        			k = 1 ;
		sum = sum + ( mat[0][i] * ( mat[1][j] *
			        mat[2][k] - mat[2][j] *
			        mat[1][k] ) ) * p ;
		j = 0 ;
	 }

	return sum ;
}

// checks if given matrix is an orthogonal matrix
int matrix :: isortho( )
{
    // transpose the matrix ;
    matrix m1 = transpose( ) ;

    // multiply the matrix with its transpose
	matrix m2 = matmul ( m1 ) ;

    // check for the identity matrix
    for ( int i = 0  ; i < MAX ; i++ )
    {
    	if ( m2.mat[i][i] == 1 )
        	continue ;
        else
        	break ;
    }
    if ( i == MAX )
    	return 1 ;
    else
    	return 0 ;
}

void main( )
{
	matrix mat1 ;
	cout << "\nEnter elements for first array: \n" ;
	mat1.create( ) ;

 	cout << "\nThe Matrix: " << endl ;
	mat1.display( ) ;

	int d = mat1.determinant( ) ;
   	cout << "\nThe determinant for given matrix: " << d << endl ;

	if ( d == 0  )
  	  	cout << "\nmat1 matrix is singular" << endl ;
	else
    		cout << "\nmat1 matrix  is not singular" << endl ;

	d = mat1.isortho( ) ;
	if ( d != 0 )
		cout << "\nmat1 matrix is orthogonal" << endl ;
	else
		cout << "\nmat1 matrix is not orthogonal" << endl ;
}