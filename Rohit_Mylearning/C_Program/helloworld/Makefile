CC=gcc
SWACHH=rm

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.o hellofunc.o 
	$(CC) -o hellomake hellomake.o hellofunc.o

swachh:
	$(SWACHH) -rf *.o hellomake

all: hellomake 
