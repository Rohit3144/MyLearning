#include "shm_sem.h"

FILE *fptr = NULL;

//#define print_log(fmt, ...) fprintf(fptr, "[%s] [%s] [%s] [%d]", timestamp(), __FILE__, __func__, __LINE__), fprintf(fptr,fmt, ##__VA_ARGS__),fprintf(fptr,"\n")

int main()
{
	int start = 1;
	void *shm = NULL;
	struct sh_dat *sh_ptr;
	char buffer[TEXT_SZ];
	int shmid, semid;

    /*if(fptr == NULL)
    {
        fprintf(stderr, "[%s] [%s] [%s] [%d] Unable to create the mylog.txt file\n", timestamp(), __FILE__, __func__, __LINE__);
        exit(EXIT_FAILURE);
    }*/

	shmid = shmget((key_t)1234, sizeof(struct sh_dat), 0666 | IPC_CREAT);
	if(shmid == -1)
	{
		print_log("Shared memory creation failed");
		exit(EXIT_FAILURE);
	}
    sleep(1);
	print_log("Shared Memory created");
	
	semid = semget((key_t)1235, 1, 0666 | IPC_CREAT);
	if(semid == -1)
	{
		print_log("Semaphore creation failed");
		//shmctl(shmid, IPC_RMID, NULL);
		exit(EXIT_FAILURE);
	}
    sleep(1);
	print_log("Semaphore created");

    if(semctl(semid, 0, GETVAL, 1) == 0)    //Semaphore value not set
    {
	    /* Initially making the semaphore available */
    	if(semctl(semid, 0, SETVAL, 1) == -1)
	    {
		    print_log("semctl(SETVAL) failed");
    		//shmctl(shmid, IPC_RMID, 0);
	    	//semctl(semid, IPC_RMID, 0);
		    exit(EXIT_FAILURE);
	    }
        print_log("Semaphore SETVAL succeed");
    }
	
	shm = shmat(shmid, (void *)0, 0);
	if(shm == (void *)-1)
	{
		print_log("Shared memory attached failed");
		//shmctl(shmid, IPC_RMID, NULL);
		//semctl(semid, IPC_RMID, 0);
		exit(EXIT_FAILURE);
	}
    sleep(1);
	print_log("Shared Memory Attached");
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
			fgets(buffer, TEXT_SZ, stdin);
            //buffer[strlen(buffer-1)] = '\0';
            buffer[strlen(buffer) - 1] = '\0';
		
			strncpy(sh_ptr->text, buffer, TEXT_SZ);
			print_log("User has type the message: %s", buffer);
			semaphore_v(semid);	/* Giving the memory to the server for reading */
			sleep(1);
			if(strncmp(sh_ptr->text, "end",3) == 0)
			{
				start = 0;		/* Stopping the program */
			    print_log("User has type the message: %s", sh_ptr->text);
			}
		}
	}
	if(shmdt(sh_ptr) == -1)
	{
		print_log("Shared memory detached failed");
		//shmctl(shmid, IPC_RMID, NULL);
		//semctl(semid, IPC_RMID, 0);
		exit(EXIT_FAILURE);
	}
	print_log("Shared Memory Detached");
	shmctl(shmid, IPC_RMID, NULL);
	semctl(semid, IPC_RMID, 0);
	exit(EXIT_SUCCESS);
}

