#include <stdio.h>

/*
guest@guest-VirtualBox:/media/sf_VM_SHARED/my_learning$ gcc memory_layout.c -o memory_layout
guest@guest-VirtualBox:/media/sf_VM_SHARED/my_learning$ size memory_layout
   text	   data	    bss	    dec	    hex	filename
   1228	    544	      8	   1780	    6f4	memory_layout
*/

//int global; // Uninitialized variable stored in bss
int global = 6; // Initialized variable stored in bss

int main(void)
{
	//static int i; // Uninitialized static variable stored in bss 
	static int i = 7; // Uninitialized static variable stored in bss 
	printf("global = %d static i = %d\n", global, i);
    return 0;
}
