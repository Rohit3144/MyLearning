#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

int main()
{
	int i,n,x;
	printf("How many numbers\n");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		printf("Enter number\n");
		scanf("%d", &x);
	}
	
/*	struct node *head, *traverse, *newnode;
	head = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data/n");
	scanf("%d\n", &newnode->data);
	newnode->next;

	if(head==NULL)
	{
		head = traverse = newnode;
	}
	else
	{
		traverse->next = newnode;
		traverse->newnode;
	}*/

	return 0;

}
