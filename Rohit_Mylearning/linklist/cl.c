#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next; 
};

void display(struct node ** ptr)
{
    struct node * t = *ptr;
    while(*ptr != NULL)
    {
        printf("%d -> ", (*ptr)->data);
        *ptr = (*ptr)->next;
    }
    printf("NULL \n");
}
void  IAS(struct node ** head, int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if(*head == NULL )
        *head = ptr;
    else
    {
       ptr->next = *head;
       *head = ptr;
    }

}

int main()
{
  struct node *head;
  IAS(&head, 10);
  IAS(&head, 23);
  IAS(&head, 43);
  display(&head);
  display(&head);
  return 0;
}

