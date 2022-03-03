#include <iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
};

void insert_node(node **head_ref,int data)
{
	node *newnode=new node();
	newnode->data=data;
	newnode->next=*head_ref;
	*head_ref=newnode;
}

void display(node *a)
{
	node *current=a;
	while(current)
	{
		cout<<current->data<<" "<<endl;
		current=current->next;
	}
}

node* evenodd(node *a)
{
	node *odd=a->next;
	node *odd_cur=odd;
	node *even_cur=a;
	node *prev_cur=NULL;
	while(even_cur && odd_cur)
	{
		even_cur->next=odd_cur->next;
		prev_cur=even_cur;
		even_cur=even_cur->next;
		if(even_cur)
		{
			odd_cur->next=even_cur->next;
			odd_cur=odd_cur->next;
			
		}
	}
	if(even_cur)
		prev_cur=even_cur;
	if(prev_cur)
		prev_cur->next=odd;
	return a;
}
	


int main()
{
	node *a=NULL;
	insert_node(&a,4);
	insert_node(&a,3);
	insert_node(&a,2);
	insert_node(&a,1);
	insert_node(&a,0);
	node *b=evenodd(a);
	display(b);
	return 0;
}
