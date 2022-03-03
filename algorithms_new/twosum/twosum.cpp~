
// Two sum problem

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

template <typename S>
ostream& operator<<(ostream& os,
                    const vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}
 

vector<int> twoSum(vector<int> &nums, int target) 
{
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            int diff=target-nums[i];
            if(m.find(diff)==m.end())
                m[nums[i]]=i;
            else
            {
                v.push_back(m[diff]);
                v.push_back(i);
            }
        
        }
              
        return v;
        
}

int main()
{
	int num = 9;
	vector<int> arr = {2,7,11,15};
	vector<int> result;
	result	= twoSum(arr,num);
	cout << result;
	return 0;
}
