#include <stdio.h>

#define getName(var) #var
  
int main()
{
    int myVar;
    printf("%s\n", getName(V));
    return 0;
} 

/*
//#define PRINT(x) ('x')   ---> It's wrong (segmentation fault)
//#define PRINT(x) "x"  // ---> These are same --> ("x") || "x" || #x 
#define PRINT(x) #x

int main()
{
    printf("%s\n", PRINT(x));
    return 0;
}
*/

