#include <iostream>
#include <stack>
using namespace std;
class Queue
{
	public:
	stack<int> s1,s2;
	int curr_size;
	Queue()
	{
		curr_size=0;
	}
	void enqueue(int element)
	{
		s1.push(element);
	}

	int dequeue()
	{
		stack<int> s;
		if(s1.empty()&& s2.empty())
			cout<<"The Queue is empty";
		
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}

		int item=s2.top();
		s2.pop();
		return item;
	}
};

int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	cout<<q.dequeue()<<"\n";
	cout<<q.dequeue()<<endl;
	return 0;
}



