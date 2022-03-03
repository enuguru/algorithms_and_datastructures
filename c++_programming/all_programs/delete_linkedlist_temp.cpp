#include <iostream>

using namespace std;
class Node
{
	public:
	int data;
	Node *next;
};

Node *start = NULL;

void insert_node(Node *mynode,int data)
{
	Node *newnode=new Node();
	newnode->data=data;
	if(start == NULL)
	{
		mynode->next = NULL;
	        head_ref = newnode;
	}
	else
        {
	       newnode->next=head_ref;
	       head_ref=newnode;
	}
}

void delete_ll(Node *a,int key)
{
	Node *current=a;
	Node *prev=NULL;
	while(current->data!=key)
	{
		prev=current;
		current=current->next;
	}
	if(current->data==key)
	{
		prev->next=current->next;
	}
	else
	{
		a=current->next;
	}
}


void display(Node *a)
{
	Node *current=a;
	while(current)
	{
		cout<<current->data<<" "<<endl;
		current=current->next;
	}
}

int main()
{
	Node *a=NULL;
	insert_node(a,30);
	insert_node(a,20);
	insert_node(a,10);
	delete_ll(a,20);
	display(a);
	return 0;
}
