//

#include<stdio.h>
#include<string.h>

int main()
{

    char fruit[] = "Apple";
    printf("%s\n", fruit);
    fruit[0] = 'Z';
    printf("After change: %s\n", fruit);

/*    char *p1 = "Hello";
    //Value can't be changed in this case
    p1[0] = 'A';        // Segmentation fault 
*/   
/*    // Value of p1 is changed in this case
    char chr = 'Z';
    char *p1 = "Hello";
    char **p2 = &p1;
    printf("Value of p2: %c\n", **p2);

    //Core Dump
    printf("Value of ++p2: %c\n", ++(**p2));

    p1 = &chr;
    printf("p1: %c\n", *p1);
*/    
/*  char str[15] = "happy new year" ;
    char *p = str;
    char *ptr = "happy new year" ;

    printf(" %c\n", *ptr ) ;
    printf(" %s\n", p ) ;
    printf(" %s\n", str ) ;
*/
    return 0;
}
