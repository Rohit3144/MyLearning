#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define MAX 100

struct message_buffer
{
    long mtype;
    char mtext[MAX];
} message;

int main()
{
    key_t key;
    int msgid;
    char *result; //To check return value of fgets
    int cond=1;              
    

    key = ftok("programId", 10);
    
    msgid = msgget(key, 0666 | IPC_CREAT); //IPC created
    message.mtype = 1;

    printf("Write something:\n ");
    //result = fgets(message.mtext, MAX, stdin);
    //printf("fgets returns : %s \n", result);
    while(fgets(message.mtext, MAX, stdin) != NULL)
    {
             
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Data sent is: %s with length=%ld \n", message.mtext, strlen(message.mtext));

        if(!strncmp(message.mtext, "end", strlen("end")))
        {
            printf("break will execute\n");
            break;
        } 
    }

    return 0;
}
