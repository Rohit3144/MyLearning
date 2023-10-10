// C Program to Demonstrate the use of strcmp() function
#include <stdio.h>
#include <string.h>

int main()
{
	// declaring two same string
	char *first_str  = "aa";
	char *second_str = "pa";

	// printing the strings
	printf("First String: %s\n", first_str);
	printf("Second String: %s\n", second_str);

	// printing the return value of the strcmp()
	printf("Return value of strncmp(): %d \n",
		strncmp(first_str, second_str, 1 ));
        
        if(!strcmp(first_str, second_str))
        {
            printf("condition will break\n");
            
        }

	return 0;
}

