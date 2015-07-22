/**********************************************************************
*
*  FILE NAME: Queue.h
*
*  AUTHOR: Matthew Cibulka (0664008)
*
*  CREATED: October 3, 2012
*  LAST UPDATED: October 5, 2012
*
*  LIMITATIONS: 
*       - queue allows only integers to be stored
*
***********************************************************************/

#include "List.h"

#define TRUE 1
#define FALSE 0

typedef struct QueueADT
{
    List *myList;
    int queueLength;
} Queue;

Queue* createQueue ();
void enqueue (Queue *, int);
node* dequeue (Queue *);
int getLength (Queue *);
int isEmpty (Queue *);
void printQueue (Queue *);
void destroyQueue (Queue *);
