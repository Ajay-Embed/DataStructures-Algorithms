#include <stdio.h>
#include <stdlib.h> 

#define ESC 	  "\033"
#define ESC_RESET "\033[00m"

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

/* This file implements the Linked List representation of a Binary Tree. 
 * It implements functions that create a binary tree and print all three 
 * traversals possible on a binary tree, i.e. Preorder, Inorder & Postorder.
 *
 * This is an iterative implementation.
 *
 * TODO : 1. Dynamically Size the Queue
 *        2. Implement Iterative Traversals
 *
 */



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

binary_tree_t* queue[100]; 
int front, rear; 

/**********************************************
 *           Function Prototypes
 *********************************************/

binary_tree_t* plant_binary_tree(void);
void display_preorder(binary_tree_t* tree);
void display_inorder(binary_tree_t* tree);
void display_postorder(binary_tree_t* tree);
void display_level_order(binary_tree_t* tree);

int main(void)
{
    printf(ESC bGREEN"\r\n----------------Generate a Binary Tree--------------------\r\n"ESC_RESET);
    printf(ESC bRED"Please fill in a negative value to avoid creation of a node\r\n"ESC_RESET);
    printf("Visualize your tree first, before blaming the program\r\n(and report if there's a real bug :p)\r\n"); 
    printf("Let's plant your tree! Enter the value of Root Node \r\n"); 

    int choice=0; 
    binary_tree_t* tree = plant_binary_tree(); 

    if(tree == NULL)
    {
        printf("\r\nTree Not created!");
    }

    else
    {
        printf(ESC bGREEN"\r\nWe planted your tree!! How do you wish to see it??"ESC_RESET);
        printf("\r\nType in your choice:\r\n1. Pre-Order\r\n2. In-Order\r\n3. Post-Order\r\n4. Level Order\r\n5. Print all\r\n"); 
        
        scanf("%d",&choice); 
        switch(choice)
        {
            case 1 : display_preorder(tree); 
                     break; 

            case 2 : display_inorder(tree);
                     break;

            case 3 : display_postorder(tree); 
                     break;

            case 4 : display_level_order(tree);
                     break;

            case 5 : printf("\r\nPre-Order: ");
                     display_preorder(tree); 
                     
                     printf("\r\nIn-Order: ");
                     display_inorder(tree); 
                     
                     printf("\r\nPost-Order: ");
                     display_postorder(tree);
                    
                     printf("\r\nLevel-Order: ");
                     display_level_order(tree);
                     break;

            default : printf("Invalid Selection!\r\n");  
                      break;
        } 


    }
}

/* 
 * Generating a Binary Tree 
 *
 * This function generates the Binary Tree using iteration.
 *
 * A queue is maintained to keep track of all the nodes that are yet to be filled up/connected to their children. 
 * We first fill in the value for a particular node, and then fill it's left child first. Once the left child of a node
 * has been filled, we go and insert the right child for the node. Entering a negative value means the node wasn't created. 
 * After calling malloc(), we check if the memory was allocated for the node, if failed we return NULL. We don't allocate 
 * memory in case the value entered was negative. 
 *
 */ 

binary_tree_t* plant_binary_tree(void)
{
    int val;
    binary_tree_t* tree;
    binary_tree_t* node = malloc(sizeof(binary_tree_t)); 
    
    if(!node)
        return NULL ; 
    
    else
    {
        tree = node; 
        printf("Enter the value of Root=");
        scanf("%d", &val); 
        node->data = val; 

        /* Put the root node in the queue */ 
        queue[rear++] = node ; 
        
        while(rear != front)
        {
            /* Remove the node being processed */
            node = queue[front++]; 
    
            /* Generate Left Sub-Tree */ 
            printf("Enter Left child of %d=", node->data); 
            scanf("%d", &val);

            if(val >= 0 ) 
            {   
               binary_tree_t* l_child = malloc(sizeof(binary_tree_t)); 
               
               if(!l_child) 
               {
                   printf("Malloc Failed\r\n");
                   return NULL; 
               }

               l_child->data=val; 

               /* Avoid SIGSEGV! Set the child nodes as NULL (not done by malloc) */
               l_child->left = l_child->right=NULL;       
               node->left=l_child; 

               /* Add the left child to the queue as it will be the root for it's subtree */ 
               queue[rear++] = l_child;  
            }
            
            /* Generate Right Sub-Tree */
            printf("Enter Right child of %d=", node->data ); 
            scanf("%d", &val);
            if(val >= 0) 
            {   
               binary_tree_t* r_child = malloc(sizeof(binary_tree_t)); 
               
               if(!r_child) 
               {
                   printf("Malloc Failed\r\n");
                   return NULL; 
               }

               r_child->data=val; 

               /* Avoid SIGSEGV! Set the child nodes as NULL (not done by malloc) */
               r_child->left = r_child->right=NULL; 

               node->right = r_child;

               /* Add the right child to the queue as it will be the root for it's subtree */ 
               queue[rear++] = r_child;  
            }
        }

        return tree; 
    }

}

/* 
 * Print the Preorder Traversal of the Binary Tree 
 *
 * This function uses iteration to print the preorder traversal of the binary tree. 
 * A stack of node pointers is maintained to keep track of nodes that aren't explored completely. 
 *
 */

void display_preorder(binary_tree_t* node)
{
    binary_tree_t* stack[100]; 
    int8_t top = -1; 

    /* Repeat till stack is empty or the last NULL node is encountered */
   
    while((top != -1) || node)
    {      
        if(node)
        {   
            /* Print node data first */ 
            printf(" %d", node->data);

            /* Push it on the stack */ 
            stack[++top]=node;

            /* Explore it's left child */
            node = node->left;
        }
        
        
        else
        {
            /* Pop the last node */ 
            node = stack[top--]; 

            /* Explore it's right child */ 
            node = node->right; 
        }
         
    }
    
}

/* 
 * Print the Inorder Traversal of the Binary Tree 
 * 
 * This function uses iteration to print the Inorder traversal of the binary tree.  
 * A stack of node pointers is maintained to keep track of nodes that aren't explored completely.
 *
 */

void display_inorder(binary_tree_t* node)
{
    binary_tree_t* stack[100]; 
    int8_t top = -1; 

    /* Repeat till stack is empty or the last NULL node is encountered */
    while((top != -1) || node)
    {      
        if(node)
        {
            /* Push the node on the stack */
            stack[++top]=node;
            /* Explore the left child first */
            node = node->left;
        }
        
        
        else
        {
            /* Pop the last traversed node */
            node = stack[top--]; 
            /* Print the latest node */
            printf(" %d", node->data);
            /* Explore the right child */
            node = node->right; 
        }
         
    }
    
}


/* 
 * Print the Postorder Traversal of the Binary Tree 
 * 
 * This function uses iteration to print the Postorder traversal of the binary tree.  
 * A stack of node pointers is maintained to keep track of nodes that aren't explored completely. 
 *
 */

void display_postorder(binary_tree_t* node)
{
    binary_tree_t* stack[100]; 
    int8_t top = -1; 

    while((top != -1) || node)
    {
        if(node)
        {
            /* Push current node on the stack */ 
            stack[++top]=node;
            /* Explore left child */
            node = node->left;
        }
       
        else
        {
            binary_tree_t* temp = stack[top]->right;
            
            if(!temp)
            {
                /* Pop the node */
                temp = stack[top--]; 
                /* Print the node */ 
                printf(" %d", temp->data);

                while((top != -1) && (stack[top]->right == temp))
                {
                    temp=stack[top--];
                    printf(" %d", temp->data);
                }
            }

            else
            {
                node=temp; 
            }
        }
    }   
}

/*
 * Print the Level-order Traversal of the Binary Tree
 *
 * This function uses iteration to print the Level-order traversal of the binary tree.
 * A queue of node pointers is maintained to keep track of nodes that aren't explored.
 *
 */

void display_level_order(binary_tree_t* node)
{
    binary_tree_t* queue[100];
    int rear = 0, front = 0;

    queue[rear++] = node;
    printf(" %d ", node->data);

    while(!(rear==front))
    {
        node = queue[front++];

        if(node->left)
        {
            printf("%d ", node->left->data);
            queue[rear++] = node->left;

        }

        if(node->right)
        {
            printf("%d ", node->right->data);
            queue[rear++] = node->right;
        }

    }
}


