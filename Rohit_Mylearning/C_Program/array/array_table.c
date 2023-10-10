#include<stdio.h>

int main()
{
    
    for(int j=2; j<=10; j++)
    {
    for(int i = 1; i <=10; i++ )
    {
        printf("%d * %d = %d", j, i, j*i);
        printf("\n");
    }
    printf("\n");
    }

    return 0;
}
