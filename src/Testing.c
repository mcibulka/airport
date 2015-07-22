/***************************************************************************
*
*  FILE NAME: Testing.c
*
*  AUTHOR: Matthew Cibulka (0664008)
*
*  CREATED: October 3, 2012
*  LAST UPDATED: October 5, 2012
*
*  LIMITATIONS: October 5, 2012
*
****************************************************************************/

#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

void myTest ();
void test_var_len (int);

int main (void)
{  
    printf("\n\tQueue Tester Program\n");
    printf("\t====================\n\n");
    
    myTest();
    
    return (EXIT_SUCCESS);
}

/* Initiates all test suites */
void myTest ()
{
    printf("Length Test Suite\n");
    printf("-----------------\n\n");
    test_var_len(0);
    test_var_len(1);
    /*test_var_len(100);*/
    /*test_var_len(10000);*/
    /*test_var_len(100000);*/
    /*test_var_len(1000000);*/
}

/* Variable length test: len controls the multiplier for the total list size; factor of 11 (size of test array) */
void test_var_len (int len)
{
    int testArray[11] = {-25671, -8763, -556, -34, -2, 0, 2, 34, 556, 8763, 25671};
    Queue *myQueue;
    node *front;
    int i, j, totLen = 0;
    
    totLen = len * 11;
    printf("## Testing length of %d nodes.\n\n", totLen);
    
    myQueue = createQueue();
    
    if (totLen == 0)
    {
        printf("Attempt to print an empty queue...\n");
        printQueue(myQueue);
    }
    else
    {
        printf("Adding elements to the queue...\n");
        
        for (j = 0 ; j < len ; j++)
        {
            for (i = 0 ; i < 11 ; i++)
            {
                enqueue(myQueue, testArray[i]);
            }
        }
        
        printQueue(myQueue);
        printf("Queue Length: %d\n", getLength(myQueue));
        
        printf("\nRemoving elements from the queue.\n");
        for (i = 0 ; i < totLen ; i++)
        {
            front = dequeue(myQueue);  
            free(front);
        }
        
        printf("\nQueue Length: %d\n", getLength(myQueue));
    }

    destroyQueue(myQueue);
}
