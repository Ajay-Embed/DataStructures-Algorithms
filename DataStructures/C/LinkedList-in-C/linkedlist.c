#include <stdio.h>
#include <stdlib.h>

/* The main data structure that creates a linked list. 
 *
 * A Linked List node is expected to have data variables 
 * that store the actual data and a self-referential variable 
 * that connects this node to the next node in the list. 
 *
 * That's how the list is formed and linked. It's just some
 * structures/class objects linked together. 
 * As shown in the figure :
 *
 *  ______________________            ___________________
 * |Node N                |          | Node N+1          |     
 * |    Data variables    |          |  Data Variables   |
 * |______________________|          |___________________|
 * | Address of Next Node |--------->| Address of Next   |
 * |______________________|          |___________________|
 *
 *
 *
 * In C, we can only use structures. 
 * Note that one element in the structure (node *next) 
 * is a pointer to the same data type (same structure). 
 * This is known as self-referentiality. It's a tiny 
 * (but very cool) feature that C provides to make Linked Lists.
 *
 */

typedef struct node
{
    int data; 
    struct node *next;

} LinkedListNode_t ; 


/* 
 * Creating a Linked List
 *
 * Head Node: 
 * A general practice while creating linked lists is to
 * have a "Header" Node. The "Header" or Head Node is
 * responsible for giving an identity to the list by
 * providing the entry point/starting address of the linked list.
 *
 * This Node may hold some dummy data or some data that hold some 
 * information about the linked list like the number of nodes etc. 
 *
 * Note that the last node in a singly linked list shall point towards
 * NULL, i.e. the next address pointer of the last node should be NULL.
 *
 * For Example, A Linked List with one element should look like: 
 *
 *  ______________________            ___________________
 * |Header                |          | Node 1            |     
 * |    Data variables    |          |  Data Variables   |
 * |______________________|          |___________________|
 * | Address of 1st  Node |--------->| Address of Next   |---------
 * |______________________|          |___________________|         |
                                                                  NULL     
 *
 * Therefore, a creation of linked list should simply mean allocating 
 * memory for the head node and making it's Next Address field NULL. 
 *
 * Note: We are allocating memory directly here, and thus returning the 
 * address of a local variable is alright. Since this variable is NOT on
 * the Stack/Activation record of this function but on the heap.
 *
 */

LinkedListNode_t* create_linkedlist(void)
{
    LinkedListNode_t * head = malloc(sizeof(LinkedListNode_t)) ; 
    
    /* Let's store the number of nodes/items in head's data */
    head->data = 0 ; 
    head->next = NULL; 

    return head; 
}


/*
 * Inserting new elements at the end of a Linked List 
 *
 * Say the following is a new element/node that one wished to insert:
 *  ____________
 * |            |
 * |  Data = 15 |
 * | Next Addr. |
 * |____________|
 *
 * And the original list (before insertion) is as follows
 *
 *  ______________________            ___________________            __________________
 * |Header                |          | Node 1            |          |Node 2            |
 * |    Data variables    |          |  Data Variables   |          |   Data Variables |
 * |______________________|          |___________________|          |__________________|
 * | Address of 1st  Node |--------->| Address of Next   |--------->| Address of Next  |--------------
 * |______________________|          |___________________|          |__________________|             |
 *                                                                                                  NULL
 *
 * All we need to do is figure out which node hangs at the end of the list. 
 * How can we do that? By traversing through the list and figuring out which 
 * element/node's next pointer is NULL. 
 *
 * After figuring out the last node, all we need to do is hook up our new node
 * to the last one's next. 
 *
 *  ______________________            ___________________            __________________               _______________
 * |Header                |          | Node 1            |          |Node 2            |             | Node 3        |
 * |    Data variables    |          |  Data Variables   |          |   Data Variables |             |  Data = 15    |
 * |______________________|          |___________________|          |__________________|             |_______________|
 * | Address of 1st  Node |--------->| Address of Next   |--------->| Address of Next  |------------>|Address of Next|--------
 * |______________________|          |___________________|          |__________________|             |_______________|       |
 *                                                                                                                          NULL
 *                                                                                                                                                                                   
 *                                                                                        
 */

void insert_element(LinkedListNode_t* head, int data)
{
    /* Allocate memory for the new member */ 
    LinkedListNode_t* newNode = malloc(sizeof(LinkedListNode_t)); 

    /* Store the address of Head to avoid messing the original pointer */
    LinkedListNode_t *node = head; 

    /* Traverse till the last node */  
    while(node->next != NULL)
    {
        node = node->next; 
    }

    /* Link the New Node */
    node->next = newNode; 
    
    /* Fill in the data */ 
    newNode->data = data; 

    newNode->next = NULL;

    /* Increment number of elements in the head */
    head->data++ ; 
}

void display_list(LinkedListNode_t* head)
{
    LinkedListNode_t* node = head ; 
    int i = 1 ; 

    printf("Total Nodes = %d\r\n", head->data) ; 

    node = node->next; 

    while(node) 
    {  

        printf("Node-%d Data : %d\r\n", i++, node->data) ; 
        node = node->next; 
    }


}

int main(void)
{
    LinkedListNode_t* head = create_linkedlist(); 
    
     
    insert_element(head,10); 

    insert_element(head,30);

    insert_element(head,25);

    display_list(head); 
    

    return 0; 
}
