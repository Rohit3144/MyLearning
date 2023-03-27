CC=gcc
CLEAN=rm

%.o: %.c 
	$(CC) -c -o $@ $< 

fun_pointer: fun_pointer.o
	$(CC) -o fun_pointer fun_pointer.o

pointer_explorer: pointer_explorer.o
	$(CC) -o pointer_explorer pointer_explorer.o

clean:
	$(CLEAN) -rf *.o fun_pointer pointer_explorer

all: fun_pointer pointer_explorer
