// Online C compiler to run C program online
#include <stdio.h>

void swap(int *a, int *b)
{
    int t;
   
    printf("Value of a = %d and b = %d before swapping\n", *a, *b);
    
    t = *a;
    *a = *b;
    *b = t;
    
}

int main() {
    
    int a = 10;
    int b = 20;
    printf("This is main function\n");
    swap(&a, &b);
    printf("value of a = %d b = %d after swapping\n", a, b);


    return 0;
}
