#include <stdio.h>
#include <stdlib.h>

int main()
{

    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n = 5, i;

    // Get the number of elements for the array
    printf("Enter number of elements:\n");
    //scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);

    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i) {
			printf("malloc ptr address: %p\n", &ptr[i]);
            ptr[i] = 10;
        }
        //free(ptr);
    	ptr = realloc(ptr, 10 * sizeof(int));
        // Print the elements of the array
        printf("The elements of the array are: \n");
        for (i = 0; i < n + 5; ++i) {
			printf("realloc ptr address: %p\n", &ptr+i);
            printf("%d\n", ptr[i]);
        }
    }

    return 0;
}
