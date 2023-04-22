// Iterative C program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};


/* Function to push a node */
void append(struct Node** head_ref, int new_data)
{
	struct Node *traceptr = (*head_ref);
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;

	if(*head_ref == NULL)
	{
		(*head_ref) = new_node;
	}
	else
	{
		while(traceptr->next != NULL)
			traceptr = traceptr->next;
		traceptr->next = new_node;
	}
}


/* Function to print linked list */
void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	append(&head, 20);
	append(&head, 4);
	append(&head, 15);
	append(&head, 85);
	append(&head, 73);
	append(&head, 67);
	append(&head, 99);

	printf("Given linked list\n");
	printList(head);
	getchar();
}
