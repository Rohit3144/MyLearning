#include<stdio.h>
int main()
{
    int i, j = 153, x, cube, sum;
    i = j;
    while(i > 0)
    {
        x = i % 10;
        printf("x = %d\n", x);
        cube = x * x * x;
        printf("cube = %d\n", cube);
        sum = sum + cube;
        printf("sum = %d\n", sum);
        i = i / 10;
        printf("value of i is %d\n", i);
    
    if(j == sum)
    {
        printf("This is Armstrong number\n");
        printf("Number = %d and sum = %d\n", j, sum);
    }
    else
    {
        printf("This is not\n");
    }
    }
    return 0;
}
