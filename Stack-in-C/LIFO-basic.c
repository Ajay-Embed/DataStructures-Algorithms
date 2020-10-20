
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

//Menu driven program utilising stack
typedef struct{

    int item[SIZE];
    int top;

}Stack;

void push(Stack *sp, int value);
int pop(Stack *sp);
void Stack_init(Stack *sp);


int main()
{
    Stack s1, s2; //2 stack objects from which we will push and pop the values

    Stack_init(&s1);
    Stack_init(&s2);

    push(&s1, 100);
    push(&s1, 200);
    push(&s1, 300);
    push(&s1, 400);
    push(&s1, 500);


    push(&s2, 1000);
    push(&s2, 2000);
    push(&s2, 3000);
    push(&s2, 4000);
    push(&s2, 5000);

    printf("Popping from s1 LIFO fashion %d\n", pop(&s1));
    printf("Popping from s1 LIFO fashion %d\n", pop(&s1));
    printf("Popping from s1 LIFO fashion %d\n", pop(&s1));
    printf("Popping from s1 LIFO fashion %d\n", pop(&s1));
    printf("Popping from s1 LIFO fashion %d\n", pop(&s1));
    printf("*****************************************\n");
    printf("Popping from s1 LIFO fashion %d\n", pop(&s2));
    printf("Popping from s1 LIFO fashion %d\n", pop(&s2));
    printf("Popping from s1 LIFO fashion %d\n", pop(&s2));
    printf("Popping from s1 LIFO fashion %d\n", pop(&s2));
    printf("Popping from s1 LIFO fashion %d\n", pop(&s2));

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
