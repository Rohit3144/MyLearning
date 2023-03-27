#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    //Sum of n numbers given by user
    int i, sum = 0;
    printf("Enter the number of arguments you want to add %d\n", argc);
    
    for(i=0; i<argc; i++)
    {
        printf("Argument number argv[%d] = %s\n", i, argv[i]);
        sum = sum + atoi(argv[i]);
    }
    printf("Sum = %d", sum);
        
    //To add two numbers given by user
/*    printf("Number of arguments are %d\n", argc);
    int a, b, sum;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    sum = a+b;
    printf("Sum of a and b = %d\n", sum);
*/
    return 0;
}
