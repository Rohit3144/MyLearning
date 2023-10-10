#include <stdio.h>
#include <stdlib.h>

void memory_allocator(int **myptr);

int main()
{
  int array[5];
  int *ptr = NULL;
  //ptr = (int *)malloc(sizeof(int)*5);
  memory_allocator(&ptr);
  if(ptr == NULL)
  {
    printf("No memory allocated\n");
    return -1;
  }
  else
  {
    printf("Memory allocated successfully\n");
  }
  return 0;
}

void memory_allocator(int **myptr)
{
  *myptr = (int *)malloc(sizeof(int)*5);
  if(*myptr == NULL)
  {
    printf("==>No memory allocated\n");
  }
  else
  {
    printf("==>Memory allocated successfully\n");
  }
}
