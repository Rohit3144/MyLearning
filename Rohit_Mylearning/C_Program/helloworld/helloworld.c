#include <stdio.h>

enum calci
{
    Add = 1,
    Sub,
    Mul,
    Div
};

int sum(int, int);
int sub(int, int);
int multi(int, int);
int div(int, int);


int main()
{
    printf("Hello World\n");
    int a, b, condition;
    printf("Enter first number\n");
    scanf("%d", &a);
    printf("Enter second number\n");
    scanf("%d", &b);
    
    printf("For add press 1\n For subtraction press 2\n For multiplication press 3\n For division press 4\n ");
    scanf("%d", &condition);
    
    switch(condition)
    {
    
        // Addition
        case Add:
        int mysum = sum(a, b);
        printf("mysum = %d\n", mysum);
        break;

        //Subtraction
        case Sub:
        int mysub = sub(a, b);
        printf("mysub = %d\n", mysub);
        break;
    
        // Multiplication
        case Mul:
        int mymul = multi(a, b);
        printf("mymul = %d\n", mymul);
        break;

        // Division
        case Div:
        if(b==0)
        {
            printf("Number can not be divided\n");
   
        }    
        else
        {
            float mydiv = (float)div(a, b);
            printf("mydiv = %f\n", mydiv);
        }
        break;

        default:
        printf("Invalid input\n");
    }

    return 0;
}

