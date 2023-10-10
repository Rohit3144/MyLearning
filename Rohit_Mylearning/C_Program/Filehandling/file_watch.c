#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

FILE *fd = NULL;

#define print_log(fmt, ...) printf("[%s] [%s] [%s] [%d] ", timestamp(), __FILE__, __func__, __LINE__), printf((fmt), ##__VA_ARGS__), printf("\n")

#define print_flog(fmt, ...) fprintf(fd, "[%s] [%s] [%s] [%d] ", timestamp(), __FILE__, __func__, __LINE__), fprintf(fd, (fmt), ##__VA_ARGS__), fprintf(fd, "\n")

char * timestamp()
{
    time_t ltime; // calendar time
    ltime = time(NULL); // get current cal time

    char * curr_local_time = asctime(localtime(&ltime));
    curr_local_time[strlen(curr_local_time) - 1] = '\0'; // removed \n
    return curr_local_time;
}

int main()
{
    //FILE *fd = NULL;
    //char buffer[100];
    char ch;
    int charcount = 0;
    
    fd = fopen("test.txt", "w+");
    
    while(ch = fgetc(fd) != EOF)
    {
        //if(ch == '')
            charcount ++;
    }
    print_log("Total number of characters are %d", charcount);


    while(1)
    {
        fseek(fd, 0, SEEK_END);
        print_log("Position of pointer before setting pointer: %ld",ftell(fd));
        print_flog("Position of pointer before setting pointer: %ld",ftell(fd));
        charcount = ftell(fd);
        //sleep(1);
        if(charcount > 2000)
        {
            //rewind(fd);     //It will put pointer in beginning of file
            fseek(fd, 0, SEEK_SET);    //Here we can set position to pointer
            print_log("Position of pointer after setting pointer: %ld",ftell(fd));
            print_flog("Position of pointer after setting pointer: %ld", ftell(fd));
            print_flog("Rewind happend");
            break;
        }
        else
        {
            print_flog("Now overwriting is performed in file");
        }
    };

    fclose(fd);


    return 0;
}

