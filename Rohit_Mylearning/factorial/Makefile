CC=gcc
SWACHH=rm

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

factorial: factorial.o fact.o
	$(CC) -o factorial factorial.o fact.o

swachh:
	$(SWACHH) -rf *.o factorial

all: factorial
