//***** Compute the value of a number raised to another numbere ********

#include<stdio.h>
int main()
{
    int i = 1, num, pow, result = 1;
    num = 2;
    pow = 3;
    while(i <= pow)
    {
        result = result * num;
        i++;
    }
    
    printf("Result  = %d\n", result);
    return 0;
}
