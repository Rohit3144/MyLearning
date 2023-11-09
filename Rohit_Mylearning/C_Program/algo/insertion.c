#include<stdio.h>

void insertion_sort(int A[], int n)
    {

        int i, value, hole;

        for(i=1; i<n-1; i++)
        {
            value = A[i];
            hole = i;

            while(hole > 0 && A[hole-1] > value)
            {
                A[hole] = A[hole-1];
                hole = hole-1;
            }
            A[hole] = value;
        }
    }
int main()
{
    int A[] = {22, 11, 3, 5, 15, 20};
    int i, n = 6;
    
    insertion_sort(A, n);
    for(i = 0; i<n; i++)
    {
        printf("insertion sort: %d\n", A[i]);
    }
    return 0;
}
