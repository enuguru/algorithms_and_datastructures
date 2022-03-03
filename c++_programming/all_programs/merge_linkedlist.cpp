#include <iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
};

void push(Node **head_ref,int data)
{
	Node *new_node=new Node();
	new_node->data=data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}

void move_node(Node **dest,Node **source_node)
{
	Node *newnode=*source_node;
	*source_node=newnode->next;
	newnode->next=*dest;
	*dest=newnode;

}
Node* merge_list(Node *a,Node *b)
{
	Node dummy_head;
	Node *tail=&dummy_head;
	while(1)
	{
		if(a==NULL)

		{
			tail->next=b;
			break;
		}
		else if(b==NULL)
		{
			tail->next=a;
			break;
		}
		
		else if(a->data<b->data)
			move_node(&tail->next,&a);
		else if(a->data>b->data)
			move_node(&tail->next,&b);
		tail=tail->next;
	}
	return dummy_head.next;
}


void print_list(Node *a)
{
	Node *current=a;
	while(current!=NULL)
	{
		cout<<current->data<<" "<<endl;
		current=current->next;
	}
}

int main()
{
	Node *res=NULL;
	Node *a=NULL;
	Node *b=NULL;
	push(&a,5);
	push(&a,4);
	push(&b,3);
	push(&b,1);
	res=merge_list(a,b);
	print_list(res);
}
	
