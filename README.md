# List / Queue
## Overview
This is a basic implementation of a Queue Abstract Data Type (ADT) written in C.  The queue is implemented using a Linked List ADT.  For simplicity, each element within the queue holds a single integer value.
### Tester
The Tester program creates a queue containing 11 elements.  It prints out the elements to the terminal, and then frees all of the memory allocated.
### Simulation
The Simulator program simulates people passing through airport security.  There is a single line of people passing through 2 security stations.  Each person takes between 1 and 3 virtual minutes to pass through a station.  After each person passes through, they line up in a second queue, waiting to pass through a second checkpoint.  For the second checkpoint, there are 3 security stations.  The process is repeated.  At the end, the total simulated time to process the people through each checkpoint is printed out to the terminal.
## To Run
Open Terminal and enter:
````
$ make
$ ./bin Tester
$ ./bin Simulation
```
There is sample program output in `\docs` for each program.
