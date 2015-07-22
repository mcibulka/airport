/***************************************************************************
*
*  FILE NAME: ListImplementation.c
*
*  AUTHOR: Matthew Cibulka (0664008)
*
*  CREATED: October 3, 2012
*  LAST UPDATED: October 5, 2012
*
*  LIMITATIONS:
*       - functions assume valid data is passed in
*
****************************************************************************/

#include "List.h"
#include <stdio.h>

/* Allocate memory for and initialize List */
List* createList ()
{
    List *newList = NULL;
    newList = malloc( sizeof(List) * 1);
    
    if (newList != NULL)
    {
        newList->head = NULL;
        newList->tail = NULL;
        newList->length = 0;
    }
    else
    {
        fprintf(stderr, "\nUnable to allocate memory for newList; program exiting.\n\n");
        exit(EXIT_FAILURE);     
    }
   
    return (newList);
}

/* Allocate memory for a new node and assign integer value within */
node* initNode (int a)
{
    node *newNode = NULL;
	newNode = malloc( sizeof(node) * 1 );
    
    if (newNode != NULL)
    {
        newNode->nodeValue = a;
        newNode->next = NULL;
    }
    else
    {
        fprintf(stderr, "\nUnable to allocate memory for newNode; program exiting.\n\n");
        exit(EXIT_FAILURE);
    }

    return (newNode);
}

/* Initialize a new node and add it to the front of the List */
node *addFront (List *L, int a)
{
    node *newHead = NULL;
    node *oldHead = L->head;
	newHead = initNode(a);
   
    newHead->next = oldHead;
    L->head = newHead;
    
    if (L->tail == NULL)
    {
        L->tail = newHead;
    }
    
    L->length++;
    
    return (newHead);
}

/* Initialize a new node and add it to the end of the list */
node *addBack (List *L, int a)
{
    node *newTail = NULL;
    node *oldTail = L->tail;
    newTail = initNode(a); 
    
    if (L->tail == NULL)
    {
        L->tail = newTail;
    }
    else
    {
        oldTail->next = newTail;
        L->tail = newTail;
    }

    if (L->head == NULL)
    {
        L->head = newTail;
    }
    
    L->length++;
    
    return (L->head);
}

/* Returns the integer value of the head node */
int getFrontVal (List *L)
{
    return (L->head->nodeValue);     /* pass the dummy head */
}

/* Returns the integer value of the tail node */
int getBackVal (List *L)
{
    return (L->tail->nodeValue);
}

/* Removes the front element of the list and returns its value */
node* removeFront (List *L)
{ 
    node *tempPtr = L->head; 
    
    /*printf("Removed element.\tValue: %d\n", tempPtr->nodeValue);*/
    
    L->head = L->head->next;
    L->length--;
    
    return (tempPtr);
}

/* Starting at the head of the list and cycling through to the end,
   print each value of the node */
void printList (node *head)
{
    node *currPos = head;
    
    while (currPos != NULL)
    {
        printf ("Element Value: %d\n", currPos->nodeValue );
        currPos = currPos->next;
    }
    
    printf("\n");
}
 
/* Return any memory allocated for the List to the system */
void destroyList (List *L)
{
    node *currPos = L->head;
    
    if (currPos != NULL)    /* check to see if the list is empty */
    {
        while (currPos->next != NULL)
        {
            currPos = removeFront(L);
                
            currPos->nodeValue = 0;
            free(currPos);
        }
    }

    free(L);
    printf("\n");
}
