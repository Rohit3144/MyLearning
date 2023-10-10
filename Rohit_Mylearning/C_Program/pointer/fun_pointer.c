#include<stdio.h>
#include<string.h>

void fun(int a)
{
	printf("a = %d\n", a);
}

void myram(int a)
{
	printf("Hey RAM\n");
}

int fun1()
{
	printf("Hello Rohit\n");
	return 1;
}

int main()
{
	void (*fun_ptr)(int) = &fun;
	
	int (*fun_ptr1)() = &fun1;

	printf("&fun = %p\n", &fun); // it will take fun address
	printf("fun_ptr = %p\n", fun_ptr); // it will take fun address
	printf("fun_ptr1 = %p\n", fun_ptr1);

	fun(10);
	(*fun_ptr)(33);

	fun_ptr = &myram; // it will take myram address
	printf("fun_ptr = %p\n", fun_ptr);
	(*fun_ptr)(33);
	
	(*fun_ptr1)();

	//int i = 10;
	char *c = "Lello";
	int len = strlen(c);
	int mylen = strlen(*c);
	printf("mylen = %d\n", mylen);
	for(int j = 0; j < len; j++)
	{
		printf("%c\n", *c++);
	}

	//10 = 20;
	//myram = &fun;
	//myram(10);

	return 0;
}
		



