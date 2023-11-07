#include<stdio.h>

void swap(*x, *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubble_sort(int A[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(A[j] > A[j++])
                // By default array is call by address
                swap(A[i], A[j]);
        }
    }
}

void main()
{
    int A[] = {3,5,2,10,7,11,55,9,20,1};
    int n = 10;

    bubble_sort(A, 10);
    for(int i=0; i<10; i++)
    {
        printf("Bubble sort: %d\n" A[i]);
    }

    return 0;
}