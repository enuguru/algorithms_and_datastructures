#include <iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	Node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
Node *curr=NULL;

class BinaryTree
{
	public:
		Node* insert(Node *root,int data)
		{
			if(root==NULL)
				return new Node(data);
			else
			{

				if(data<root->data)
				{	
					curr=insert(root->left,data);
					root->left=curr;
				}
			
				else if(data>root->data)
				{	
					curr=insert(root->right,data);
					root->right=curr;
				}
			}
			return root;
		}
};

void pre_order(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"\n";
		pre_order(root->left);
		pre_order(root->right);
	}
}

int main()
{
	BinaryTree t;
	Node *root=NULL;
	root=t.insert(root,10);
	t.insert(root,9);
	t.insert(root,11);
	pre_order(root);
	return 0;

}

