#include "shm_sem.h"

FILE *fptr = NULL;

#define printf(fmt, ...) fprintf(fptr, "[%s] [%s] [%s] [%d]", timestamp(), __FILE__, __func__, __LINE__), fprintf(fptr,fmt, ##__VA_ARGS__),fprintf(fptr,"\n")

int main()
{
	int start = 1;
	void *shm = NULL;
	struct sh_dat *sh_ptr;
	char buffer[TEXT_SZ];
	int shmid, semid;

    fptr = fopen("mylog.txt", "a+");

    if(fptr == NULL)
    {
        fprintf(stderr, "[%s] [%s] [%s] [%d] Unable to create the mylog.txt file\n", timestamp(), __FILE__, __func__, __LINE__);
        exit(EXIT_FAILURE);
    }

	shmid = shmget((key_t)1234, sizeof(struct sh_dat), 0666 | IPC_CREAT);
	if(shmid == -1)
	{
		printf("Shared memory creation failed");
        fclose(fptr);
		exit(EXIT_FAILURE);
	}
    sleep(1);
	printf("Shared Memory created");
	
	semid = semget((key_t)1235, 1, 0666 | IPC_CREAT);
	if(semid == -1)
	{
		printf("Semaphore creation failed");
        fclose(fptr);
		shmctl(shmid, IPC_RMID, NULL);
		exit(EXIT_FAILURE);
	}
    sleep(1);
	printf("Semaphore created");

	shm = shmat(shmid, (void *)0, 0);
	if(shm == (void *)-1)
	{
		printf("Shared memory attached failed");
        fclose(fptr);
		shmctl(shmid, IPC_RMID, NULL);
		semctl(semid, IPC_RMID, 0);
		exit(EXIT_FAILURE);
	}
    sleep(1);
	printf("Shared Memory Attached");
	sh_ptr = (struct sh_dat *)shm;
	while(start) 				/* entering the loop */
	{
		/* Waiting while server reads the data written by the client */
		if(semaphore_p(semid))	/* Check if server has written the data */
		{
            // Black[30], Red[31], Green[32], Yellow[33], Blue[34], Purple[35], Cyan[36], White[37]
            mycolor(genRandoms(30, 37));
			printf("Enter some text: ");
            colorreset();
			printf("Enter some text: ");
			fgets(buffer, TEXT_SZ, stdin);
		
			strncpy(sh_ptr->text, buffer, TEXT_SZ);
			printf("User has type the message: %s", buffer);
			semaphore_v(semid);	/* Giving the memory to the server for reading */
			sleep(1);
			if(strncmp(sh_ptr->text, "end",3) == 0)
			{
				start = 0;		/* Stopping the program */
			    printf("User has type the message: %s", sh_ptr->text);
			}
		}
	}
	if(shmdt(sh_ptr) == -1)
	{
		printf("Shared memory detached failed");
        fclose(fptr);
		shmctl(shmid, IPC_RMID, NULL);
		semctl(semid, IPC_RMID, 0);
		exit(EXIT_FAILURE);
	}
	printf("Shared Memory Detached");
    fclose(fptr);
	shmctl(shmid, IPC_RMID, NULL);
	semctl(semid, IPC_RMID, 0);
	exit(EXIT_SUCCESS);
}

