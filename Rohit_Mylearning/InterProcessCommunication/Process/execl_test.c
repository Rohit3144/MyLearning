#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main() {
   printf("getpid = %d\t getppid = %d\t File name = %s\t Func name = %s\t Line num = %d\n", getpid(), getppid(), __FILE__, __func__, __LINE__);
   execl("./helloworld", "./helloworld", (char *)0);
   printf("This wouldn't print\t File name = %s\n", __FILE__);
   return;
}
