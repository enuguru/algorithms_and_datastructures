
#include <utility>      // std::pair
#include <vector>      // std::pair
#include <iostream>     // std::cout
#include <algorithm>     // std::cout
#include <chrono>
#include <random>
using namespace std;


// partition A according to pivot, return its index after partition

template <typename T>
int partition(vector<T> &A, const int &L, const int &R, const int &pivot)
{
     T pivot_value = A[pivot];
     int larger_index = L;

     swap(A[pivot] , A[R]);
     for(int i = 1; i < R; ++i)
     {
        if(A[i] > pivot_value)
        {
            swap(A[i], A[larger_index++]);
        }
     }
     swap(A[R], A[larger_index]);
     return larger_index;
}
   
 
     
template <typename T>
T find_k_th_largest(vector<T> A, const int &k)
{
   int L = 0, R = A.size() - 1;
  
   while( L <= R)
   {
        default_random_engine gen((random_device())());
        uniform_int_distribution<int> dis(L,R); // generatre random int in (L,R)
        int p = partition(A,L,R,dis(gen));
        if( p == k - 1)
        {
            return A[p];
        } else if(p > (k -1))
        {
            R = p - 1;
        } else   // p < k - 1
        {
          L = p + 1;
        }
    }
}
      

int main ()
{
    int myints[] = {16,2,77,29,345,234,23,654,34,98,79};
    vector<int> myvector (myints, myints + sizeof(myints) / sizeof(int) );
    int p = find_k_th_largest(myvector,2);
    cout << "kth-largest element is : " << p << '\n';
    return 0;
}
  
