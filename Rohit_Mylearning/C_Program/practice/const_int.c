#include<stdio.h>

int main()
{
	int q = 5;
	int *const p = &q;

	//Valid
	*p = 7;

	const int q2 = 7;

	//Compilation error
	//p = &q2;

    printf("int const *ptr = %d\n", *p);
    printf("int const ptr = %p\n", p);

	return 0;
}

/* 
int main()
{
    const int q = 5;
 
    //Valid
    const int* const p = &q;
 
    //Compilation error
    *p = 7;
     
    const int q2 = 7;
 
    //Compilation error
    p = &q2;
     
    return 0;
}*/
