#include <iostream>
using namespace std;
int main()
{
	char str[30];
	cin.getline(str,30);
	int l,i,j;
	for(l=0;str[l]!='\0';l++);
	for(i=0,j=l-1;i<l/2 && str[i]==str[j];i++,j--);
	if(i==l/2)
		cout<<str<<" is palindrome"<<endl;
	else
		cout<<"It is not palindrome";
	return 0;
}
