/*
    Chaining is a method to create a hash function such that the function is now responsible
    for chaining the list of the numbers that keep getting added to the list, the list maintained
    at each chained position is more easily accessible as compared to the traversing the entire
    list.
    The worst case scenario is having to tie up all the elements in the array to a single pointer,
    which doesn't essentially slow down the approach but is more or less the same as to not creating
    the list in the first place.
*/

#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************************************
Singly LL specific methods
******************************************************************************************************/
typedef struct
{
    int data;
    struct Node_t* next;
}Node_t;


void LL_InsertSorted(Node_t **ch, int value)
{
    //A temp node to insert member in the LL, a tailing q pointer to p, *p=*ch because at each insert we have to
    //insert at the corresponding chain
    Node_t *temp,*q=NULL,*ptr=*ch;

    //
    temp=(Node_t*)malloc(sizeof(Node_t));
    temp->data = value;
    temp->next = NULL;

    if(*ch==NULL)
    {
        *ch=temp;
    }
    else
    {
        while((ptr != NULL) && (ptr->data < value))
        {
            q=ptr;
            ptr=ptr->next;
        }
        if(ptr==*ch)
        {
            temp->next=*ch;
            *ch=temp;
        }
        else
        {
            temp->next=q->next;
            q->next=temp;
        }
    }
}

//Seraching the given key in the chain
Node_t* LL_Search(Node_t *ptr, int key)
{
    while(ptr!=NULL)
    {
        if(key==ptr->data)
        {
            return ptr;
        }
        ptr=ptr->next;
    }
    return NULL;
}



/*****************************************************************************************************
Hashing specific methods
******************************************************************************************************/
int Hash_Calc(int key)
{
    return key%10;
}

void Hash_Insert(Node_t *Hash[], int value)
{
    int index = Hash_Calc(value);
    LL_InsertSorted(&Hash[index], value);
}



/*****************************************************************************************************
Application code
******************************************************************************************************/
int main(void)
{
    Node_t *HashTable[10];

    for(int i = 0; i < 10; i++)
    {
        HashTable[i]=NULL;
    }

    Hash_Insert(HashTable,12);
    Hash_Insert(HashTable,22);
    Hash_Insert(HashTable,42);

    Node_t *temp=NULL;
    temp=LL_Search(HashTable[Hash_Calc(22)],22);

    printf("%d ",temp->data);


    return 0;
}
