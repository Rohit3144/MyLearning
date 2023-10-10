#include <stdio.h>
#include <stdlib.h>

void exitfunc() 
{
   printf("Called cleanup function - exitfunc()\n");
   return;
}

int main() 
{
   atexit(exitfunc); //atexit function executed just before exiting the function 
   printf("Hello, World!\n");
   exit (0);
}
