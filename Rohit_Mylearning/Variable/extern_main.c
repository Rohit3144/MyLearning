// Used when a particular file needs access a variable from another file
// Extern variable should only be declared not defined

#include<stdio.h>

//extern int a;
int a = 10;
int main()
{
    extern int a;                 //its declared
    //extern int a = 5;           // now a is both extern and initialised so wrong
    printf("Value of a = %d\n", a);
    return 0;
}
