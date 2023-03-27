#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char a[20] = "Rohit";
    char b[20];
    printf("Before reverse: %s\n", a);

 //   b = strrev(a);
    
    printf("After reverse: %s\n", strrev(a));
    
    return 0;
}
