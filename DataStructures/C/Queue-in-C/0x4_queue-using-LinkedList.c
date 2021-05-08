#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int data;
    struct Node_t *next;
}Node_t;

Node_t *front = NULL;
Node_t *rear = NULL;


void EnQ(int value)
{
    Node_t *temp = (Node_t *)malloc(sizeof(Node_t));

    if(temp == NULL)
    {
        printf("Malloc failed, Queue Full!\n");
    }

    temp->data = value;
    temp->next = NULL;

    if(front == NULL)
    {
        //Implies that the inserted value is the first element in the Q
        front = rear = temp;
    }else
    {
        rear->next = temp;
        rear = rear->next;
    }
}


int DeQ()
{
    int x = -1;

    Node_t *temp;

    if(front == NULL)
    {
        printf("Queue Empty\n");
    }

    x = front->data;
    temp = front;
    front = front->next;

    free(temp);

    return x;
}

void Display(Node_t *ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}


int main(void)
{
    //EnQing
    for(int i=0 ; i<5 ; i++)
    {
        EnQ(i*10);
    }

    Display(front);
    printf("**************\n");

    //DeQing
    DeQ();
    DeQ();

    Display(front);
    return 0;
}
