
#include <iostream>
#include <set>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}
  

vector<vector<int>> threeSum(vector<int> &a)
{
    //[-4,-1,-1,0,1,2]
    vector<vector<int>> v;
    if(a.size()<3) return v;
    int n=a.size();
    sort(a.begin(),a.end()); //sort the vector 

    for(int i=0;i<n-2;i++)
    {
        int l=i+1,r=n-1;
        if(i>0 and a[i]==a[i-1])
            continue;
        while(l<r)
        {
            if(a[i]+a[l]+a[r]==0){
                v.push_back({a[i],a[l],a[r]});
            l++; r--;
            while(a[l]==a[l-1] and l<r) //skip if duplicates are avilable
                l++;
            while(l<r and a[r]==a[r+1]) // same as above
                r--;
            }
            else if(a[i]+a[l]+a[r]<0) //if sum is less than desired value  then i will advance one step up from below
                l++;
            else // viceversa
                r--;
        }
    }
    return v;
}


int main()
{
	int arr[] = { -4, -1, -1, 0, 1, 2 };
	vector<vector<int>> newvector;
	newvector = threeSum(arr);
	cout << newvector;
	return 0;
}
