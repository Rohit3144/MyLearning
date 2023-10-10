#include<stdio.h>

void fun_1(int n)
{
	printf("n = %d\n", n);
	n = 5;
}

void fun_2(int *n)
{
	printf("*n = %d\n", *n);
	*n = 5;
}

void fun_3(int **n)
{
	printf("**n = %d\n", **n);
	**n = 5;
}

void fun_4(int ***n)
{
	printf("***n = %d\n", ***n);
	***n = 5;
}

void fun_5(int ****n)
{
	printf("****n = %d\n",****n);
	****n = 5;
}

int *head_global = 0;
void fun_6()
{
	*head_global = 5;
}

int head_g = 0;
void fun_7()
{
	head_g = 5;
}

int main()
{
	int j = 10;
	fun_1(j);// Call by value
	printf("j = %d\n", j);

	int k = 10;
	fun_2(&k);// Call by address
	printf("k = %d\n", k);

	int y = 10;
	int *c = &y;
	fun_3(&c);
	printf("*c = %d\n", *c);

	int m = 10;
	int *a = &m;
	int **b = &a;
	fun_4(&b);
	printf("**b = %d\n", **b);
	
	int mm = 10;
	int *aa = &mm;
	int **bb = &aa;
	int ***zz = &bb;
	fun_5(&zz);
	printf("***zz = %d\n", ***zz);
	
	int kk = 10;
	head_global = &kk;
	printf("before call *head_global = %d\n", *head_global);
	fun_6();// Call by address
	printf("after call *head_global = %d\n", *head_global);

	head_g = 20;
	printf("before call head_g = %d\n", head_g);
	fun_7();// Call by address
	printf("after call head_g = %d\n", head_g);

	return 0;
}
