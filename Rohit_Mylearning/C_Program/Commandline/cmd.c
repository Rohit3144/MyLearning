#include<stdio.h>

int main(int argc, char *argv[])
{
    printf("Number of elements: %d\n", argc);
    
    for(int i = 0; i < argc; i++)
    {
        printf("Elements at position %d is argv[%s]\n", i, argv[i]);
    }
    return 0;
}
