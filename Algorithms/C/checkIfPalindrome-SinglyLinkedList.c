/*************************************************************************************************************************
				We are checking if the elements of a Singly LinkedList form a Plaindrome or Not.	

**************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>


/*************************************************************** User defined MACROS *********************************************************** */
#define SIZE_OF_ARRAY 9

/*************************************************************** Global Space ******************************************************************* */
typedef struct Node
{
    int data;
    struct Node *next;

}Node;

//Global pointer to Node for operating LL
Node *first = NULL;
Node *last = NULL;

//Global array to copy the contents of the LL
int Arrray[SIZE_OF_ARRAY] = {0};

//array index
int j=0;


/*************************************************************** Prototypes ******************************************************************* */
void Insert_Last_LL(Node *p, int value);
void PushToArray(struct Node *ptr);
void Validate(struct Node *ptr);



/*************************************************************** Implementations ************************************************************** */
//Inserts a Node at the last of the LL
void Insert_Last_LL(Node *p, int value)
{
    //concept of last pointer that points towards the end of linked list.

    Node *t;
    t = (Node *)malloc(sizeof(Node));
    t->data = value;

    if(first == NULL)
    {
        first = t;
        last = t;
    }else
    {
        last->next = t;
        t->next = NULL;
        last = t;
    }
}

void Display_LL(struct Node *ptr)
{
    while(ptr)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }


}

void PushToArray(struct Node *ptr)
{
    int i=0;

    while(ptr != NULL)
    {
        Arrray[i] = (int)ptr->data;
        ptr= ptr->next;
        i++;
    }

    printf("Printing the array\n");
    printf("******************\n");

    for(j=0 ; j< 9 ; j++)
    {
        printf("%d \n", Arrray[j]);

    }
}


//Now array has the elements of the LL;
//Now we have to read back from array and compare the elements from the contents of the LL
void Validate(struct Node *ptr)
{
    int flag=0;

    j--;
    while(ptr != NULL)
    {
        if(ptr->data != Arrray[j])
        {
            flag=1;
        }

        ptr = ptr->next;
        j--;
    }

    if(flag==0)
    {
        printf("Palindrome");
    }else
    {
        printf("Not a Palindrome");
    }
}


int main(void)
{

      Insert_Last_LL(first, 10);
      Insert_Last_LL(first, 20);
      Insert_Last_LL(first, 30);
      Insert_Last_LL(first, 90);
      Insert_Last_LL(first, 60);
      Insert_Last_LL(first, 90);
      Insert_Last_LL(first, 30);
      Insert_Last_LL(first, 20);
      Insert_Last_LL(first, 10);

/***************************************************************************
Create a dynamic array at runtime for entering everything yourself. Right now it's static

//      int x=0, i;
//      printf("Enter the number of elements to be entered in the LL\n");
//      scanf("%d", &x);
//
//      printf("Enter the LL\n");
//
//      int Element= 0;
//
//      for(i=0 ; i<x ; i++)
//      {
//        scanf("%d", &Element);
//        Insert_Last_LL(first, Element);
//      }

***************************************************************************/
      printf("Display the LL\n");
      Display_LL(first);

      PushToArray(first);
      Validate(first);

	return 0;
}
