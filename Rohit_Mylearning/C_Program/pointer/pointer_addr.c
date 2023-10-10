#include <stdio.h>

int main() 
{
    // Write C code here
    int a[] = {1,2};
    int *p = &a;

	printf("*(&p+1) = %p\n", *(&p+1));
    printf("sizeof(p) = %p\n", sizeof(p));
    printf("sizeof(int *) = %ld\n", sizeof(int *));

    return 0;
}
