#include<stdio.h>

#define AREA(l, b) (l * b)

int main()
{
    int l1 = 10, l2 = 20, area;
    area = AREA(l1, l2);

    printf("Area is %d\n", area);

    return 0;
}
