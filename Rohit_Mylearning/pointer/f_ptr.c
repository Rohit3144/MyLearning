#include<stdio.h>

void add(int a, int b)
{
    printf("Addition is %d\n", a+b);
}
void sub(int a, int b)
{
    printf("Addition is %d\n", a-b);
}
void mul(int a, int b)
{
    printf("Addition is %d\n", a*b);
}
int main()
{
    void (*f_ptr[]) (int, int) = {add, sub, mul};
    int operation, a = 15, b = 20, i=1;

    printf("Enter the operation of your choice: 0 for addition , 1 for subtraction, 2 for multiplication\n");
    scanf("%d", &operation);
    while(i!=100)
    {
    if(operation > 3)
        return 0;
    
    (*f_ptr[operation]) (a, b);
    printf("if you want to quit enter 100 else enter any number\n");
    scanf("%d", &i);
    if (i!=100)
    {
    printf("Enter the operation of your choice: 0 for addition, 1 for subtraction, 2 for multiplication\n");
    scanf("%d", &operation);
    }
    }

    
    return 0;
}
