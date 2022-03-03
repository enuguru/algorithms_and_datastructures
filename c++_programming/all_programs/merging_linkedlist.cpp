
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

void push(node **head_ref,int data)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=*head_ref;
	*head_ref=newnode;
}

void merge(node **head,node **source)
{
	node *newnode=*source;
	*source=newnode->next;
	newnode->next=*head;
	*head=newnode;
}


node* move(node *a,node *b)
{
	node dummy_head;
	node *tail=&dummy_head;

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

		else if(a->data<=b->data)
		{
			merge(&tail->next,&a);
		}
		else
			merge(&tail->next,&b);
	
		tail=tail->next;
	}
	return dummy_head.next;
}



void print_linkedlist(struct node *head)
{
	struct node *root=head;
	while(root)
	{
		cout<<root->data<<endl;
		root=root->next;
	}
}

int main()
{
	struct node *a=NULL;
	struct node *b=NULL;
	push(&a,11);
	push(&a,10);
	push(&b,12);
	push(&b,5);
	node *res;
	res=move(a,b);
	print_linkedlist(res);
	return 0;
}
