#include<stdio.h>
#include<string.h>

struct mystructure
{
    int mynum;
    char mychar, mystring[];
};
int main()
{
    struct mystructure ss;
    ss.mynum = 10;
    ss.mychar = 'R';
    strcpy(ss.mystring, "This is string structure");

    printf("mynum = %d\n", ss.mynum);
    printf("mychar = %c\n", ss.mychar);
    printf("mystring = %s\n", ss.mystring);

    return 0;
}
