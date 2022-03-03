#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};

struct node* create_node(int data)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

struct node* insert_node(struct node *root,int data)
{
	struct node *newnode=create_node(data);
	if(root==NULL)
	{
		root=newnode;
		return root;
	}
	else
	{
		struct node *current=root;
		while(current->next!=NULL)
			current=current->next;
		current->next=newnode;
		return root;
	}
}

void print_node(struct node *root)
{
	struct node *current=root;
	while(current!=NULL)
	{
		cout<<current->data<<endl;
		current=current->next;
	}
}

int main()
{
	struct node *root=NULL;
	root=insert_node(root,10);
	insert_node(root,11);
	insert_node(root,100);
	print_node(root);
}
