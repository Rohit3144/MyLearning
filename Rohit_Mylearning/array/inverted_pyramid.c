#include<stdio.h>

int main()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=4; j>=i; j--)
        {
            printf(" ");
        }
        for(int k=1; k<=i; k++)
        {
            printf("* ");
        }
/*        for(int l=1; l<=i; l++)
        {
            printf("* ");
        }
*/        printf("\n");
    }    
    
    for(int x=1; x<=5; x++)
    {
        for(int m=1; m<=x; m++)
        {
            printf(" ");
        }
        for(int n=4; n>=x; n--)
        {
            printf("* ");
        }
/*        for(int o=4; o>=x; o--)
        {
            printf("* ");
        }
*/        printf("\n");
    }
      
    
    return 0;
}
