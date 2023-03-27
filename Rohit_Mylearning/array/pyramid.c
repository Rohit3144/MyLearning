#include<stdio.h>

int main()
{
    int rows;
    printf("Enter number of rows: \n");
    scanf("%d", &rows);
/*    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=i; j++)
        {
            printf("_");
        }
        for(int k=i; k<=rows; k++)
        {
            printf("*+");
        }
        printf("\n");
    }
*/
    for(int i=1; i<=rows; i++)
    {
        for(int j=rows; j>=1; j--)
        {
            printf("_");
        }
        
        for(int k=i; k<=i; k++)
        {
            printf("*+");
        }
        printf("\n");
    }


    return 0;
}
