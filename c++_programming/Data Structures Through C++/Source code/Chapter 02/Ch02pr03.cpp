// Program Ch02pr03
// Program to perform operations like addition, multiplicaton, etc. on matrix

#include <iostream.h>

const int MAX = 3 ;

class matrix
{
	private :

		int mat[MAX][MAX] ;

	public :

		matrix( ) ;
		void create( ) ;
		void display( ) ;
		void matadd ( matrix &m1, matrix &m2 ) ;
		void matmul ( matrix &m1, matrix &m2 ) ;
		void transpose ( matrix &m1 ) ;
} ;

// initializes the matrix mat with 0
matrix :: matrix( )
{
	for ( int i = 0 ; i < MAX ; i++ )
	{
		for ( int j = 0 ; j< MAX ; j++ )
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
			cout << "\nEnter the element : " ;
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

// adds two matrices m1 and m2
void matrix :: matadd ( matrix &m1, matrix &m2 )
{
	for ( int i = 0 ; i < MAX ; i++ )
	{
		for ( int j = 0 ; j < MAX ; j++ )
			mat[i][j] = m1.mat[i][j] + m2.mat[i][j] ;
	}
}

// multiplies two matrices m1 and m2
void matrix :: matmul ( matrix &m1, matrix &m2 )
{
	for ( int k = 0 ; k < MAX ; k++ )
	{
		for ( int i = 0 ; i < MAX ; i++ )
		{
			for ( int j = 0 ; j < MAX ; j++ )
				mat[k][i] += m1.mat[k][j] * m2.mat[j][i] ;
		}
	}
}

// obtains transpose of matrix m1
void matrix :: transpose ( matrix &m1 )
{
	for ( int i = 0 ; i < MAX ; i++ )
	{
		for ( int j = 0 ; j < MAX ; j++ )
			mat[i][j] = m1.mat[j][i] ;
	}
}

void main( )
{
	matrix mat1 ;
	cout << "\nEnter elements for first array: \n" ;
	mat1.create( ) ;

	matrix mat2 ;
	cout << "\nEnter elements for second array: \n" ;
	mat2.create( ) ;

	cout << "\nFirst Array: \n" ;
	mat1.display( ) ;
	cout << "\nSecond Array:\n" ;
	mat2.display( ) ;

	matrix mat3 ;
	mat3.matadd ( mat1, mat2 ) ;
	cout << "\nAfter Addition: \n" ;
	mat3.display( ) ;

	matrix mat4 ;
	mat4.matmul ( mat1, mat2 ) ;
	cout << "\nAfter Multiplication: \n" ;
	mat4.display( ) ;

	matrix mat5 ;
	mat5.transpose ( mat1 ) ;
	cout << "\nTranspose of first matrix: \n" ;
	mat5.display( ) ;
}
