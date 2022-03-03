
#include <stdio.h>
#include <malloc.h>

typedef struct node
{
   int data;
   struct node *next;
}NODE;

NODE *start = NULL;


void main()
{
   NODE *tempone;
   void push(NODE *,int);
   void print_stack();
   NODE *pop();
   int count,p;
   tempone = (NODE *)malloc(sizeof(NODE));
   while(1)
   {
        count =0;
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        scanf("%d",&p);
        push(temp, (p+10));
        count = p + 1;
   }
   print_stack();
   tempone = pop();
   print_stack();
}


void push(NODE *local, int x)
{
       
       if(start == NULL)
       {
           local->next = NULL;
           local->data = x;
           start = local;
       }
       else
       {
            local->next = start;
            local->data = x;
            start = local;
       }
}


void print_stack()
{
      
      NODE *traceptr = start;
      while(traceptr != NULL)
      {
           printf("%d\n",traceptr->data);
           traceptr = traceptr->next;
      }
}
          

NODE* pop()
{
     NODE *temp,*tempone;
     tempone = (NODE *)malloc(sizeof(NODE));
     if(start == NULL)
         printf("\n The stack is empty\n");
     printf("\n%d",start->data);
     temp = start;
     start = start->next;
     tempone = temp;
     free(temp);
     return tempone;
}
