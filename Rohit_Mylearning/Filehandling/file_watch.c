#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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
    FILE *fd = NULL;
    //char buffer[100];
    char ch;
    int charcount = 0;
    
    fd = fopen("test.txt", "w+");
    
    while(ch = fgetc(fd) != EOF)
    {
        //if(ch == '')
            charcount ++;
    }
    printf("Total number of characters are %d\n", charcount);


    while(1)
    {
        fseek(fd, 0, SEEK_END);
        printf("Position of pointer before setting pointer: %ld\n",ftell(fd));
        fprintf(fd, "[%s] [%s] [%s] [%d] Position of pointer before setting pointer: %ld\n", timestamp(), __FILE__, __func__, __LINE__, ftell(fd));
        charcount = ftell(fd);
        if(charcount > 2000)
        {
            //rewind(fd);     //It will put pointer in beginning of file
            fseek(fd, 1000, SEEK_SET);    //Here we can set position to pointer
            printf("Position of pointer after setting pointer: %ld\n",ftell(fd));
            fprintf(fd, "[%s] [%s] [%s] [%d] Position of pointer after setting pointer: %ld\n", timestamp(), __FILE__, __func__, __LINE__, ftell(fd));
            fprintf(fd, "[%s] [%s] [%s] [%d] Rewind happend\n", timestamp(), __FILE__, __func__, __LINE__);
            break;
        }
        else
        {
            fprintf(fd, "[%s] [%s] [%s] [%d] Now overwriting is performed in file\n", timestamp(), __FILE__, __func__, __LINE__);
        }
    };

    fclose(fd);


    return 0;
}

