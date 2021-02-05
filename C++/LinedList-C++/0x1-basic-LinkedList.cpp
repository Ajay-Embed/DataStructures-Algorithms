#include <iostream>
#include <string>

using namespace std;


//Class for LL-Nodes
class node
{
public:
    int data;
    node *pnext;
};


//Class for LL
class LL
{

private:
    node *phead;

public:

    //constructor which sets the head pointer to NULL
    LL()
    {
        phead = NULL;
    }

    //constructor to initialize the LL with elements
    LL(int *A, int NumberOfElements);

     //Destructor
    ~LL();

    void Display();
    void Delete(int position);
    void Insert_LL(int position, int value);

};



/*
    Creating a LL from a passed Array
*/

LL::LL(int *A, int NumberOfElements)
{
    int i;
    node *t, *last=NULL;

    phead = new node;
    phead->data = *(A);
    phead->pnext = NULL;
    last = phead;

    for(i=1 ; i<NumberOfElements ; i++)
    {
        t = new node;
        t->data = *(A+i);
        t->pnext = NULL;
        last->pnext = t;
        last = t;
    }
}



/*
    Displaying LL
*/
void LL::Display()
{
    node *ptr = phead;

    while(ptr != NULL)
    {
        cout<<ptr->data<<endl;
        ptr = ptr->pnext;
    }
}



/*
    Deleting the entire LL
*/
LL::~LL()
{
    node *ptr = phead;

    while(phead)
    {
        phead = phead->pnext;
        delete(ptr);
        ptr = phead;
    }
}



/*
    Inserting at a given position in the LL
*/
void LL::Insert_LL(int position, int value)
{
    node *ptr = phead;

    node *temp = new node;
    temp->data = value;
    temp->pnext = NULL;
    int i;

    if(position == 0)
    {
        temp->pnext = phead;
        phead = temp;
    }else
    {
        for(i=0 ; i<position-1 ; i++)
        {
            ptr = ptr->pnext;
        }

        temp->pnext = ptr->pnext;
        ptr->pnext = temp;
    }
}


//Application
int main()
{
    cout << "Hello world!" << endl;
    int Array[5] = {1,2,3,4,5};

    //Initializing LL with an array of 4 elements
    LL LL(Array, 4);

    //Display
    LL.Display();
    return 0;
}
