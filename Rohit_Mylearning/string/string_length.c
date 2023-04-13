#include<stdio.h>
#include<string.h>

int main()
{
   // char a[] = "Rohit Kuhar";
   // printf("Length of string: %ld\n", strlen(a));

    char text[100];
    int count;
    printf("Enter a string\n");

    //To read space in string %[^\n]s or %[^\n]*c
    scanf("%[^\n]*c", text);

    for(int i=0; text[i]!='\0'; i++)
    {
        count++;
    }
    printf("String is %s = %d\n", text, count);

    return 0;
}
