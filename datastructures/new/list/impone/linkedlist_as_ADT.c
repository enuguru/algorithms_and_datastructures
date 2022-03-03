


#include <stdio.h>
#include <stdio.h>
#include  <malloc.h>
#include "LinkedList.h"

typedef struct listnode* Node; 

// This structure will define a Node to be a pointer to listnode

struct listnode 
{
	int item; 
	Node next;
}; 

// listnode will contain an integer item and a link 
// to the next node

struct linkedlist 
{
	Node head; 
	Node *pointer; 
	Node tail;
}; 


// linkedlist ADT will contain three node references. 
// head, a pointer to a node, and a tail


int nodeCount;

int main()
{
	int max_nodes;
	LinkedList mylist;
	max_nodes = 5;
	mylist = listInit(max_nodes);
	insertNext(mylist,5);
	insertNext(mylist,10);
	insertNext(mylist,15);
	insertNext(mylist,20);
	insertNext(mylist,25);
	return 0;
}


// Create a new node with a reference to a next node and an integer // item value

Node new(int item, Node next)
{
    Node n = malloc(sizeof n); 
    n->item = item; // Set its value to the int item argument
    n->next = next; // Set its pointer to next to itself
    return n;
}

// This function will move the list pointer to the next 
// node in the list

void next(LinkedList list)
{
    Node n = *list->pointer;
    list->pointer = &n->next;
}

// Return the value of the node to which the pointer points

int getNode(LinkedList list)
{
    return (*list->pointer)->item;
}
 
// Return the number of nodes in the list

int getNodeCount()
{
    return nodeCount;
}
 
// Initialize the list setting the head and tail nodes to null 
// and allowing the pointer to point to the head node

LinkedList listInit(int maxSize)
{
    LinkedList list = malloc(sizeof *list);
    list->head = NULL;
    list->tail = NULL;
    list->pointer = &list->head;    
    nodeCount = 0; // Set the initial node count to zero
    return list;
}
 
// Check to see if the list is empty by 
// returning 1 if the list is empty

int emptylist(LinkedList list)
{
    return list->head == NULL;
}
 
// Insert the next node in the list by simply passing two 

void insertNext(LinkedList list, int item)
{
    Node n = new(item, NULL); 

// Create a new node with a NULL pointer value    
// Check to see if this new node is the first node inserted by 
// seeing if the head node contains no value

    if(list->head == NULL)
    {
        list->tail = n; // Set the tail equal to the new node
        list->head = list->tail; // Set the head equal to the tail
        nodeCount++; // Increment the node counter
        return;
    }
    
// If the inserted node is not the head simplly set the 
// tail's next node to node n

    list->tail->next = n;
    list->tail = list->tail->next; 

    nodeCount++; // Increment the node counter
}
 
// Remove a node from the passed list

int removeNode(LinkedList list)
{
    Node n; // Reference node n
    n = *list->pointer; 

    *list->pointer = (*list->pointer)->next; 

    nodeCount--; // Decrement the node counter
    return n->item; // Return the integer value of the removed node
}
 
// Move through the passed list by means of the list pointer

void traverseList(LinkedList list)
{
    list->pointer = &list->head; 
    int i = 1; // This integer value is just for output clarity
    while(*list->pointer != NULL)
    {
        printf("List[%d]: %d\n", i++, (*list->pointer)->item);
        next(list); // Move along the list to the next node
    }
}
 

void setNode(LinkedList list, int item)
{
    (*list->pointer)->item = item;
}
 

// Set the list pointer to the first node in the list

void first(LinkedList list)
{
    list->pointer = &list->head;
}
 
// Set the list pointer to the last node in the list

void last(LinkedList list)
{
    list->pointer = &list->tail;
}
 
// Deallocate the space used for the list and set the head and tail // equal to null

void listEmpty(LinkedList list)
{
    list->head = NULL;
    list->tail = NULL;
    *list->pointer = NULL;
    free(list);
}




