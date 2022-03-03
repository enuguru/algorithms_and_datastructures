
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

// Recursive function to delete given binary tree
void deleteBinaryTree(Node* &root)
{
    // Base case: empty tree
    if (root == nullptr)
        return;

    // delete left and right subtree first (Postorder)
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);

    // After deleting left and right sub-tree, delete the current node
    delete root;

    // set root as NULL before returning
    root = nullptr;
}

// main function
int main()
{
    Node* root = nullptr;

    root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    // delete entire tree
    deleteBinaryTree(root);

    if (root == nullptr)
        cout << "Tree Successfully Deleted" << endl;

    return 0;
}
