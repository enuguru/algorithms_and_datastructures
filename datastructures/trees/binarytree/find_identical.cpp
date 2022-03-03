
#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Recursive function to check if two given binary trees are identical or not
int isIdentical(Node* x, Node* y)
{
    // if both trees are empty, return true
    if (x == nullptr && y == nullptr)
        return 1;

    // if both trees are non-empty and value of their root node matches,
    // recur for their left and right sub-tree
    return (x && y) && (x->key == y->key) &&
			isIdentical(x->left, y->left) &&
			isIdentical(x->right, y->right);
}

// main function
int main()
{
    // construct first tree
    Node* x = nullptr;

    x = new Node(15);
    x->left = new Node(10);
    x->right = new Node(20);
    x->left->left = new Node(8);
    x->left->right = new Node(12);
    x->right->left = new Node(16);
    x->right->right = new Node(25);

    // construct second tree
    Node* y = nullptr;

    y = new Node(15);
    y->left = new Node(10);
    y->right = new Node(20);
    y->left->left = new Node(8);
    y->left->right = new Node(12);
    y->right->left = new Node(16);
    y->right->right = new Node(25);

    if (isIdentical(x, y))
        cout << "Given binary Trees are identical" << endl;
    else
        cout << "Given binary Trees are not identical" << endl;

    return 0;
}
