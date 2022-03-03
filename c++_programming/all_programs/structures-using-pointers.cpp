#include <iostream>
using namespace std;
struct complex
{
	int real;
	float img;
};

int main()
{
	complex *ptr;
	(ptr+0)->real=12;
	(ptr+0)->img=12.2;
	(ptr+1)->real=13;
	(ptr+1)->img=13.3;
	int i;
	for(i=0;i<2;i++)
		cout<<(ptr+i)->real << " " <<(ptr+i)->img;
	cout<<endl;
	return 0;
}
