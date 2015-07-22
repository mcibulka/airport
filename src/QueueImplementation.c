/***************************************************************************
*
*  FILE NAME: QueueImplementation.c
*
*  AUTHOR: Matthew Cibulka (0664008)
*
*  CREATED: October 3, 2012
*  LAST UPDATED: October 5, 2012
*
*  LIMITATIONS:
*       - assumes valid data is passed in
*
****************************************************************************/

#include "Queue.h"
#include <stdio.h>

/* Allocate memory for and initialize Queue */
Queue* createQueue ()
{
    Queue *newQueue = NULL;
    newQueue = malloc( sizeof(Queue) * 1);
    
    if (newQueue != NULL)
    {
        newQueue->myList = createList();
        newQueue->queueLength = 0;
    }
    else
    {
        fprintf(stderr, "\nUnable to allocate memory for newQueue; program exiting.\n\n");
        exit(EXIT_FAILURE); 
    }
    
    return (newQueue);
}

/* Add an element to the end of the queue */
void enqueue (Queue *Q, int a)
{
    Q->myList->head = addBack( Q->myList, a );
    Q->queueLength = Q->myList->length;
}

/* Remove the first element in the queue */
node* dequeue (Queue *Q)
{
    node *front = removeFront(Q->myList);
    Q->queueLength = Q->myList->length;
    
    return (front);
}

/* Get the length of the queue */
int getLength (Queue *Q)
{
    return (Q->queueLength);
}

/* Determines whether the queue is empty or not */
int isEmpty (Queue *Q)
{
    if (Q->queueLength == 0)
    {
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

/* Display elements in the queue */
void printQueue (Queue *Q)
{
    if (isEmpty(Q) == TRUE)
    {
        printf("The queue is empty.\n\n");
    }
    else
    {
        printf("Printing the queue; starting at the front.\n");
  
        printList(Q->myList->head);
    }
}

/* Return any memory allocated for the Queue to the system */
void destroyQueue (Queue *Q)
{
    destroyList(Q->myList);
    Q->queueLength = 0;
    free(Q);
}
