#include<stdio.h>

int main()
{
    int lower = 4, upper = 10, i, j, c;
    /*printf("Enter the starting point:  ");
    scanf("%d", &lower);
    printf("\nEnter the ending point:  ");
    scanf("%d", &upper);
    */    
    for(i=lower; i<=upper; i++)
    {
        //if(i == 0 || i == 1)
            //continue;

        c = 1;

        for(j=2; j<=i; ++j)
        {
            if(i%j == 0)
            {
                c = 0;
                //break;
            }
        }
        if(c == 1)
            printf("%d", i);
    }
                   
    return 0;
}
