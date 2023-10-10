CC=gcc
SWACHH=rm

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

add_matrix: add_matrix.o 
	$(CC) -o add_matrix add_matrix.o

mul_matrix: mul_matrix.o 
	$(CC) -o mul_matrix mul_matrix.o

swachh:
	$(SWACHH) -rf *.o add_matrix mul_matrix

all: add_matrix mul_matrix
