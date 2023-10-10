#include "shm_sem.h"

FILE *fptr = NULL;

//#define print_log(fmt, ...) fprintf(fptr, "[%s] [%s] [%s] [%d]", timestamp(), __FILE__,__func__,__LINE__ ), fprintf(fptr, fmt, ##__VA_ARGS__), fprintf(fptr, "\n")

int main()
{
	int start = 1;
	void *shm = NULL;
	struct sh_dat *sh_ptr;
	int shmid, semid;

	/* Creating the semaphore and shared memory */
	shmid = shmget((key_t)1234, sizeof(struct sh_dat), 0666 | IPC_CREAT);
	if(shmid == -1)
	{
		print_log("Shared memory creation failed");
		exit(EXIT_FAILURE);
	}
	semid = semget((key_t)1235, 1, 0666 | IPC_CREAT);
	if(semid == -1)
	{
		print_log("Semaphore creation failed");
		//shmctl(shmid, IPC_RMID, NULL);
		exit(EXIT_FAILURE);
	}

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
	
	/* Attaching the shared memory to server process */
	shm = shmat(shmid, (void *)0, 0);
	if(shm == (void *)-1)
	{
		print_log("Shared memory attached failed");
		//shmctl(shmid, IPC_RMID, 0);
		//semctl(semid, IPC_RMID, 0);
		exit(EXIT_FAILURE);
	}
    print_log("Shared memory attached");
	sh_ptr = (struct sh_dat *)shm;
	while(start) 				/* entering the loop */
	{
		sleep(2);
		if(semaphore_p(semid))	/* Check if client has written the data */
		{
            // Black[30], Red[31], Green[32], Yellow[33], Blue[34], Purple[35], Cyan[36], White[37]
            mycolor(genRandoms(30, 37));
			printf("You wrote: %s\n", sh_ptr->text);
            colorreset();
            print_log("Message received from client: %s", sh_ptr -> text);
			semaphore_v(semid);	/* Giving it to client after reading the data */
			if(strncmp(sh_ptr->text, "end",3) == 0)
			{
				start = 0;		/* Stopping the program */
                print_log("Message received from client: %s", sh_ptr -> text);
			}
		}
	}

	/* Detaching the shared memory */
	if(shmdt(sh_ptr) == -1)
	{
		print_log("Shared memory detached failed");
		//shmctl(shmid, IPC_RMID, 0);
		//semctl(semid, IPC_RMID, 0);
		exit(EXIT_FAILURE);
	}
	if(shmctl(shmid, IPC_RMID, 0) == -1)
	{
		print_log("shmctl(IPC_RMID) failed");
		//shmctl(shmid, IPC_RMID, 0);
		//semctl(semid, IPC_RMID, 0);
		exit(EXIT_FAILURE);
	}
	if(semctl(semid, IPC_RMID, 0) == -1)
	{
		print_log("semctl(IPC_RMID) failed");
		//shmctl(shmid, IPC_RMID, 0);
		//semctl(semid, IPC_RMID, 0);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
