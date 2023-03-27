#include<stdio.h>
#include<string.h>

int main()
{
/*    //String should be enclosed in DOUBLE QUOTES always
    printf("%s", "Hello everyone\n");     
//    printf("%s", 'Hello everyone\n');     //its wrong 

    //To printf a string in next line
    printf("%s", "You have to dream before your dreams come true.\ 
            --- A.P.J. Abdul Kalam\n");

    printf("%s", "You have to dream before your dreams come true." 
           " --- A.P.J. Abdul Kalam\n");
*/

    char s1[] = "asdfgh";
    printf("Before change s1: %s\n", s1);
    s1[0] = 'x';
    printf("After change s1: %s\n", s1);

    char *s2 = "abcdef";
    printf("s2: %s\n", s2);

    s2 = "new string";
    printf("New string s2: %s\n", s2);


    return 0;
}
