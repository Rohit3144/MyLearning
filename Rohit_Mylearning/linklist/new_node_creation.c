#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * link;
};
void traverse(struct node *head)
{
    printf("Head address in traverse: %p\n", head);
    while(head != NULL)
    {
        printf("data = %d\n", head->data);
        head = head->link;
    }
}

int main()
{
   struct node * head;
   head = (struct node *)malloc(sizeof(struct node));
   head->data = 5;

   struct node *second;
   second =(struct node *)malloc(sizeof(struct node));
   second->data = 10;
   head->link = second;

   struct node * third;
   third = (struct node *)malloc(sizeof(struct node));
   third->data = 15;
   second->link = third;

   struct node * fourth;
   fourth = (struct node *)malloc(sizeof(struct node));
   fourth->data = 20;
   third->link = fourth;

   fourth->link = NULL;
   printf("Head address in main: %p\n", head);

   traverse(head);
   printf("head->data after traverse = %d\n", head->data);
/*   printf("Head->data: %d\n",head->data);
   printf("second->data: %d\n", second->data);
   printf("third->data: %d\n", third->data);
   printf("fourth->data:%d\n", fourth->data);
   
   printf("head->link: %p\n", head->link);
   printf("second->link: %p\n", second->link);
   printf("Third->link: %p\n", third->link);
   printf("Fourth->link: %p\n", fourth->link);

   printf("Head Address: %p\n", head);
   printf("Second Address: %p\n", second);
   printf("Third Address: %p\n", third);
   printf("Fourth Address: %p\n", fourth);
*/
   return 0;
}
