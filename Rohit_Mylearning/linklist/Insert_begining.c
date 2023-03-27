#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next; 
};

void traverse(struct node * ptr)
{
    while(ptr != NULL)
    {
        printf("data: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node * insertatstart(struct node * head, int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;

}

int main()
{
    struct node * head = (struct node*)malloc(sizeof(struct node));
    struct node * second = (struct node*)malloc(sizeof(struct node));
    struct node * third = (struct node*)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 13;
    third->next = NULL;

    traverse(head);
//    insertatbegining(head, data);
    return 0;
}

