#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<string> v;
	v.push_back("badri");
	v.push_back("karthik");
	for(auto it=v.rbegin();it!=v.rend();it++)
		cout<<*it<<" "<<endl;
}
