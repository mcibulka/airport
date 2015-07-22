/***************************************************************************
*
*  FILE NAME: Simulation.c
*
*  AUTHOR: Matthew Cibulka (0664008)
*
*  CREATED: October 3, 2012
*  LAST UPDATED: October 5, 2012
*
*  LIMITATIONS:
*   
****************************************************************************/

#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{	
    Queue *queueOne = NULL, *queueTwo = NULL;
    node *persOne = NULL, *persTwo = NULL, *persThree, *firstPersOut = NULL;
    int i;
    int stationOne = 0, stationTwo = 0, stationThree = 0;
    int totTime = 0;
  
    printf("\nAirport Security Checkpoint Simulator\n");
    printf("=====================================\n\n");

    queueOne = createQueue();
    queueTwo = createQueue();
    
    srand( (unsigned)time(NULL) );
    
    /*  Assign random values to each person in the queue, between 60 and 180 seconds  */
    for (i = 0 ; i < 1000 ; i++)
    {
        int num = 0;
        
        num = rand()%(180-60) + 60;
        enqueue(queueOne, num);
    }
    
    printf("Number of people in line: %d\n", getLength(queueOne));
    
    persOne = dequeue(queueOne); 
    stationOne = persOne->nodeValue;
    enqueue(queueTwo, persOne->nodeValue);

    persTwo = dequeue(queueOne);
    stationTwo = persTwo->nodeValue;
    enqueue(queueTwo, persTwo->nodeValue);
    
    while (getLength(queueOne) != 0)
    {
        stationOne--;
        stationTwo--;
        
        if (stationOne == 0)
        {
            firstPersOut = persOne;
            persOne = dequeue(queueOne);
            stationOne = persOne->nodeValue;
            
            enqueue(queueTwo, firstPersOut->nodeValue);
        }
        else if (stationTwo == 0)
        {
            firstPersOut = persTwo;
            persTwo = dequeue(queueOne);
            stationTwo = persTwo->nodeValue;
            
            enqueue(queueTwo, firstPersOut->nodeValue);
        }      
        
        totTime++;
    }
    
    destroyQueue(queueOne);
    
    printf("Total Time for Two Stations: %.2f virtual minutes\n", (totTime/60.0));
    
    
    /* Test with 3 stations */
    totTime = 0;
    persOne = dequeue(queueTwo); 
    stationOne = persOne->nodeValue;

    persTwo = dequeue(queueTwo);
    stationTwo = persTwo->nodeValue;
    
    persThree = dequeue(queueTwo);
    stationThree = persThree->nodeValue;
    
    while (getLength(queueTwo) != 0)
    {
        stationOne--;
        stationTwo--;
        stationThree--;
        
        if (stationOne == 0)
        {
            firstPersOut = persOne;
            persOne = dequeue(queueTwo);
            stationOne = persOne->nodeValue;
        }
        else if (stationTwo == 0)
        {
            firstPersOut = persTwo;
            persTwo = dequeue(queueTwo);
            stationTwo = persTwo->nodeValue;
        }    
        else if (stationThree == 0)
        {
            firstPersOut = persThree;
            persThree = dequeue(queueTwo);
            stationThree = persThree->nodeValue;
        }   
        
        totTime++;
    }
    
    printf("Total Time for three Stations: %.2f virtual minutes\n", (totTime/60.0));
    destroyQueue(queueTwo);
    
    return (EXIT_SUCCESS);
}
