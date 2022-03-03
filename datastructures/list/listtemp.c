
#include <stdio.h>
#include <malloc.h>

struct Lakshna
{
    int data;
    struct Lakshna *next;
};

struct Lakshna *START = NULL;

int main()
{
    int count,value;
    void addatend(struct Lakshna *,int);
    void addatbeginning(struct Lakshna *,int);
    void printlinklist();
    int searchlinklist(int);
    struct Lakshna *temp = NULL;
    for(count = 0; count < 10; count++)
    {
        temp = (struct Lakshna *)malloc(sizeof(struct Lakshna));
        addatend(temp, (count+10));
    }

    for(count = 0; count < 10; count++)
    {
        temp = (struct Lakshna *)malloc(sizeof(struct Lakshna));
        addatbeginning(temp, (count+20));
    }
    printlinklist();
    value = searchlinklist(37);
    if(value == 1)
       printf("The value is found\n");
    else
       printf("The value is not found\n");
 
}


void addatend(struct Lakshna *local,int x)
{
    struct Lakshna *traceptr = START;
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
	
int searchlinklist(
void addatbeginning(struct Lakshna *local,int x)
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
	struct Lakshna *traceptr = START;
	while (traceptr != NULL)
	{
	    printf(" %d", traceptr->data);
	    traceptr = traceptr->next;
	}
}	
int searchlinklist(int x)
{
	struct Lakshna *traceptr = START;
	while (traceptr != NULL)
	{
		if(transptr-> data == x)
		return 1;
		traceptr = traceptr->next;
	}
	return 0;
}
	

			





