#include <iostream>
#include <queue>
using namespace std;
void print_queue(queue<int> gqueue)
{
	queue<int> q=gqueue;
	while(!q.empty())
	{
		cout<<q.front()<<"\n";
		q.pop();
	}
}
int main()
{
	queue <int> fqueue;
	fqueue.push(10);
	fqueue.push(20);
	print_queue(fqueue);
	return 0;
}
