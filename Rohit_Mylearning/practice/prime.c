#include<stdio.h>

int main()
{
    int i, n, c = 0;
    printf("Check number whether prime or not: \n");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        if(n%i==0)
            c++;
    }
    printf("Counter is: %d\n", c);

    if(c == 2)
    {
        printf("Number is prime\n");
    }
    else
    {
        printf("Number is not prime\n");
    }

    return 0;
}
