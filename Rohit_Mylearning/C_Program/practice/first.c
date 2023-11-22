// Print all ASCII value and their equivalent character

#include<stdio.h>

int main()
{
    int i;
    char a, z;
    while(i <= 255)
    {
        printf("ASCII value of %c %d\n", i, i);
        i++;
    }
    return 0;
}
