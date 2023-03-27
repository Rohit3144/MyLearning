#include<stdio.h>

int main(int argc, char *argv[])
{
    printf("Total number of arguments =  %d\n", argc);
    for(int i=0; i<argc; i++)
    {
        printf("Element at position %d is agv[%s]\n", i, argv[i]);
    }

    return 0;
}

