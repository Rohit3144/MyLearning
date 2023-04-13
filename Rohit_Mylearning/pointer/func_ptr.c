#include <stdio.h> 
 
int opadd2(int *args) 
{ 
	return(args[0] + args[1]); 
} 
 
int opmul2(int *args) 
{ 
	return(args[0] * args[1]); 
} 
 
// this is the library function requiring 
// different processing of x 
int f(int *x, int(*function)(int*)) 
{ 
	return (function(x)); 
} 
 
int main() 
{ 
	int x[2] = { 5, 6 }; 
 
	printf("Add says %d\n", f(x, &opadd2)); 
	printf("Mul says %d\n", f(x, &opmul2)); 
 
} 
