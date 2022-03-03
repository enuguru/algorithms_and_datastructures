#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> a;
	a.push_back(10);
	a.push_back(20);
	int i;
	for(auto it=a.rbegin();it!=a.rend();it++)
			cout<<*it<<" "<<endl;
	return 0;
	
}
