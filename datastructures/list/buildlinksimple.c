
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *START = NULL;

int main()
{
    int count,value;
    void addatend(struct node *,int);
    void addatbeginning(struct node *,int);
    void printlinklist();
    int searchlinklist(int);
    struct node *temp = NULL;
    for(count = 0; count < 10; count++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        addatend(temp, (count+10));  /* here we put some value to the linked list */
    }


    for(count = 0; count < 10; count++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        addatbeginning(temp, (count+20));
    }

    printlinklist();
    value = searchlinklist(37);
    if(value == 1)
       printf("The value is found\n");
    else
       printf("The value is not found\n");
    
}


void addatend(struct node *local,int x)
{
    struct node *traceptr = START;
    traceptr = START;
    if(START == NULL)
    {
        local->data = x;
        local->next = NULL;
        START = local;
    }
    else
    {
        while(traceptr->next != NULL)
           traceptr = traceptr->next;
        traceptr -> next = local;
        local -> next = NULL;
        local -> data = x;
    }
}


void addatbeginning(struct node *local,int x)
{
   if(START == NULL)
   {
      local -> next = NULL;
      local -> data = x;
      START = local;
   }
   else
   {
      local->next = START;
      local->data = x;
      START = local;
   }
}

 


void printlinklist()
{
   struct node *traceptr = START;
   while(traceptr != NULL)
   {
      printf(" %d ",traceptr->data);
      traceptr = traceptr -> next;
   }
   printf("\n");
}


int searchlinklist(int x)
{
   struct node *traceptr = START;
   while(traceptr != NULL)
   {
      if(traceptr -> data == x)
         return 1;
      traceptr = traceptr -> next;
   }
   return 0;
}














