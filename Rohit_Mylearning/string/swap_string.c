#include<stdio.h>
#include<string.h>

void swap_str(char str11[20], char str22[20])
{
    char temp[20];
    //strcpy(temp, str1);
   // printf(" temp=%s",temp);
    strcpy(temp,str11);
    strcpy(str11,str22);
    strcpy(str22,temp);

    printf("%c\n", str11);
    
    printf("str1: %s\n", str11);
    printf("str2: %s\n", str22);

}
int main()
{
    char str1[20] = "Rohit";
    char str2[20] = "Kuhar";
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("%x\n", str1);
    swap_str(str1, str2);
    
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    
    return 0;
}
