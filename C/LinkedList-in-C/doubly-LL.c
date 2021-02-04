
#include <stdio.h>
#include <stdlib.h>
//******************Global Space****************************
typedef struct
{
    struct Doubly_Node_t *prev;
    int data;
    struct Doubly_Node_t *next;

}Doubly_Node_t;

Doubly_Node_t *head = NULL;
Doubly_Node_t *last = NULL;

//******************Prototypes******************************
void Create_dLL(int *A, int Elements);
void Insert_DLL(Doubly_Node_t *ptr, int value, int position);
void Display_forward_dLL(Doubly_Node_t *ptr);
void Display_reverse_dLL(Doubly_Node_t *ptr);
int Length_dLL(Doubly_Node_t *ptr);
int Delete_dLL(Doubly_Node_t *ptr, int position);

//******************Implementations*************************
int Delete_dLL(Doubly_Node_t *ptr, int position)
{
    int x = -1;
    int i;
    if(position == 1)
    {
        head = head->next;
        if(head != NULL)
        {
            head->prev = NULL;
        }
        x = ptr->data;
        free(ptr);
    }else
    {
        for(i=1 ; i<position-1 ; i++)
        {
            ptr = ptr->next;
        }

        ptr->prev->next = ptr->next;
        if(ptr->next != NULL)
        {
            ptr->next->prev = ptr->prev;
        }
        x = ptr->data;

        free(ptr);
    }

    return x;
}



//Creates a DLL from the array passed to it
void Create_dLL(int *A, int Elements)
{
    int i;
    Doubly_Node_t *temp;
    head = (Doubly_Node_t*)malloc(sizeof(Doubly_Node_t));
    head->data = *A;
    head->prev = NULL;
    head->next = NULL;

    last = head;

    for(i=1 ; i<Elements ; i++)
    {
        temp = (Doubly_Node_t*)malloc(sizeof(Doubly_Node_t));
        temp->data = *(A+i);
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }

}

void Insert_DLL(Doubly_Node_t *ptr, int value, int position)
{
    //At the very start of the DLL
    if(position == 0)
    {
        Doubly_Node_t *temp = (Doubly_Node_t*)malloc(sizeof(Doubly_Node_t));
        temp->data = value;

        //modifying links
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }else
    {
        for(int i=0 ; i<position-1 ; i++)
        {
            ptr = ptr->next;
        }
        Doubly_Node_t *temp = (Doubly_Node_t*)malloc(sizeof(Doubly_Node_t));
        temp->data = value;

        temp->next = ptr->next;
        temp->prev = ptr;
        //ptr->next->prev = temp;
        ptr->next = temp;
    }
}


//Displays DLL
void Display_forward_dLL(Doubly_Node_t *ptr)
{
    while(ptr != NULL)
    {
        printf("%d\n ", ptr->data);
        ptr= ptr->next;

    }
    printf("\n");
}



//Displaying DLL in reverse, Since we had a last pointer, we don't need to traverse till the end of DLL
void Display_reverse_dLL(Doubly_Node_t *ptr)
{
    while(ptr != head)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
    }
    printf("%d", ptr->data);
    printf("\n");
}



//Returns the number of elements present in the DLL
int Length_dLL(Doubly_Node_t *ptr)
{
    int count = 0;

    while(ptr)
    {
        count++;
        ptr = ptr->next;
    }

    return count;

}


//Application
int main(void)
{
    int A[5] = {10,20,30,40,50};

    Create_dLL(&A, 5);

    printf("***********Display the DLL forward***********\n ");
    Display_forward_dLL(head);
    printf("***********Display the DLL in reverse*********\n");
    Display_reverse_dLL(last);

    Insert_DLL(head, 4,4);
    printf("***********Display the DLL forward***********\n ");
    Display_forward_dLL(head);

    return 0;
}
