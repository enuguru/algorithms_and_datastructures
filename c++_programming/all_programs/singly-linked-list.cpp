#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;

struct node* create_node(int data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void insert(int data)
{
	struct node *newnode=create_node(data);
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
}

void display()
{
	struct node *temp=head;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

int main()
{
	insert(10);
	insert(20);
	display();
}
