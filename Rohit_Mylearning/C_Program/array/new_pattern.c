// Online C compiler to run C program online
#include <stdio.h>
#include<unistd.h>

int main() {
    // Write C code here
    for(int i=1; i<=5; i++)
    {
//        sleep(1);
        for(int n=4; n>=i; n--)
        {
            printf(" ");
        }
        for(int j=1; j<=i; j++)
        {
            printf("R ");
        }
        
//        sleep(2);
        for(int k=4; k>=i; k--)
        {
            printf(" ");
        }
        for(int l=4; l>=i; l--)
        {
            printf(" ");
        }
        for(int m=1; m<=i; m++)
        {
            printf("K ");
        }
        printf("\n");
    }

    return 0;
}
