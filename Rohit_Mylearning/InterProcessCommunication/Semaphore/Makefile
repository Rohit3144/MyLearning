CC=gcc
CLEAN=rm

%.o: %.c
	$(CC) -c -o $@ $<

shm_sem_client: shm_sem_client.o
	$(CC) -o shm_sem_client shm_sem_client.o

shm_sem_server: shm_sem_server.o
	$(CC) -o shm_sem_server shm_sem_server.o

clean:
	$(CLEAN) -rf *.o shm_sem_client shm_sem_server

all: shm_sem_client shm_sem_server
