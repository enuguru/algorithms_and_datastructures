#include <iostream>
using namespace std;
bool anagrams(string s1,string s2)
{
	int n1,n2;
	n1=s1.length();
	n2=s2.length();
	if(n1!=n2)
		return false;
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]!=s2[i])
			return false;
	}
	return true;
}

int main()
{
	string s1="badri",s2="karthik";
	cout<<anagrams(s1,s2)<<endl;
	return 0;
}
