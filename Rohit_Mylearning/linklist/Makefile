CC=gcc
CLEAN=rm

%.o: %.c 
	$(CC) -c -o $@ $< 

linklist_insertion: linklist_insertion.o
	$(CC) -o linklist_insertion linklist_insertion.o

single_linklist: single_linklist.o
	$(CC) -o single_linklist single_linklist.o

new_linklist: new_linklist.o
	$(CC) -o new_linklist new_linklist.o

switchcase_linklist: switchcase_linklist.o
	$(CC) -o switchcase_linklist switchcase_linklist.o

clean:
	$(CLEAN) -rf *.o linklist_insertion switchcase_linklist new_linklist single_linklist

all: linklist_insertion single_linklist new_linklist switchcase_linklist
