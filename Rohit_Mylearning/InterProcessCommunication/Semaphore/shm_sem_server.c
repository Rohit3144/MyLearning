//#include <time.h>
#include "shm_sem.h"

int semaphore_p(int sem_id);
int semaphore_v(int sem_id);
FILE *fptr = NULL;
/*char * timestamp()
{
    time_t ltime; // calendar time 
    ltime = time(NULL); // get current cal time 

    char * curr_local_time = asctime(localtime(&ltime));
    curr_local_time[strlen(curr_local_time) - 1] = '\0'; // removed \n
    return curr_local_time;
}*/

int main()
{
    int start = 1;
    void *shm = NULL;
    struct sh_dat *sh_ptr;
    int shmid, semid;

    fptr = fopen("mylog.txt", "a+");

    /* Creating the semaphore and shared memory */
    shmid = shmget((key_t)1234, sizeof(struct sh_dat), 0666 | IPC_CREAT);
    if(shmid == -1)
    {
        fprintf(fptr, "[%s] [%s] [%s] [%d]shmget failed\n", timestamp(), __FILE__, __func__, __LINE__);
        exit(EXIT_FAILURE);
    }
    semid = semget((key_t)1235, 1, 0666 | IPC_CREAT);
    if(semid == -1)
    {
        fprintf(fptr, "[%s] [%s] [%s] [%d]semget failed\n", timestamp(), __FILE__, __func__, __LINE__);
        shmctl(shmid, IPC_RMID, NULL);
        exit(EXIT_FAILURE);
    }
    /* Initially making the semaphore available */
    if(semctl(semid, 0, SETVAL, 1) == -1)
    {
        fprintf(fptr, "[%s] [%s] [%s] [%d]semctl(SETVAL) failed\n", timestamp(), __FILE__, __func__, __LINE__);
        shmctl(shmid, IPC_RMID, 0);
        semctl(semid, IPC_RMID, 0);
        exit(EXIT_FAILURE);
    }
    /* Attaching the shared memory to server process */
    shm = shmat(shmid, (void *)0, 0);
    if(shm == (void *)-1)
    {
        fprintf(fptr, "[%s] [%s] [%s] [%d] shmat failed\n", timestamp(), __FILE__, __func__, __LINE__);
        exit(EXIT_FAILURE);
    }
    sh_ptr = (struct sh_dat *)shm;
    while(start) 				/* entering the loop */
    {
        sleep(2);
        if(semaphore_p(semid))	/* Check if client has written the data */
        {
            fprintf(fptr, "[%s] [%s] [%s] [%d] Server reading\n", timestamp(), __FILE__, __func__, __LINE__);
            printf("You wrote: %s", sh_ptr->text);
            semaphore_v(semid);	/* Giving it to client after reading the data */
            if(strncmp(sh_ptr->text, "end",3) == 0)
            {
                start = 0;		/* Stopping the program */
            }
        }
    }
    /* Detaching the shared memory */
    if(shmdt(sh_ptr) == -1)
    {
        fprintf(fptr, "[%s] [%s] [%s] [%d]shmdt failed\n", timestamp(), __FILE__, __func__, __LINE__);
        exit(EXIT_FAILURE);
    }
    if(shmctl(shmid, IPC_RMID, 0) == -1)
    {
        fprintf(fptr, "[%s] [%s] [%s] [%d]shmctl(IPC_RMID) failed\n", timestamp(), __FILE__, __func__, __LINE__);
        exit(EXIT_FAILURE);
    }
    if(semctl(semid, IPC_RMID, 0) == -1)
    {
        fprintf(fptr, "[%s] [%s] [%s] [%d]semctl(IPC_RMID) failed\n", timestamp(), __FILE__, __func__, __LINE__);
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
	
int semaphore_p(int sem_id)
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;
    sem_b.sem_flg = SEM_UNDO;
    if(semop(sem_id, &sem_b, 1) == -1)
    {
        fprintf(fptr, "[%s] [%s] [%s] [%d]semaphore_p failed \n", timestamp(), __FILE__, __func__, __LINE__);
        return 0;
    }
    return 1;
}

int semaphore_v(int sem_id)
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;
    sem_b.sem_flg = SEM_UNDO;
    if(semop(sem_id, &sem_b, 1) == -1)
    {
        fprintf(fptr, "[%s] [%s] [%s] [%d]semaphore_v failed \n", timestamp(), __FILE__, __func__, __LINE__);
        return 0;
    }
    return 1;
}
