// generate prime numbers using sieve of eratosthenes algorithm

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<bool> v(n+1,true);
    v[0]=false;
    v[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(v[i])
        {
            for(int j=i*i;j<=n;j+=i)
                v[j]=false;
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(v[i])
            cout<<i<<" ";
    }
    cout<<endl;
    exit(0);
}

// Path: generateprimes.cpp