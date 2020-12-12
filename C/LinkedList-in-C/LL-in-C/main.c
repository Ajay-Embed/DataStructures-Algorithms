#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node *next;

}Node;

//Global pointer to Node for operating LL
Node *first = NULL;
Node *last = NULL;
Node *second = NULL;

/*
Creating a LL using an ARRAY
*/
void create_LL(int A[], int Elements_in_arr)
{
    int i;
    Node *t, *last;

    //As the LL is empty i will cerate first node using first node
    first = (Node *)malloc(sizeof(Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1 ; i<Elements_in_arr ; i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

//Displaying a LL
void Display_LL(Node *p)
{
    while(p)
    {
        printf(" %d \n", p->data);
        p = p->next;
    }

}

//Recursive display
void Recursive_Display_LL(Node *p)
{
    if(p != NULL)
    {
        printf("%d \n", p->data);
        Recursive_Display_LL(p->next);
    }

}

//Recursive reverse display
Recursive_DisplayReverse_LL(Node *p)
{
    if(p != NULL)
    {
        Recursive_DisplayReverse_LL(p->next);
        printf("%d \n", p->data);
    }
}

//Counting nodes in the linked list
int CountingNodes_LL(Node *p)
{
    int count=0;
    while(p)
    {
        p = p->next;
        count++;
    }
    return count;
}

//Sum of all the elemenst of the linked list
int Sum_LL(Node *p)
{
    int sum=0;
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}


int Max_LL(Node *p)
{
    int Max=0;
    while(p)
    {
        if(Max < p->data)
        {
            Max = p->data;
        }
        p = p->next;
    }
return Max;
}


//Linear search
void Linear_Search(Node *p, int key)
{

    while(p)
    {
        if(p->data == key)
        {
            printf("Found! \n");
            return;
        }
    p = p->next;
    }
    printf("Not found\n");
}


//Moves the found KEY to head.
//Using this method will compensate the integrity of the linkedlist.
void Improved_Linear_Search(Node *p, int key)
{
    //We will need to use a tail pointer along with p, this pointer will be following p
    Node *q = NULL;

    while(p)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;

            printf("Found! \n");
            return;
        }
    q = p;
    p = p->next;
    }
    printf("Not found\n");

}


//Inserts at a particular position(index) of the LL
void Insert_LL(Node *p, int position, int Element)
{
    Node *t;
    t = (Node*)malloc(sizeof(Node));
    t->data = Element;

    if (position == 0)
    {
    //constant time taken
        t->next = first;
        first = t;
    }
    else
    {
    //Now we will be inserting at a given index, first we will nedd to get to that index using a for() and then insert by breaking and mending some connections
    for(int i=0 ; i < ((position-1) && (position!=NULL)) ; i++)
    {
        p = p->next;
    }

        t->next = p->next;
        p->next = t;
    }


}


//Inserts a Node at the last of the LL
void Insert_Last_LL(Node *p, int value)
{

    Node *t;
    t = (Node *)malloc(sizeof(Node));
    t->data = value;
    t->next = NULL;
    if(first == NULL)
    {
        first = last = t;
    }
    else
    {
        last ->next = t;
        last = t;
    }

}


//Inserts into a sorted LL at the relevant location
void Insert_Sorted_LL(Node *p, int value)
{
    Node *q=NULL, *t;

    p = first;

    t = (Node *)malloc(sizeof(Node));
    t->data = value;
    t->next = NULL;

    if(first == NULL)
    {
        //Insert at the very beginning
        first = t;
    }else
    {
    while(p && (value > p->data))
    {
        q = p;
        p = p->next;
    }

    if(p == first)
    {
        t->next = first;
        first = t;
    }else
    {
        t->next = q->next;      //or t->next = p;
        q->next = t;
    }

    }
}


//Deletes a node from the LL at the specified Index
int Delete_LL(Node *p, int position)
{
    int deleted_element = 0;
    Node *q = NULL;

    //Checking for invalid index
    if(position < 1 || position > CountingNodes_LL(first))
        return -1;


    //If element to be deleted is indexed at 1st position
    if(position == 1)
    {
        q = first;
        deleted_element = first->data;
        first = first->next;
        free(q);
        return deleted_element;
    }else   //if not indexed at 1 then we got to traverse till the position and then delete and replace links accordingly
    {
        for(int i = 0 ; i < (position-1) ; i++)
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            deleted_element = p->data;
            q->next = p->next;
            free(p);
            return deleted_element;
        }
    }
}


//Checcks if LL is sorted or NOT
void isSorted_LL(Node *p)
{
    int x = 0;
    while(p)
    {
        if(x > p->data)
        {
            printf("Not sorted!!!\n");
            return;
        }
        x = p->data;
        p = p->next;
    }

    printf("Sorted!!!\n");
}


//Removes adjacent duplicates from a sorted or unsorted LL
void Removing_AdjacentDuplicates_LL(Node *p)
{
    Node *q = first->next;

    while(q)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }

}

//Removes immediate duplicates from a sorted or unsorted LL
void Removing_Duplicates_LL(Node *p)
{
    Node *q = first->next;
    int x=0;
    while(q)
    {
        x = p->data;
        for(int i = 0 ; i< CountingNodes_LL(first) - i ; i++)
        {


        }
    }

}

//Auxillary array to reverse the data elements in the LL
void ReverseElements_LL(Node *p)
{
    int getCount = CountingNodes_LL(first);
    int *A = (int *)malloc(sizeof(int)*getCount); //this is our auxiliary array with the number of elements in the LL
    int i=0;
    while(p)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    printf("Elements in the array\n");
    for(int j=0 ; j< getCount ; j++)
    {
        printf("%d ", A[j]);
    }
    printf("\n");

    printf("Now copying elements back from the array to the LL\n\n");

    p = first; i--;

    while(p)
    {
        p->data = A[i--];
        p = p->next;
    }
    printf("Now displaying the LL in reverse\n");

}


//Reversing a LL by reversing Links
void ReverseLinks_LL(Node *p)
{
    Node *q=NULL, *r=NULL;        //sliding pointers

    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Concatenate_LL(Node *p, Node *q)
{
    while(p)
    {
    p = p->next;        // we reached the end of LL_1
    }

    p = second;        //joining the first LL to second first element

}

int main(void)
{

//int A[8] = {1,2,3,4,55,6,7,8};
//
//    //creating a LL of the above array
//    create_LL(A, 8);
//
//    printf("**********Normal display**********************\n");
//    Display_LL(first);
//
//    printf("**********Recursive display*******************\n");
//    Recursive_Display_LL(first);
//
//    printf("**********Recursive Reverse Display***********\n");
//    Recursive_DisplayReverse_LL(first);
//
//    printf("**********Counting Nodes**********************\n");
//    int count = printf("%d\n", CountingNodes_LL(first));
//
//    printf("**********Sum of all elements in the list*****\n");
//    int sum =   printf("%d\n", Sum_LL(first));
//
//    printf("**********Max of all elements in the list*****\n");
//    int Max =   printf("%d\n", Max_LL(first));
//
//    printf("*******Linear_Search********\n");
//    Linear_Search(first, 55);
//
//    printf("*******Improved Linear_Search********\n");
//    Improved_Linear_Search(first, 55);
//    Display_LL(first);
//
//    printf("*******Inserting in the LL********\n");
//    Insert_LL(first, 3, 400);
//    Display_LL(first);

      printf("*********Insert Last*****************\n");
      Insert_Last_LL(first, 20);
      Insert_Last_LL(first, 20);
      Insert_Last_LL(first, 20);
      Insert_Last_LL(first, 50);
      Insert_Last_LL(first, 60);

      Insert_Last_LL(second, 20);
      Insert_Last_LL(second, 20);
      Insert_Last_LL(second, 20);
      Insert_Last_LL(second, 50);
      Insert_Last_LL(second, 60);
      Display_LL(first);

//      printf("******Inserting in a sorted Linked List******\n");
//      Insert_Sorted_LL(first, 55);
//      Display_LL(first);
//
//      printf("******Deleting from a Linked List******\n");
//      int deleted_element = Delete_LL(first, 6);
//      printf("the deleted element is %d\n", deleted_element);
//      Display_LL(first);

//      printf("******cHECKING IF A Linked List is sorted******\n");
//      isSorted_LL(first);
//      Display_LL(first);
//
//        printf("******Removing Duplicates******\n");
//        Removing_AdjacentDuplicates_LL(first);
//        Display_LL(first);

//        printf("******Removing Duplicates******\n");
//        Removing_Duplicates_LL(first);
//        Display_LL(first);
//
//        printf("**************Reversing a LL******************\n");
//        ReverseElements_LL(first);
//        Display_LL(first);

//        printf("**************Reversing a LL******************\n");
//        ReverseLinks_LL(first);
//        Display_LL(first);

        printf("**************Concatenating 2 LL******************\n");
        Concatenate_LL(first, second);
        Display_LL(first);
    return 0;
}
