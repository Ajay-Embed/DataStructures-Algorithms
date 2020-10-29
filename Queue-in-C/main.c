/*
The idea here is the implementation of a circular FIFO queue.
The reason being, both the programs (0x1 and 0x2) that were not using circular FIFO, were facing serious problems.

- We were not able to utilise the emptied out portions in the queue even after dequeueing, and also, at some point the queue turned out to be
overflow and underflow at the same time, weird.

This is solved by using a circular queue..

Look at this equation

REAR  = (( REAR  +1 )  % SIZE)
FRONT = (( FRONT +1 )  % SIZE)

Imagine an array of size 5, with 5 elements in it. Now let's assume REAR & FRONT point at index zero.
    We want to increment REAR, after adding an element to the queue, let's use the above metioned equation.
    REAR  = (( REAR  +1 )  % SIZE)
    we get ((0 +1) % 5) == 1
    (repeat this till REAR == 3, i.e for 4 elements)

    Now, when REAR is equal to 4. That is, the fifth element, (((4+1) % 5) == 0 )
    Notice 0.
    This means now the REAR is pointing back at the zeroth index. In a circular fashion.
    Same applies for FRONT.

NOTE - the only concrete idea that we have to keep in mind is in this method, the rear & front will start at SIZE-1 (i.e the last index) - You should know why. If not
I urge you to dry run the algorithm on a notebook and check.

 -----------------------------------------------------------------------------------------------------------------------------------------------------------------
 [ALTERNATIVE] (Less CPU clock exhaustive)

    if(REAR == (SIZE -1))
    {
        REAR = 0;
    }
    else
    {
        REAR++;
    }
*/

#include <stdio.h>
#include <stdint.h>

#define SIZE 100

//Type for our queue
typedef struct{
    uint8_t item[SIZE];
    uint8_t rear, front;
}Q;

void PRINT_menu(void);
void Q_init(Q *);
void En_Q(Q *, uint8_t);
uint8_t De_Q(Q *);


int main(void)
{
    uint8_t quit=0, number=0;
    Q qptr;
    //We'll develop a menu driven format for EnQ-ing and DeQ-ing in our Circular FIFO

    Q_init(&qptr);

    PRINT_menu();

    while(!quit)
    {
        printf("Enter your choice\n");

        int choice=0, value=0;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("You have chose to EN-Q, please enter the number you'd like to put in Q\n");
                scanf("%u", &number);
                En_Q(&qptr, number);
                break;

            case 2:
                value = De_Q(&qptr);
                if(value == -1)
                {
                    printf("Q underflow");
                }

                printf("You have chose to DE-Q, here is the element = %d\n", De_Q(&qptr));
                break;

            case 3:
                quit = 1;
                break;

            default:
                printf("please choose a option from the menu\n");
                break;

        }

    }

return 0;
}


void Q_init(Q *qptr)
{
    qptr->rear  = SIZE-1;
    qptr->front = SIZE-1;
}

void En_Q(Q *qptr, uint8_t element)
{
    //check for overflow
    if( ( (qptr->rear + 1) % SIZE) == qptr->front)
    {
        printf("Q overflow\n");
        return;
    }

    //Add the element in the Q
    qptr->rear = ((qptr->rear + 1) % SIZE);
    qptr->item[qptr->rear] = element;
}

uint8_t De_Q(Q *qptr)
{
    //Check for underflow condition
    if(qptr->rear == qptr->front)
    {
        printf("Q underflow\n");
        return -1;
    }

    //Since it's not underflow, we can return the element we find on the front index while DeQ-ing
    qptr->front = (qptr->front + 1) % SIZE;
    uint8_t element = qptr->item[qptr->front];
return element;
}

void PRINT_menu(void)
{
    printf("----------------CIRCULAR FIFO-------------------\n");
    printf("-------------SELECT YOUR CHOICE-----------------\n");
    printf("--------------PRESS 1 FOR EN-Q------------------\n");
    printf("--------------PRESS 2 FOR DE-Q------------------\n");
    printf("--------------PRESS 3 TO QUIT ------------------\n");
}






































