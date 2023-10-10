// To swap numbers using pointers

#include<stdio.h>

// Doesn't matter whether you are giving argument while declaring the function or not
// void swap(int *, int *) ----Can provide it like this
void swap(int *d, int *ak); 
int main()
{
    int a,b;
    a = 20;
    b = 30;
    printf("Before swap: a = %d, b = %d\n", a, b);
   
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
    
    return 0;
}
void swap(int *x, int *y)
{
    int z;
    z = *x;
    *x = *y;
    *y = z;
}

