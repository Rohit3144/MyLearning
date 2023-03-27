CC=gcc
CLEAN=rm

%.o: %.c 
	$(CC) -c -o $@ $< 

double_array: double_array.o
	$(CC) -o double_array double_array.o

clean:
	$(CLEAN) -rf *.o double_array
