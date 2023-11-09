#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort (int A[] , int n)
{
    int i, j, k;
    for(i = 0; i < n-1; i++)
    {
        for(j=k=i; j<n; j++)
        {
            if(A[j] < A[k])
            {
                k = j;
            }

        swap(&A[i], &A[k]);
        }
    }
}

int main()
{
    int A[] = {11, 23, 21, 5, 44, 7};
    int n = 6, i;

    selection_sort (A, n);
    
    for(i=0; i<n; i++)
    {
        printf("Selection sort of A: %d\n", A[i]);
    }
    return 0;
}

