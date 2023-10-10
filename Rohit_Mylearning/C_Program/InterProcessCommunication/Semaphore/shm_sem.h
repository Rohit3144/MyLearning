#ifndef _SHM_H_
#define _SHM_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <time.h>

#define TEXT_SZ 32

struct sh_dat
{
	char text[TEXT_SZ];
};

char * timestamp()
{
    time_t ltime; // calendar time
    ltime = time(NULL); // get current cal time
    char * curr_local_time = asctime(localtime(&ltime));
    curr_local_time[strlen(curr_local_time) - 1] = '\0'; // removed \n
    return curr_local_time;
 }
#endif
