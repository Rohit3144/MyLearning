//va_list --> Type of list of arguments
//va_start(list_arg, num_arg) --> Taking the list argument & num_arg(number of arguments)
//va_arg(arg, int) --> Taking list arguments and type of arguments

#include<stdio.h>
#include<stdarg.h>

void max(int num_arg, ...);

int main()
{
    max(4, 10, 20, 30, 40);     //character will be promoted to integer value & float promoted to double
    return 0;
}
void max(int num_arg, ...)
{
    va_list arg;
    va_start(arg, num_arg);
    for(int i = 0; i < num_arg; i++)
    {
        int x = va_arg(arg, int);
        printf("x: %d\n", x);
    }
    va_end(arg);
    
}



