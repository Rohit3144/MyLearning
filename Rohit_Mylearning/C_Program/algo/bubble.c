#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubble_sort(int A[], int n)
{
    int i, j, flag=0;
    for(i=0; i<n-1; i++)
    {
        flag=0;
        for(j=0; j<n-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                // By default array is call by address
                swap(&A[j], &A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int A[] = {3,5,2,10,7,11,55,9,20,1};
    int n = 10;

    bubble_sort(A, n);
    for(int i=0; i<10; i++)
    {
        printf("Bubble sort: %d\n", A[i]);
    }

    return 0;
}
