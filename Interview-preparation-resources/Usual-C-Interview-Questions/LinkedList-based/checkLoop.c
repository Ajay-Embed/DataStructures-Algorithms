

//Function to check if a loop exists in a singly linkedlist using a fast pointer.
int checkLoop(Node *ptr)
{
    Node *q = first;

    do
    {
        ptr = ptr->next;

        //fast pointer, move double as much as ptr moves so that they meet again somewhere if a loop exists
        q = q->next;

        if(q != NULL)
        {
            q = q->next;

        }else
        {
            //let q be NULL only
            q = NULL;
        }
    }while((ptr!=q) && (ptr&&q));

    return ((ptr==q) ? 1 : 0);
}
