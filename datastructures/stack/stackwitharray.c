
#include <stdio.h>
#define SIZE 10
int top = -1;
int stack[SIZE];


int main()
{
   int count,value;
   void push(int);
   int pop();
   void showstack(); 
   for(count = 0; count < 12; count ++)
   {
       push((count + 20));
   }
   showstack();
   for(count = 0; count < 11; count ++)
   {
       value = pop();
       if(value != -1)
          printf("The value you just popped is %d \n",value);
   }

}


void push(int data)
{
   if(top == (SIZE-1))
       printf("The stack is full\n");
   else
   {
       top = top + 1;
       stack[top] = data;
   }
}


void showstack()
{
    int count;
    for(count = 0; count <= top; count++)
    {
        printf(" %d\n",stack[count]);
    }
}


int pop()
{
        int temp;
	if(top == -1)
	{
	    printf("\nThe stack is Empty\n");
	    return -1;
	}
	else
        {
            temp = top;
	    top = top - 1;
            return(stack[temp]);
        }
}
