#include<stdio.h>
#include<string.h>

int main()
{
    char a[20];
    char b[20];
    int i;

    printf("Enter a string: ");
    gets(a);

    for(i=0; a[i] != '\0'; i++)
    {
        b[i] = a[i];
    }
    //Make sure string is NULL terminated
    b[i] = '\0';

    printf("a[i]: %c\n", a[i]);
    printf("b[i]: %c\n", b[i]);
    printf("Total characters copied: %d\n", i);

    return 0;
}
