#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

#define MAX(a,b) (a > b ? a : b)
#define ESC 	  "\033"
#define ESC_RESET "\033[00m"
/* Max nodes in a binary tree */
#define MAX_NODES 100


/*******************************************
 * 
 * Just some terminal colours, do you mind? 
 *
 ******************************************/

#define bRED 	 "[1;31;40m"
#define bGREEN   "[1;32;40m"
#define bYELLOW  "[1;33;40m"
#define bBLUE 	 "[1;34;40m"
#define bMAGENTA "[1;35;40m"
#define bCYAN 	 "[1;36;40m"
#define bWHITE 	 "[1;37;40m"

/* The Main skeletal structure for our binary tree 
 *          _______________________
 *         |      |       |        |
 *         |      | Value |        |
 *         | Left |       | Right  |
 *         | Child|       | Child  |
 *         |______|_______|________|
 *             |                \___________________
 *             |                                    |
 *   __________|____________               _________|____________
 *  |      |       |        |             |      |       |       |
 *  |      | Value |        |             |      | Value |       |
 *  | Left |       | Right  |             | Left |       | Right |
 *  | Child|       | Child  |             | Child|       | Child |
 *  |______|_______|________|             |______|_______|_______|
 *
 */

typedef struct Tree
{
    struct Tree *left; 
    int data; 
    struct Tree *right;
    
} binary_tree_t;

typedef struct Queue
{
    binary_tree_t* q[MAX_NODES];
    int front; 
    int rear;
} queue_t;

void qpush(queue_t* Q, binary_tree_t* element)
{
    if((Q->rear + 1)%MAX_NODES == Q->front)
    {
        printf("Queue Full"); 
        return;
    }
    
    else
    {
        Q->q[Q->rear++] = element; 
    }
}

binary_tree_t* qfront(queue_t* Q)
{
    if(Q->rear == Q->front)
    {
        printf("Queue full");
        return NULL;
    }

    else
    {
        return Q->q[Q->front++];
    }
}

binary_tree_t* qPeek(queue_t* Q)
{
    return Q->q[Q->front];
}

bool Qempty(queue_t* Q)
{
    return (Q->front == Q->rear);
}

/* 
 * Print the Level-order Traversal of the Binary Tree 
 * This function prints the level order of the binary tree. 
 */

void display_levelorder(binary_tree_t* root, queue_t* Q)
{
    qpush(Q, root);

    while(Qempty(Q) != true)
    {
        binary_tree_t* node = qfront(Q);
        
        if(node)
        {
            if(node->left)
            {
                qpush(Q, node->left);
            }
        
            if(node->right)
            {
                qpush(Q, node->right);
            }

            printf(" %d ", node->data);
        }

    }
}

/******* Helper functions for the binary trees ********/

/* 
 * Generating a Binary Tree 
 *
 * This function generates the Binary Tree using recursion. The implementation is simple if you're aware of recursion. 
 * We first fill in the value for a particular node, and then fill it's left child first. Once the left child of a node
 * has been filled, we go and insert the right child for the node. Entering a negative value means the node wasn't created. 
 * After calling malloc(), we check if the memory was allocated for the node, if not **"NEVER DEREFERENCE A NULL POINTER"** 
 * We return NULL in case the value entered was negative or if malloc() failed to allocate the required memory. 
 * We are reading the value in pre-order fashion, as it is intuitive for most people.
 *
 */ 

binary_tree_t* plant_binary_tree(void)
{
    int value; 
    printf("\r\nEnter the value= ") ; 
    scanf("%d",&value); 
    
    if (value < 0)
        return NULL; 
    
    binary_tree_t* node = malloc(sizeof(binary_tree_t)); 
    if(node)
    {
        node->data=value; 
        
        printf("\r\nEnter the value of Left Child of %d", value);
        node->left = plant_binary_tree(); 

        printf("\r\nEnter the value of Right Child of %d", value); 
        node->right = plant_binary_tree(); 
    }
    
    return (node != NULL) ? node : NULL ; 
}

/* Auxillary queue, will always have as many elements as the width of the tree.
 * Space Complexity = O(w) or O(n) 
 */
queue_t Q;

int main(void)
{
    printf(ESC bGREEN"\r\n----------------Generate a Binary Tree--------------------\r\n"ESC_RESET);
    printf(ESC bRED"Please fill in a negative value to avoid creation of a node\r\n"ESC_RESET);
    printf("Visualize your tree first, before blaming the program\r\n(and report if there's a real bug :p)\r\n"); 
    printf("Let's plant your tree! Enter the value of Root Node \r\n"); 

    int k=0; 

    Q.rear = 0;
    Q.front = 0;
    binary_tree_t* tree = plant_binary_tree(); 

    if(tree == NULL)
    {
        printf("\r\nTree Not created!");
    }

    else
    {
        /* Display the tree */ 
        printf("\r\nLevel-order traversal of the tree: ");
        display_levelorder(tree, &Q);
    }

    return 0;
}
