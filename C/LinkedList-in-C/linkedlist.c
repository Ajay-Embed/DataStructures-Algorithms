#include <stdio.h>
#include <stdlib.h>

/* The main data structure that creates a linked list. 
 *
 * A Linked List node is expected to have data variables 
 * that store the actual data and a self-referential variable 
 * that connects this node to the next node in the list. 
 *
 * That's how the list is formed and linked. It's jus some 
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


/* Creating a Linked List
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

int main(void)
{
  LinkedListNode_t* head = create_linkedlist(); 


  return 0; 
}
