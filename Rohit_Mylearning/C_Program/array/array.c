#include<stdio.h>

int main()
{
	/*int a[1];
	int n = 10;*/

	/*int arr[2];
	printf("a[3] = %d\n", a[3]);
	printf("a[-2] = %d\n", a[-2]);*/

	/*int b[2] = {1, 2, 3};
 	printf("b[2] = %d\n", b[2]);*/

	// an array of 10 integers.
    // If arr[0] is stored at
    // address x, then arr[1] is
    // stored at x + sizeof(int)
    // arr[2] is stored at x +
    // sizeof(int) + sizeof(int)
    // and so on.
    /*int arr[5], i;

    printf("Size of integer in this compiler is %lu\n",
           sizeof(int));

    for (i = 0; i < 5; i++)
	{
        // The use of '&' before a variable name, yields
        // address of variable.
        printf("Address arr[%d] is %p\n", i, &arr[i]);
	}*/

	/* int arr[6] = {11, 12, 13, 14, 15, 16};

    // Way 1
    for(int i = 0; i < 6; i++)
	{
	  	printf("%i ", arr[i]);
	}
    printf("\n");

    // Way 2
    printf("By Other Method: \n");

    for(int i = 0; i < 6; i++)
	{
		printf("%i ", i[arr]);
	}
	printf("\n");
	************************/

	int arr[] = { 10, 20, 30, 40, 50, 60 };
    int* ptr = arr;
 
    // sizof(int) * (number of element in arr[]) is printed
    printf("Size of arr[] %ld\n", sizeof(arr));
 
    // sizeof a pointer is printed which is same for all
    // type of pointers (char *, void *, etc)
    printf("Size of ptr %ld\n", sizeof(ptr));

	char *cptr;
	int *iptr;
	float *fptr;
	double *dptr;	
	void *vptr;	
    printf("Size of ctpr = %ld\t iptr = %ld\t fptr = %ld\t dptr = %ld\t vptr = %ld\n", sizeof(cptr), sizeof(iptr), sizeof(fptr), sizeof(dptr), sizeof(vptr));

	return 0;

}
