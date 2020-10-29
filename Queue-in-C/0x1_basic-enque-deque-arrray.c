
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
        printf("Queue empty\n");
        return -1;
    }

    int element = qp->item[qp->front];      //Store whatever is in the front index in the item array
    qp->front = qp->front + 1;
    return element;
}

int main(void)
{
    Q q;
    Q_Init(&q);

    Q_EnQ(&q, 10);
    Q_EnQ(&q, 20);
    Q_EnQ(&q, 30);
    Q_EnQ(&q, 40);
    Q_EnQ(&q, 50);

    printf("first deque %d\n", Q_DeQ(&q));
    printf("second deque %d\n", Q_DeQ(&q));
    printf("third deque %d\n", Q_DeQ(&q));
    printf("fourth deque %d\n", Q_DeQ(&q));
    printf("fifth deque %d\n", Q_DeQ(&q));
    printf("sixth deque %d\n", Q_DeQ(&q));


    return 0;
}


