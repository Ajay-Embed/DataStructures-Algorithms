#include <stdio.h>
#include <stdlib.h>

//We will be creating a general purpose stack using singly linkedList in this example
typedef struct
{
    int data;
    struct Node_t *next;
}Node_t;

Node_t *head = NULL;


void StackPUSH(Node_t *ptr, int value)
{
    Node_t *t = (Node_t *)malloc(sizeof(Node_t));
    t->data = value;

    //condition for the first element in the stack
    if(head == NULL)
    {
        //Insert the first element in the stack
        t->next = NULL;
        head = t;
    }
    else
    {
        t->data = value;
        t->next = head;
        head = t;
    }
}


int stackPOP(Node_t *ptr)
{
    int pop = 0;
    Node_t *q = head;

    if(head == NULL)
    {
        printf("Nothing to POP \n");
    }
    else
    {
        //q is a trailing pointer with head, one step behind head, so as to free the element that is popped
        q = head;

        pop = head->data;
        head = head->next;
        free(q);
    }
    return pop;
}



void displayStack(Node_t *ptr)
{
    while(ptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}




int main(void)
{

    for(int i=1 ; i<=5 ; i++)
    {
        StackPUSH(head, i);
    }

    //Displaying the created stack
    displayStack(head);

    printf("\n");

    //Displaying the popped elements from the stack
    while(head)
    {
        printf("%d ", stackPOP(head));
    }
    return 0;
}
