

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
void printBinary(unsigned int);

int main()
{
    printBinary(10);

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

void printBinary(unsigned int n)
{
    Stack s;
    Stack_init(&s, 10);
    const int BASE = 2;

    while(n > 0)
    {
        int rem = n % BASE;
        push(&s, rem);
        n /= BASE;
    }

    printf("BINARY EQUIVALENT OF %d is = ", n);
    while(s.top != -1)
    {
        printf("%d", pop(&s));
    }

    deallocate(&s);

}
