#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void insert(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	//temp->next = head;
	//head = temp;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

void print()
{
	struct node* temp = head;
	printf("The list is\n");
	while(temp != NULL)
	{
		printf("[%d]->", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int i, n, x;

	head = NULL;
	printf("How many numbers\n");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter the number\n");
		scanf("%d", &x);
		insert(x);
	}

	print();

	return 0;
}

