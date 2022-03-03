#include <iostream>
#include <queue>
using namespace std;
class Stack
{
	queue<int> q1,q2;
	int curr_size;
	public:
	Stack()
	{
		curr_size=0;
	}

	void push(int ele)
	{
		q1.push(ele);
		curr_size++;
	}
	void pop()
	{
		while(q1.size()!=1)
		{
			q2.push(q1.front());
			q1.pop();
		}

		q1.pop();
		curr_size--;
		queue<int> q;
		q=q1;
		q1=q2;
		q2=q;
	}

	int top()
	{
		while(q1.size()!=1)
		{
			q2.push(q1.front());
			q1.pop();
		}

		int temp=q1.front();
		q2.push(temp);
		queue<int> q;
		q=q1;
		q1=q2;
		q2=q;
		return(temp);
	}
};

int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<s.top()<<"\n";
	s.pop();
	cout<<s.top();
}
