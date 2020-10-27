#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct{
    int item[SIZE];
    int front, rear;
}Q;

void Q_Init(Q *);
void Q_EnQ(Q *, int);
int Q_DeQ(Q *);
void print_menu();



int main(void)
{
    Q q;
    Q_Init(&q);
    int value = 0, quit = 0;
    print_menu();

    while(!quit)
    {
    int choice = 0;
    printf("Enter your choice \n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
                printf("ENQUEUE CHOSEN\n");
                scanf("%d", &value);
                Q_EnQ(&q, value);
                break;

        case 2:
                printf("DEQUEUE CHOSEN\n");
                value = Q_DeQ(&q);
                if(value == -1)
                {
                    printf("Queue empty (Underflow)\n");
                }
                printf("Deleted value = %d\n", value);
                break;

        case 3:
                quit = 1;
                break;

        default :
                printf("Invalid operation, please choose between 1 2 and 3\n");

    }
}
    return 0;
}

void Q_Init(Q *qp)
{
    qp->front = 0;
    qp->rear  = 0;
}

void Q_EnQ(Q *qp, int element)
{
    if(qp->rear == SIZE)
    {
        printf("Q overflow\n");
        return;
    }

    qp->item[qp->rear] = element;   //Place element where rear is
    qp->rear = qp->rear + 1;                  //Move rear forward.
}

int Q_DeQ(Q *qp)
{
    if(qp->rear == qp->front)
    {
        return -1;
    }

    int element = qp->item[qp->front];      //Store whatever is in the front index in the item array
    qp->front = qp->front + 1;
    return element;
}

void print_menu()
{
    printf("-------------------FIFO QUEUE-------------------\n");
    printf("-------------------1. ENQUEUE-------------------\n");
    printf("-------------------2. DEQUEUE-------------------\n");
    printf("-------------------3. END    -------------------\n");
    printf("------------------------------------------------\n");

}
