#include <iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
};

void push(Node **head,int data)
{
	Node *newnode=new Node();
	newnode->data=data;
	newnode->next=*head;
	*head=newnode;
}
void print(Node *head)
{
	Node *curr=head;
	while(curr)
	{
		cout<<curr->data<<endl;
		curr=curr->next;
	}
}

void move_node(Node **dest,Node **source)
{
	Node *newnode=*source;
	if(newnode==NULL)
		return;
	*source=newnode->next;
	newnode->next=*dest;
	*dest=newnode;
}

Node* merge_linkedlist(Node *a,Node *b)
{
	Node dummy_head;
	Node *tail=&dummy_head;
	dummy_head.next=NULL;
	while(1)
	{
		if(a==NULL)
		{
			tail->next=b;
			break;
		}
		if(b==NULL)
		{
			tail->next=a;
			break;
		}
		if(a->data<=b->data)
			move_node(&(tail->next),&a);
		else
			move_node(&(tail->next),&b);
		tail=tail->next;
	}
	return dummy_head.next;
}

void skip_nodes(Node *a,Node *b,int m,int n)
{
	Node *curr=a;
	int i;
	for(i=1;i<m && curr!=NULL;i++)
		curr=curr->next;
	Node *temp=curr->next;
	for(i=1;i<=n && temp!=NULL;i++)
	{
		Node *del=temp;
		temp=temp->next;
		free(del);
	}
	Node *trace=b;
	curr->next=b;
	while(trace->next!=NULL)
		trace=trace->next;
	trace->next=temp;
	trace=temp;
	curr=trace;
	
}
	
	






int main()
{
	Node *head=NULL;
	Node *res;
	push(&head,13);
	push(&head,10);
	push(&head,9);
	push(&head,7);
	Node *b=NULL;
	push(&b,11);
	push(&b,8);
	push(&b,5);
	skip_nodes(head,b,1,1);
	print(head);
	return 0;
}
