#include<stdio.h>

int main()
{
    int row, col, i, j;

        printf("Enter the number of rows\n " );
        scanf("%d", &row);
        printf("Enter the number of columns\n " );
        scanf("%d", &col);
    if(row>=1 && col >= 1)
    {
        int a[row][col], b[row][col], sum[row][col];
        printf("Enter the elements of a");
        for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("Insert at a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the number for second matrix\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("Insert at b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\nAddition matrix sum[row][col]:\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d\t",sum[i][j]);
        }
        printf("\n");
    }
    }
    else
    {
        printf("Invalid Input\n");
        printf("Please give positive numbers only\n");
    }

    return 0;
}
