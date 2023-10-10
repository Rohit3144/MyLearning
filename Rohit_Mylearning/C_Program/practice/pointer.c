#include<stdio.h>

int main()
{
    int a = 10;
    printf("Value of a  = %d\n", a);
    printf("Address of a  = %p\n", &a);

    int *b = &a;
    printf("Address of b  = %p\n", b);
    printf("Value at address b  = %d\n", *b);

    *b = 20;
    printf("Value of b  = %d\n", *b);



    return 0;
}
