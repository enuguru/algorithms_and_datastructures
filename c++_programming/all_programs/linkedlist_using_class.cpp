#include <iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
	Node(int d)
	{
		this->data=d;
		this->next=NULL;
	}
};

class Linkedlist
{
	public:
	Node *head;
	Node *tail;
	Linkedlist()
	{
		this->head=NULL;
		this->tail=NULL;
	}

	void insert(int data)
	{
		Node *node=new Node(data);
		if(!this->head)
		{
			this->head=node;
		}
		else
		{
			this->tail->next=node;
		}
		this->tail=node;
	}
	Node* merge_sorted_list(Node *l1,Node *l2)
	{
		Node *current=NULL;
		Node *dummy_head=current;
		while(l1!=NULL && l2!=NULL)
		{
			if(l1->data<l2->data)
			{
				current->next=l1;
				l1=l1->next;
			}
			else if(l1->data>l2->data)
			{
				current->next=l2;
				l2=l2->next;
			}

			current=current->next;
		}
		if(l1)
			current->next=l1;
		else
			current->next=l2;

		return dummy_head->next;
	}

	void display()
	{
		Node *current=head;
		while(current)
		{
			cout<<current->data<<"\n"<<endl;
			current=current->next;
		}
	}
};

int main()
{
	Linkedlist *mylist=new Linkedlist();
	Linkedlist *slist=new Linkedlist();
	Linkedlist *tlist=new Linkedlist();
	slist->insert(5);
	slist->insert(11);
	mylist->insert(10);
	mylist->insert(20);
	tlist->head=tlist->merge_sorted_list(mylist->head,slist->head);
	tlist->display();
	return 0;
}
