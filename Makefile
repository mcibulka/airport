CC          =	gcc
# Flags that are sent to the compiler

CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude


all: Tester Simulator

Tester:
	$(CC) $(CFLAGS) src/ListImplementation.c src/QueueImplementation.c src/Testing.c -o bin/Tester -Iinclude

Simulator: 
	$(CC) $(CFLAGS) src/ListImplementation.c src/QueueImplementation.c src/Simulation.c -o bin/Simulation -Iinclude

clean:
	rm bin/*