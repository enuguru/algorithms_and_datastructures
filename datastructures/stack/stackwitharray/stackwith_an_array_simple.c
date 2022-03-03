
#include <stdio.h>
#define MAXSIZE 5
int stack[MAXSIZE];
int top;

void push ();
void pop();
void display ();
void search();
void isstackfull();
void isstackempty();

int main() {

    int element, choice;

    top = -1;

    while (1)
    {
        printf ("\nThis is the Menu Driven Stack\n");
        printf ("What do you want to do in the stack\n");

        printf ("------------------------------------------\n");
        printf ("1. PUSH\n");
        printf ("2. POP\n");
        printf ("3. DISPLAY\n");
        printf ("4. SEARCH\n");
        printf ("5. IS STACK FULL\n");
        printf ("6. IS STACK EMPTY\n");
        printf ("7. EXIT\n");
        printf ("------------------------------------------\n");

        printf ("Enter your choice\n");
        scanf   ("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            isstackfull();
            break;
        case 6:
            isstackempty();
            break;
        case 7:
            return;
        }

    }

}

/*Function to add an element to the stack*/
void push()
{
    int num;

    if (top == (MAXSIZE - 1))
        printf ("Error: Overflow\n");
    else
    {
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &num);
        top = top + 1;
        stack[top] = num;
    }
}


/*Function to delete an element from the stack*/
void pop ()
{
    int num;
    if (top == - 1)
        printf ("Error: Stack Empty\n");
    else
    {
        num = stack[top];
        printf ("poped element is = %d\n", num);
        top = top - 1;
    }
}



/*Function to display the status of the stack*/
void display()
{
    int i;
    if (top == -1)
        printf ("Error: Stack Empty\n");
    else
    {
        printf ("\nItems in Stack\n");
        for (i = top; i >= 0; i--)
            printf ("%d\n", stack[i]);
    }
    printf ("\n");
}


void search()
{

    int i;
    int num;
    int flag=0;
    if (top == -1)
        printf ("Error: Stack Empty\n");
    else
    {
        printf ("Enter the element to be searched\n");
        scanf ("%d", &num);

        for (i = top; i >= 0; i--)
        {
            if(num==stack[i])
            {
                flag++;
                break;
            }
        }

        if(flag > 0)
            printf ("Element %d found in stack\n", num);
        else
            printf ("Element %d not found in stack\n", num);
    }
    printf ("\n");

}


/* function to check if stack is full */

void isstackfull()
{
    if(top == (MAXSIZE - 1))
        printf("\nThe stack is full, please do not push data\n");
    else
        printf("\nThe stack is not full, you can push data\n");
}

/* function to check if stack is empty */

void isstackempty()
{
    if(top == -1)
        printf("\nThe stack is empty, there is no data to pop\n");
    else
        printf("\nThe stack is not empty, you can pop data\n");
}
