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
    char filename[100];
    char ch;
    int charcount = 0;
    
    fd = fopen("test.txt", "a+");
    
    /*while(ch = fgetc(fd) != EOF)
    {
        //if(ch == '')
            charcount ++;
    }
    printf("Total number of characters are %d\n", charcount);*/


    while(1)
    {
        fseek(fd, 0, SEEK_END);
        printf("Position of pointer before setting pointer: %ld\n",ftell(fd));
        fprintf(fd, "[%s] [%s] [%s] [%d] Position of pointer before setting pointer: %ld\n", timestamp(), __FILE__, __func__, __LINE__, ftell(fd));
        charcount = ftell(fd);
        if(charcount > 2000)
        {
                int i;
                FILE *ls_cmd = popen("find . -type f -name 'a*.txt' | grep -o -E '[0-9]+' | sort -rn | head -n 1", "r");            
                if (ls_cmd == NULL)
                {
                     fprintf(stderr, "popen(3) error");
                     exit(EXIT_FAILURE);
                }
                char buff[1024];
                size_t n;
                while ((n = fread(buff, 1, sizeof(buff)-1, ls_cmd)) > 0)
                {
                    buff[n] = '\0';
                    printf("file_content is = %s", buff);
                }
                sprintf(filename, "file_%d.txt", i++);
                //files[i] = fopen(filename, "w");
                char filename1[200];
                sprintf(filename1, "mv test.txt %s", filename);
                system(filename1);

                rewind(fd);
                printf("Position of pointer after setting pointer: %ld\n",ftell(fd));
                fprintf(fd, "[%s] [%s] [%s] [%d] Rewind happend\n", timestamp(), __FILE__, __func__, __LINE__);
                i = 0;
                break;
        }
            /*//rewind(fd);     //It will put pointer in beginning of file
            fseek(fd, 1000, SEEK_SET);    //Here we can set position to pointer
            printf("Position of pointer after setting pointer: %ld\n",ftell(fd));
            fprintf(fd, "[%s] [%s] [%s] [%d] Position of pointer after setting pointer: %ld\n", timestamp(), __FILE__, __func__, __LINE__, ftell(fd));
            fprintf(fd, "[%s] [%s] [%s] [%d] Rewind happend\n", timestamp(), __FILE__, __func__, __LINE__);
            break;
        }*/
        else
        {
            fprintf(fd, "[%s] [%s] [%s] [%d] Writting in new file\n", timestamp(), __FILE__, __func__, __LINE__);
        }
    };

    fclose(fd);


    return 0;
}

