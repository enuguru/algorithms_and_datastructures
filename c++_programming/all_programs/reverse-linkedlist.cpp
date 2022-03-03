#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;

void insert_node(int data)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	struct node *current=head;
	while(current->next!=NULL)
		current=current->next;
	current->next=newnode;
	return;
}

void reverse_list()
{

	struct node *prev=NULL,*curr=head,*temp=NULL;
	while(curr)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	head=prev;
	
}
void display()
{
	struct node *current=head;
	while(current)
	{
		cout<<current->data<<endl;
		current=current->next;
	}
}

int main()
{
	insert_node(10);
	insert_node(20);
	insert_node(30);
	insert_node(100);
	display();
	cout<<"After reversing the list"<<endl;

	reverse_list();
	display();
}
