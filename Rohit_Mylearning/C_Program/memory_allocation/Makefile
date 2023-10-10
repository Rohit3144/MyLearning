CC=gcc
CLEAN=rm

%.o: %.c 
	$(CC) -c -o $@ $< 

memory_allocation: memory_allocationt.o
	$(CC) -o memory_allocation memory_allocation.o

memory_layout: memory_layout.o
	$(CC) -o memory_layout memory_layout.o

volatile_with_optimization: volatile_with_optimization.o
	$(CC) -o volatile_with_optimization volatile_with_optimization.o

volatile_without_optimization: volatile_without_optimization.o
	$(CC) -o volatile_without_optimization volatile_without_optimization.o

clean:
	$(CLEAN) -rf *.o memory_layout memory_allocation volatile_with_optimization volatile_without_optimization

all: memory allocation memory_layout volatile_with_optimization volatile_without_optimization
