#include <stdio.h>
#include <stdlib.h>

//****************************Global Variables****************************
typedef struct{
    int data;
    struct Node_t *next;

}Node_t;

Node_t *head = NULL;


//**************************** Fncn Protoypes *****************************
void Insert_Circular_cLL(Node_t *ptr, int value, int position);
void Delete_Node_cLL(Node_t *ptr, int position);
void Display_cLL(Node_t *ptr);

//**************************** Implementations ****************************

//Inserting Node in a circular LinkedList
void Insert_Circular_cLL(Node_t *ptr, int value, int position)
{


    if(position == 0)
    {
        Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
        temp->data = value;
        if(head == NULL)
        {
            head = temp;
            head->next = head;
        }else
        {
            while(ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->next = head;
            head = temp;
        }

    }else
    {
        for(int i=0 ; i<position-1 ; i++)
        {
            ptr = ptr->next;

        }
            Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
            temp->data = value;
            temp->next = ptr->next;
            ptr->next = temp;

    }
}

void Delete_Node_cLL(Node_t *ptr, int position)
{
    Node_t *q;

    if(position == 1)
    {
        //Move ptr till the last node as it is a circular LL, thereby the last node will point towwards the first Node.
        while(ptr->next != head)
        {
            ptr = ptr->next;
        }

        if(head == ptr)
        {
            free(head);

            //Good practise to NULL the pointer after freeing/deleting, else expect system crash
            head=NULL;
        }
        else
        {

            ptr->next = head->next;

            free(head);

            head = ptr->next;
        }
    }
    else
    {
        for(int i=0 ; i<position-2 ; i++)
        {
            ptr = ptr->next;
            q   = ptr->next;
        }


        ptr->next = q->next;
        free(q);
    }
}

//Iterative display function for a circular LinkedList
void Display_cLL(Node_t *ptr)
{
    do{

    printf("%d\n", ptr->data);
    ptr = ptr->next;

    }while(ptr != head);


}



int main(void)
{
    Insert_Circular_cLL(head, 1, 0);
    Insert_Circular_cLL(head, 2, 1);
    Insert_Circular_cLL(head, 3, 2);
    Insert_Circular_cLL(head, 4, 3);
    Display_cLL(head);

    printf("***********Performing deletion********\n");
    Delete_Node_cLL(head, 3);
    Display_cLL(head);
    return 0;
}
