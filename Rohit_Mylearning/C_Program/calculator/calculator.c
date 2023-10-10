#include <stdio.h>

enum calculator
{
    add = 1,
    subt,
    mul,
    divi
};

double sum(double, double);
int sub(int, int);
int multiply(int, int);
float div(int, int);

int g_val = 15;
static int s_val = 10;

int main()
{
    printf("Hello World\n");
    double a, b, result;
    printf("Enter first number\n");
    scanf("%lf", &a);
    printf("Enter second number\n");
    scanf("%lf", &b);
    printf(" For add press 1\n For sub press 2\n For mul press 3\n For Div press 4\n");
    scanf("%lf", &result);

    // Addition
    if(result == add)
    {
        double mysum = sum(a, b);
        printf("mysum = %f\n", mysum);
    }

    //Subtraction
    else if(result == subt)
    {
        int mysub = sub(a, b);
        printf("mysub = %d\n", mysub);
    }
    
    // Multiplication
    else if(result == mul)
    {
        int mymul = multiply(a, b);
        printf("mymul = %d\n", mymul);
    }

    // Division
    else if(result ==divi)
    {
        if(b==0)
        {
            printf("Invalid input\n"); 
        }    
        else
        {
            float mydiv = div(a, b);
            printf("mydiv = %f\n", mydiv);
        }
    }
    else
    {
        printf("Please enter the valid number\n");
    }

    return 0;

}
