#include<stdio.h>
#include<string.h>
int main()
{
    char name[20];
    char mobile[10];

    printf("Enter you name: ");
//    scanf("%s", &name);
    gets(name);

    printf("Enter you mobile: ");
//    scanf("%s", &mobile);
    gets(mobile);

    puts(name);
    puts(mobile);

    printf("Length od name string: %ld\n", strlen(name));

    return 0;
}
