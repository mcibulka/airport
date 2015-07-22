/**********************************************************************
*
*  FILE NAME: List.h
*
*  AUTHOR: Matthew Cibulka (0664008)
*
*  CREATED: October 3, 2012
*  LAST UPDATED: October 5, 2012
*
*  LIMITATIONS: 
*       - list structure is capable of storing integers only
*
***********************************************************************/

#include <stdlib.h>

typedef struct listNode 
{
	int nodeValue; 
	struct listNode *next;	
} node;

typedef struct ListADT
{
    node *head;
    node *tail;
    int length;
} List;

List* createList ();
node* initNode (int);
node* addFront (List *, int);
node* addBack (List *, int);
int getFrontVal (List *);
int getBackVal (List *);
node* removeFront (List *);
void printList (node *);
void destroyList (List *);
