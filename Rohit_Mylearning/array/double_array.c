#include<stdio.h>

int main()
{
	int single_a[4] = {1, 2, 3, 4};
//	int double_a[2][3] = {1, 2, 3, 4, 5, 6};


/*	printf("0 index single_a & = %d\t single_a value by index = %d\t single_a value by * = %d\n", &single_a, single_a[0], *(single_a+0));
	printf("1 index single_a & = %d\t single_a value by index = %d\t single_a value by * = %d\n", &single_a + 1, single_a[1], *(single_a+1));
	printf("2 index single_a & = %d\t single_a value by index = %d\t single_a value by * = %d\n", &single_a + 2, single_a[2], *(single_a+2));*/


	printf("single_a = %p\n", single_a);
	printf("&single_a = %p\n", &single_a);
	printf("*single_a = %d\n", *single_a);
	printf("single_a[0] = %d\n", single_a[0]);
	printf("single_a + 1 = %p\n", single_a + 1);
	printf("&(single_a) + 1 = %p\n", &(single_a) + 1);
	printf("*(&(single_a) + 1) = %p\n",*(&(single_a) + 1));
//	printf("&(single_a + 1) = %d\n", &(single_a + 1));
	printf("*(single_a + 1) = %d\n", *(single_a + 1));
	printf("single_a[1] = %d\n", single_a[1]);

	return 0;
}

