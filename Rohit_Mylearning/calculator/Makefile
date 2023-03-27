CC=gcc
SWACHH=rm
#GDB=-g

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

calculator: calculator.o sum.o sub.o multi.o div.o
	$(CC) -g -o calculator calculator.o sum.o sub.o multi.o div.o
swachh:
	$(SWACHH) -rf *.o calculator

all: calculator
