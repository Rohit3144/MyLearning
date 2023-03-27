#include<stdio.h>
#include"fact.h"

int main()
{
    int res, n;

    printf("Enter a number to find factorial: ");

    scanf("%d", &n);

    res = myfact(n); 

    printf("Factorial of %d is: %d\n", n, res);

    return 0;
}
