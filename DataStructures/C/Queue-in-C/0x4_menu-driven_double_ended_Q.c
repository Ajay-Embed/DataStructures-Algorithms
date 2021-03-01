

/*
  * @file    - 0x4_basic_double_ended_Q.c
  * @author  - Ajay
  * @date    - 30/10/2020
  * @brief   - Algorithm and implementation for a double ended queue

--------------------------------------------------------------------------------------------------------
DOUBLE ENDED QUEUE

EXAMPLE THAT SHOWCASES THE CONCEPT OF A DOUBLE ENDED QUEUE.

By a DEQ, I mean, you can use both the front and rear indexes to insert as well as delelte a element.

---------------------------------------------------------------------------------------------------------

Here is a pseudocode for the same idea.

Initial conditions ---  FRONT == 0 & REAR == -1

(procedure 1)
INSERT_AT_REAR(ELEMENT_TO_BE_INSTERTED)
    IF REAR == SIZE-1       //checking overflow, cannot insert
        CANNOT INSERT ELEMENT
        EXIT!
    END IF

    REAR = REAR + 1         //move rear to index zero by incrementing by 1
    ITEAM[REAR] = ELEMENT   //insert the element
END OF INSERT_AT_REAR(ELEMENT_TO_BE_INSTERTED)


(procedure 2)
DELETE_FROM_REAR()
    IF FRONT > REAR
        QUEUE UNDERFLOW         //notice this was our initial condition
        exit!
    END IF

    ELEMENT = ITEM[REAR]
    REAR = REAR - 1         //decrement by 1 coz we deleted
    RETURN ELEMENT
END OF DELETE_FROM_REAR()


(procedure 3)
INSERT_AT_FRONT(ELEMENT_TO_BE_INSERTED)
    IF FRONT IS AT INDEX ZERO
        UNABLE TO INSERT AT FRONT
        EXIT
    END IF

    FRONT = FRONT-1
    ITEM[FRONT] = ELEMENT_TO_BE_INSERTED
END OF INSERT_AT_FRONT(ELEMENT_TO_BE_INSERTED)


(procedure 4)
DELETE_FROM_FRONT()
    IF FRONT > REAR
        UNABLE TO DELETE FROM FRONT
        EXIT
    END IF

    ELEMENT = ITEM[FRONT]
    FRONT = FRONT + 1;
END OF DELETE_FROM_FRONT()

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
void Insert_AT_REAR(Q *qptr, uint8_t element);
void Insert_AT_FRONT(Q *qptr, uint8_t element);
uint8_t Delete_from_FRONT(Q *qptr);
uint8_t Delete_from_REAR(Q *qptr);


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
            /*


            The cases have been left to the user as an exercise, keep 0x3 or 0x2 program as a reference
            while implementing the switch cases.


            */
            default:
                printf("please choose a option from the menu\n");
                break;

        }

    }

return 0;
}


void Q_init(Q *qptr)
{
    qptr->rear  = -1;
    qptr->front =  0;
}

void Insert_AT_REAR(Q *qptr, uint8_t element)
{
    //check for overflow
    if(qptr->rear == SIZE-1)
    {
        printf("Unable to insert at rear\n");
        return;
    }

    //Add the element in the Q
    qptr->rear++;
    qptr->item[qptr->rear] = element;
}

uint8_t Delete_from_REAR(Q *qptr)
{
    //Check for underflow condition
    if(qptr->front > qptr->rear)
    {
        printf("Q underflow\n");
        return -1;
    }
    uint8_t element = qptr->item[qptr->rear];
    qptr->rear--

return element;
}

void Insert_AT_FRONT(Q *qptr, uint8_t element)
{
    //check for overflow
    if(qptr->front == 0)
    {
        printf("unable to insert at front\n");
        return;
    }
    qptr->front--;
    qptr->item[qptr->front] = element;
}

uint8_t Delete_from_FRONT(Q *qptr)
{
    //Check for underflow condition
    if(qptr->front > qptr->rear)
    {
        printf("Q underflow\n");
        return -1;
    }

    uint8_t element = qptr->item[qptr->front];
    qptr->front = (qptr->front + 1);

return element;
}

void PRINT_menu(void)
{
    printf("----------------CIRCULAR FIFO-------------------\n");
    printf("-------------SELECT YOUR CHOICE-----------------\n");
    printf("----------PRESS 1 TO EN-Q FROM REAR-------------\n");
    printf("----------PRESS 2 TO EN-Q FROM FRONT------------\n");
    printf("----------PRESS 3 TO DE-Q FROM REAR-------------\n");
    printf("----------PRESS 4 TO DE-Q FROM FRONT -----------\n");
    printf("--------------PRESS 5 TO QUIT-------------------\n");
}
