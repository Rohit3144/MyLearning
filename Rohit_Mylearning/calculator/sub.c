#include<stdio.h>

extern int g_val;

int sub(int a, int b) 
{
    printf("Global = %d\n", g_val);
    //printf("Static = %d\n", s_val);
    int mysub = 0;
    mysub = a - b;
    return mysub;
}
