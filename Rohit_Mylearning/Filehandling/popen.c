#include<stdio.h>

int main()
{
    FILE *fileopen;
    char line[300];

    fileopen = popen("ls -lrt", "r");
    while(fgets(line, sizeof(line), fileopen))
    {
        printf("line is: %s", line);
    }

    pclose(fileopen);
    return 0;
}
