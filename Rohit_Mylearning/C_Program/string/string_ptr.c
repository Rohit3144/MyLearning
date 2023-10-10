#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "Rohit";
    printf("String: %s\n", str);
    char *ptr = str;
    
    while( *ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n") ;
    return 0;
}
