
#include <stdio.h>
#include <stdlib.h>

//Program for dynamic implementation of LIFO
typedef struct{
    int *item;
    int top;
    int size;
}Stack;

void push(Stack *sp, int value);
int pop(Stack *sp);
void Stack_init(Stack *sp, int size);
void deallocate(Stack *sp);
int getSize(Stack *sp);

int main()
{
    Stack s1;
    Stack_init(&s1, 3);
    printf("Current size of stack %d\n", getSize(&s1));
    printf("What do u want to do? -\n");
    printf("Enter 0 for PUSH -\n");
    printf("Enter 1 for POP -\n");
    printf("Enter 2 to EXIT program -\n");
    int choice, value;

    while(1)
    {
        printf("Enter choice \n");
        scanf("%d", &choice);
        printf("Current size of stack %d\n", getSize(&s1));
        switch(choice)
        {
            case 0:
                printf("Enter value\n");
                scanf("%d", &value);
                push(&s1, value);
            break;

            case 1:
                value = pop(&s1);
                if(value != -1)
                {
                    printf("Popped data is %d", value);
                }
            break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }

    }


    return 0;
}

//In this program if there is a stack overflow we assign a double size memory are a to the existing dynamic stack
void push(Stack *sp, int value)
{
    if(sp->top == (sp->size-1))
    {

        int *temp;
        temp = (int *)malloc((sizeof(int)*sp->size)*2);  //Now if there is a stack overflow we assign double the stack space
        if(temp == NULL)
        {
            //printf("Stack overflow\r\n");
            return;
        }
        int i;
        for(i=0 ; i<sp->top ; ++i)
        {
            temp[i] = sp->item[i];      //Assign all the elements of sp->item memory to temp for now
        }
        free(sp->item);
        sp->item = temp;
        sp->size *= 2;
        return;

    }

    sp->top++;
    sp->item[sp->top] = value;
}

int pop(Stack *sp)
{
    if(sp->top == -1)
    {
        printf("Stack underflow\r\n");
        return -1;
    }else
    {
        int value=0;
        value = sp->item[sp->top];
        sp->top--;

        return value;
    }
}

void Stack_init(Stack *sp, int size)
{
    sp->top = -1;                           //Initializing to an invalid index so that it can be incremented to zero
    sp->item = (int *)malloc(sizeof(int) * size);
    if(sp->item == NULL)
    {
        printf("Memory allocation failed, termination in progress\n");
        exit(1);
    }
    sp->size = size;
}

void deallocate(Stack *sp)
{
    if(sp->item != NULL)
    {
        free(sp->item);
    }

    sp->top = -1;
    sp->size = 0;

}

int getSize(Stack *sp)
{
    return sp->size;
}
