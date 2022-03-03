#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
	int i;
	unordered_map<string,vector <string> >map;
	vector<string>trace;
	trace.push_back("karti");
	map["badri"]=trace;
	trace.push_back("Narayan");
	map["badri"]=trace;	
	

	unordered_map<string,vector <string> >::iterator it;
	for(it=map.begin();it!=map.end();it++)
	{
		vector<string>trace=it->second;
		for(i=0;i<trace.size();i++)
			cout<<trace[i]<<endl;
	}
	return 0;
}
