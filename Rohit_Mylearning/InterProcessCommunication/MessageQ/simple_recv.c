#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>

struct message_buffer
{
    long mtype;
    char mtext[100];
} message;

int main()
{

    key_t key;
    int msgid;


    key = ftok("programId", 10);
    msgid = msgget(key, 0666 | IPC_CREAT);

   for(;;)
   {
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Recieved message is : %s\n", message.mtext);
    
       if(!strncmp(message.mtext, "end", 3))
              break;
   }
    return 0;
}
