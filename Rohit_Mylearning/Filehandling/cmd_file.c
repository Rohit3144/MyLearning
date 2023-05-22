#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    int case_number;

    printf("argc: %d\n", argc );
    printf("argv[0]: %s\n", argv[0]);
    printf("argv[1]: %s\n", argv[1]);
    
    case_number = atoi(argv[1]);
    switch(case_number)
    {
        case 1:
            fp = fopen("cmd_log.txt", "a+");
            fprintf(fp, "Writting into the file in append mode\n");
            fclose(fp);
            break;

        case 2:
            fp = fopen("cmd_log.txt", "w+");
            fprintf(fp, "This is second case\n");
            fclose(fp);
            break;

        default:
            printf("Please give 1 for appending in file\n");
            printf("Please give 2 for writting in file\n");
    }

    return 0;
}
