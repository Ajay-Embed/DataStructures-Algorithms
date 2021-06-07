#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int data;
    struct Node *next;
}Node;

Node *first = NULL;




//Iterative method for removing duplicates in amsingly linked list
void RemoveDuplicates(Node *ptr)
{
    Node *q = first->next;

    while(q)
    {
        if(ptr->data != q->data)
        {
            ptr = q;
            q = q->next;
        }else
        {
            ptr->next = q->next;
            free(q);
            q = ptr->next;
        }
    }
}


//Function to insert at a given position in a singly linked list
void Insert_LL(Node *ptr, int value, int position)
{   
    //temp node
    Node *t = (Node *)malloc(sizeof(Node));

    if(position == 0)
    {
        t->data = value;
        t->next = NULL;
        first = t;

    }else
    {
        t->data = value;
        t->next = NULL;

        //Traverse to the position where we wsih to insert
        for(int i=0 ; i<position-1 ; i++)
        {
            ptr = ptr->next;
        }
        t->next = ptr->next;
        ptr->next = t;
    }
}


//recursive display 
void R_Display(Node *ptr)
{
    if(ptr)
    {
        printf("%d ", ptr->data);
        R_Display(ptr->next);
    }
}


int main(void)
{

    Insert_LL(first, 1, 0);
    Insert_LL(first, 1, 1);
    Insert_LL(first, 2, 2);
    Insert_LL(first, 2, 3);
    Insert_LL(first, 3, 4);
    Insert_LL(first, 3, 5);
    R_Display(first);
    printf("\n***************** After removing duplicates *******************\n");

    RemoveDuplicates(first);
    R_Display(first);


    return 0;
}