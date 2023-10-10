#include<stdio.h>

int main()
{
    int arr[10] = {[0] = 11, [3] = 22};
    for(int i=9; i>=0; i--)    
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


    return 0;
}
