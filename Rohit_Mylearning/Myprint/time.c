#include <time.h>
#include <stdio.h>
#include <string.h>

FILE *fptr = NULL;

//#define print_log(f_, ...) printf("[%s] [%s] [%s] [%d] ", timestamp(), __FILE__, __func__, __LINE__), printf(f_, ##__VA_ARGS__), printf("\n")
#define print_flog(f_, ...) fprintf(fptr, "[%s] [%s] [%s] [%d] ", timestamp(), __FILE__, __func__, __LINE__), fprintf(fptr,f_, ##__VA_ARGS__), fprintf(fptr,"\n")

//#define print_log(f_, ...) printf((f_), ##__VA_ARGS__), printf("\n")     //Modified
//#define print_log(f_, ...) printf("%s ", timestamp()), printf((f_), ##__VA_ARGS__), printf("\n")  //Original

char * timestamp()
{
    time_t now = time(NULL);
    char * time = asctime(gmtime(&now));
    time[strlen(time)-1] = '\0';    // Remove \n
    return time;
}

int main(int argc, char* argv[]) 
{
    fptr = fopen("log_file.txt", "a+");
    
    //print_log("[%s] [%s] [%s] [%d] Hello", timestamp(), __FILE__, __func__, __LINE__);
    print_flog("Hello");
    //print_log("%s%d","mokumus",1996);
    print_flog("%s %d","mokumus",1996);
    print_flog("%s %d","Rohit",2023);

    return 0;
}

/*void timestamp1()
{
    time_t ltime; //calendar time
    ltime = time(NULL); // get current cal time
    printf("%s", asctime(localtime(&ltime)));
}
int main()
{   
    timestamp1();
    return 0;
}*/
/*Mon Apr 24 09:15:08 2023 Hello
Mon Apr 24 09:15:08 2023 mokumus1996    */
