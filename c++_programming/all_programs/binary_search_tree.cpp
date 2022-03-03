#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

struct node* new_node(int data)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

struct node* insert_node(struct node *root,int data)
{
	struct node *curr;
	if(root==NULL)
		return new_node(data);
	else
	{
		if(root->data>data)
		{
			curr=insert_node(root->left,data);
			root->left=curr;
		}
		else if(root->data<data)
		{
			curr=insert_node(root->right,data);
			root->right=curr;
		}
	}

	return root;

}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" "<<endl;
		inorder(root->right);
	}
}

int get_height(struct node *root)
{
	if(root==NULL)
		return -1;
	int l_height=get_height(root->left);
	int r_height=get_height(root->right);
	if(l_height>=r_height)
		return l_height+1;
	else
		return r_height+1;
}


int main()
{
	root=insert_node(root,10);
	insert_node(root,7);
	insert_node(root,8);
	insert_node(root,11);
	insert_node(root,13);
	insert_node(root,15);
	insert_node(root,20);
	cout<<get_height(root)<<endl;
	return 0;
}

          
