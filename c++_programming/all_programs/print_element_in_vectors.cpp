#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	for(auto i:v)
		cout<<i<<"\n"<<endl;
	return 0;
}
