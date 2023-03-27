#include<stdio.h>

int main()
{
    int r, c, r1, c1, i, j; 
    
    printf("Enter number of rows\n");
    scanf("%d", &r);
    printf("Enter number of columns\n");
    scanf("%d", &c);

    printf("Enter row for second matrix\n");
    scanf("%d", &r1);
    printf("Enter column for second matrix\n");
    scanf("%d", &c1);
//    if(c==r1)
//    {


    int a[r][c], b[r1][c1], m[r][c1];

    printf("\nFirst matrix elements are:\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("Insert at index [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nElements for second matrix are: \n");
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            printf("Insert at index [%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    
    for(i=0; i<r; i++)
    {
        for(j=0; j<c1; j++)
        {
            m[i][j] = 0;
            
            for(int k=0; k<c; k++)
            {
                
                 m[i][j] = m[i][j] + (a[i][k] * b[k][j]);
                 printf("m[i][j] = %d\t", m[i][j]);
                 printf("a[i][k] = %d\t", a[i][k]);
                 printf("b[k][j] = %d\n", b[k][j]);               
            }
        }
    }

    for(i=0; i<r; i++)
    {
        for(j=0; j<c1; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
//    }
/*    else
    {
        printf("\nMatrix can not be multiply\n");
    }
*/
    return 0;
}
