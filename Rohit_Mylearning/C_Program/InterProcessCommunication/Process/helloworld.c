#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main() {
   printf("Hello World\n");
   printf("getpid = %d\t getppid = %d\t File name = %s\t Func name = %s\t Line num = %d\n", getpid(), getppid(), __FILE__, __func__, __LINE__);
  // execl("./execl_test", "./execl_test", (char *)0);               it will make a loop thats why both lines are commented
  // printf("This would not print\t FIle name = %s\n", __FILE__);
   return;
}
