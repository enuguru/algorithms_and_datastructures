
/*

Question: write an algorithm to convert a binary tree into a double linked list. For example, if the input is the binary tree below:

The output will be a double linked list like this:


Solution: there are two tasks in converting a binary tree to a linked list. First of all, we must traverse the tree and visit all the nodes. Second of all, we must break each node from the tree and add it into the linked list.


For traversing the tree, we'll use level / order traversal a.k.a breadth first search. If you are not familiar with that concept, here is the post for you :) Take your time to read it, I'll be right here when you come back!

To construct the linked list, each node will have its left pointer point to the node in front of it and its right pointer point to the node behind it in the linked list. For instance, if node 1 is in front of node 2 and node 3 is behind node 2 in the linked list, we'll set left pointer of node 2 to node 1 and right pointer of node 2 to node 3 (see picture above)

*/

#include<iostream>
#include<queue>
using namespace std;

struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* bt2DoubleLinkedList(struct Node* root)
{
  if (root == NULL)
    return NULL;
  queue nodeQueue;

  struct Node* head = root; //reference to head of the linked list
  struct Node* listIT = NULL; //current node being processed
  struct Node* prevNode = NULL; //previous node processed

  //initialize the stack
  nodeQueue.push(root);

  //convert to double linked list
  while (!nodeQueue.empty())
  {
    //process next node in stack
    prevNode = listIT; 
    listIT = nodeQueue.front();

    nodeQueue.pop();

    //add left child to stack
    if (listIT->left != NULL)
      nodeQueue.push(listIT->left);

    //add right child to stack
    if (listIT->right != NULL)
      nodeQueue.push(listIT->right);
    //add current node to linked list
    if (prevNode != NULL)
      prevNode->right = listIT;
    listIT->left = prevNode;
  }

  //connect end node of list to null
  listIT->right = NULL;
  return head;
}
