#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

void display(struct node * n)
{
	while(n != NULL)
		{
			printf("%d\n", n -> data);
			n = n -> next;
		}
}

int main()
{
	struct node * head = NULL;
	struct node * second = NULL;
	struct node * third = NULL;

	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));

	head->data = 1;
	head->next = NULL;

	second->data = 2;
	second->next = NULL;

	third->data = 3;
    third->next = NULL;

//	printf("head->data = %d\n", head->data);
//	printf("second->data = %d\n", second->data);
//	printf("third->data = %d\n", third->data);
	display(head);

	return 0;
}
