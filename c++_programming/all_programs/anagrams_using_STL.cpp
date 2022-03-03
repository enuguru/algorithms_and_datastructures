#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
void print_anagrams(unordered_map<string,vector<string> > &store)
{
	int i;
	unordered_map<string,vector<string > >:: iterator it;
	for(it=store.begin();it!=store.end();it++)
	{
		vector<string> temp=it->second;
		if(temp.size()>1)
		{
			for(i=0;i<temp.size();i++)
				cout<<temp[i]<<" ";
		}
		cout<<endl;
	}
}

void create_hash_map(vector<string>&v)
{
	int i;
	unordered_map<string,vector<string> >store;
	for(i=0;i<v.size();i++)
	{
		string temp(v[i]);
		sort(temp.begin(),temp.end());

		if(store.find(temp)==store.end())
		{
			vector<string>temp_vec;
			temp_vec.push_back(v[i]);
			store.insert(make_pair(temp,temp_vec));
		}
		else
		{
			vector<string>temp_vec(store[temp]);
			temp_vec.push_back(v[i]);
			store[temp]=temp_vec;
		}
	}
	
	
	print_anagrams(store);

	
}


int main()
{
	vector<string>v;
	v.push_back("cat");
	v.push_back("badri narayanan");
	v.push_back("act");
	v.push_back("dog");
	v.push_back("god");
	v.push_back("narayanan badri");
	create_hash_map(v);
	return 0;
}

