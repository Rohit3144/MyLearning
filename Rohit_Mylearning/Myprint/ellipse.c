#include<stdio.h>
#include<stdarg.h>


//count number of arguments to be send
//... --> Ellipses --> to take multiple arguments 
void fun(int total, ...)
{
    int n, num ;
    va_list ptr;
    va_start(ptr, total);
    num = va_arg(ptr, int);
    n = va_arg(ptr, int);
    
    printf("num = %d\n", num);
    printf("n = %d\n", n);

}
    
int main()
{
    fun(2, 10, 20);
    return 0;
}
