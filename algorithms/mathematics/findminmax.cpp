
#include <utility>      // std::pair
#include <vector>      // std::pair
#include <iostream>     // std::cout
#include <algorithm>     // std::cout
using namespace std;

//Return (min, max) pair of elements in A

template <typename T>
pair<T, T> find_min_max(const vector<T> &A)
{
    if(A.size() <= 1)
    {
        return { A.front(), A.front() };
    }

    // Initialize the min and max pair
    pair<T, T> min_max_pair = minmax(A[0], A[1]);
    for (int i = 2; i + 1 < A.size(); i = i + 2)
    {
        pair<T, T> local_pair = minmax(A[i], A[i+1]);
        min_max_pair = {min(min_max_pair.first, local_pair.first),
                        max(min_max_pair.second, local_pair.second)
                       };
    }
    // special case: if there is odd number of elements in the array, we still
    // need to compare the last element with the existing answer

    if(A.size() & 1)
    {
        min_max_pair = {min(min_max_pair.first, A.back()),
                        max(min_max_pair.second, A.back())
                       };
    }
    return min_max_pair;
}


// make_pair example

int main ()
{
    int myints[] = {16,2,77,29,345,234,23,654,34,98,79};
    vector<int> myvector (myints, myints + sizeof(myints) / sizeof(int) );
    pair <int,int> minmax;

    minmax = find_min_max(myvector);
    cout << "minmax: " << minmax.first << ", " << minmax.second << '\n';

    return 0;
}

