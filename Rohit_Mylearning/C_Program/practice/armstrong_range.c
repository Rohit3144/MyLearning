#include<stdio.h>
int main()
{
     int a, i, x, cube, sum;
     for(a = 1; a <= 153; a++)
     {
         printf("Value of a = %d\n", a);
         i = a;
         while(i > 0)
         {
             x = i%10;
             cube = x * x * x;
             printf("cube = %d\n", cube);
             sum = sum + cube;
             i = i/10;
         
         printf("sum = %d\n", sum);
         if(a == sum)
         {
             printf("%d is Armstrong number\n", a);
         }
         /*else
         {
             printf("%d is not armstrong number\n", a);
         
         }*/
         }
         sum = 0;
     }
     return 0;     
}

