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
        printf("\r\nType in your choice\r\n1. Pre-Order\r\n2. In-Order\r\n3. Post-Order\r\n"); 
        
        scanf("%d",&choice); 
        switch(choice)
        {
            case 1 : display_preorder(tree); 
                     break; 

            case 2 : display_inorder(tree);
                     break;

            case 3 : display_postorder(tree); 
                     break; 

            default : printf("Invalid Selection!\r\n");  
        }  
    }
}

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
        queue[rear++] = node ; 
        
        while(rear != front)
        {
            node = queue[front++]; 
    
            /* Generate Left Sub-Tree */ 
            printf("Enter Left child of %d=", node->data); 
            scanf("%d", &val);
            if(val >= 0 ) 
            {   
               binary_tree_t* l_child = malloc(sizeof(binary_tree_t)); 
               
               l_child->data=val; 

               /* Avoid SIGSEGV! NULLify the child nodes (not done by malloc) */
               l_child->left = l_child->right=NULL;       
               node->left=l_child; 

               queue[rear++] = l_child;  
            }
            
            /* Generate Right Sub-Tree */
            printf("Enter Right child of %d=", node->data ); 
            scanf("%d", &val);
            if(val >= 0) 
            {   
               binary_tree_t* r_child = malloc(sizeof(binary_tree_t)); 
               
               r_child->data=val; 

               /* Avoid SIGSEGV! NULLify the child nodes (not done by malloc) */
               r_child->left = r_child->right=NULL; 

               node->right = r_child;

               queue[rear++] = r_child;  
            }
        }

        return tree; 
    }

}

/* 
 * Print the Preorder Traversal of the Binary Tree 
 * This function uses recursion to print the preorder traversal of the binary tree. 
 */

void display_preorder(binary_tree_t* tree)
{
    if(tree)
    {
        printf("%d ", tree->data); 
        display_preorder(tree->left); 
        display_preorder(tree->right); 
    }
}

/* 
 * Print the Inorder Traversal of the Binary Tree 
 * This function uses recursion to print the Inorder traversal of the binary tree.  
 */

void display_inorder(binary_tree_t* tree)
{
    if(tree)
    {
        display_inorder(tree->left); 
        printf("%d ", tree->data); 
        display_inorder(tree->right); 
    }
}


/* 
 * Print the Postorder Traversal of the Binary Tree 
 * This function uses recursion to print the Postorder traversal of the binary tree.  
 */

void display_postorder(binary_tree_t* tree)
{
    if(tree)
    {
        display_postorder(tree->left); 
        display_postorder(tree->right);
        printf("%d ", tree->data); 

    }
}


