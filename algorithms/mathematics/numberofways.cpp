
// this program tells the number of ways you can go to any index of a matrix
// this program can be done by dynamic programming also

#include <iostream>
#include <vector>
using namespace std;

int number_of_ways(const int &n, const int &m)
{
    vector<vector<int> > A(n,vector<int>(m,0));
    A[0][0] = 1;  // 1 to start from 0,0
    cout << endl;
    for(int rowindex = 0; rowindex < n; rowindex = rowindex + 1)
    {
        for(int columnindex = 0; columnindex < m; columnindex = columnindex + 1)
        {
            A[rowindex][columnindex] = A[rowindex][columnindex] +
            ( rowindex < 1 ? 0 : A[rowindex-1][columnindex] ) + 
            ( columnindex < 1 ? 0 : A[rowindex][columnindex-1] );
            cout << A[rowindex][columnindex] << "    ";
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    number_of_ways(5,5);
    return 0;
}
