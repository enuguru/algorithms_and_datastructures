

// this is a recursive call to the linked list, this is a superb program
// cannot appreciate it enough

struct node* recursiveReverseLL(struct node* first)
{

   if(first == NULL) 
       return NULL; // list does not exist

   if(first->link == NULL) 
       return first; // list with only one node

   struct node* rest = recursiveReverseLL(first->link); // recursive call on rest.
   first->lnk->link= first; // make first; link to the last node in the reversed rest.
   first->link = NULL; // since first is the new last..make its link NULL.
   return rest; // rest now points to the head of the reversed list.

}
