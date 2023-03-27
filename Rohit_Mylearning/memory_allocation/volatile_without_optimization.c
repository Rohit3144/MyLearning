/* Compile code without optimization option */
/*
When we compile code with “–save-temps” option of gcc, it generates 3 output files:
1) preprocessed code (having .i extension)
2) assembly code (having .s extension) and
3) object code (having .o extension).

We compiled code without optimization, that’s why the size of assembly code will be larger (which is highlighted in red below).
*/
/* 
 guest@guest-VirtualBox:/media/sf_VM_SHARED/my_learning$ gcc volatile_without_optimization.c -o volatile_without_optimization -save-temps
 guest@guest-VirtualBox:/media/sf_VM_SHARED/my_learning$ ./volatile_without_optimization
 Initial value of local : 10
 Modified value of local: 100
 guest@guest-VirtualBox:/media/sf_VM_SHARED/my_learning$ ls -l volatile_without_optimization.s
-rwxrwx--- 1 root vboxsf 1172 Dec 29 15:59 volatile_without_optimization.s
 */

#include <stdio.h>

int main(void)
{
    const int local = 10;
	int *ptr = (int*) &local;
	// int *ptr = &local;
	/* volatile_without_optimization.c: In function ‘main’:
volatile_without_optimization.c:25:20: warning: initialization discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
   25 |         int *ptr = &local;
      |                    ^
	*/

	printf("Initial value of local : %d \n", local);

	*ptr = 100;

	printf("Modified value of local: %d \n", local);

	return 0;
}

