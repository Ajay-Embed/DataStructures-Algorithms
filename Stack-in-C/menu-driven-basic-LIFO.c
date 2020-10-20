#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

//Program for simple implementation of LIFO
typedef struct{

    int item[SIZE];
    int top;

}Stack;

void push(Stack *sp, int value);
int pop(Stack *sp);
void Stack_init(Stack *sp);

int main()
{
    Stack s1;
    Stack_init(&s1);

    printf("What do u want to do? -\n");
    printf("Enter 0 for PUSH -\n");
    printf("Enter 1 for POP -\n");
    printf("Enter 2 to EXIT program -\n");
    int choice, value;

    while(1)
    {
        printf("Enter choice \n");
        scanf("%d", &choice);

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


void push(Stack *sp, int value)
{
    if(sp->top == (SIZE-1))
    {
        printf("Stack overflow\r\n");
        return;
    }else
    {
        sp->top++;
        sp->item[sp->top] = value;
    }
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

void Stack_init(Stack *sp)
{
    sp->top = -1;                           //Initializing to an invalid index so that it can be incremented to zero
}

