#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
	unordered_map<string,int> map;
	map["Badri"]=1;
	map["Karthik"]=2;
	unordered_map<string,int>::iterator it;
	string key="Badri";
	if(map.find(key)!=map.end())
		cout<<"Key is found"<<endl;
	else
		cout<<"Key is not found"<<endl;
	return 0;
}
