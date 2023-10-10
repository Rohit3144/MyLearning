#include <stdio.h>
#include <time.h>
#include <string.h>

char * timestamp()
{
    time_t now = time(NULL);
    char * time = asctime(gmtime(&now));
    time[strlen(time)-1] = '\0';    // Remove \n
    return time;
}


int main()
{
  
    struct tm* local;
    //volatile time_t t = time(NULL);    //Time will not change in this case

    while(1)
    {
    volatile time_t t = time(NULL);     //By enabling it time will change
    
    // Get the localtime
    local = localtime(&t);

        printf("Timestamp .........Local time and date: %s\n", asctime(local));
        //printf("Timestamp .........Local time and date: %s\n", timestamp());
    }
    return 0;
}
