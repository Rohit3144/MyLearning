#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * L; 
    struct node * R; 
};

void display(struct node *node)
{
    if(node!= NULL)
    {
     display(node->L);
     printf("%d ", node-> data);
     display(node->R);
    }
}
struct node* IAS(struct node * head,struct node * t)
{
     if(head == NULL)
         head = t;
     else
     {
        if(t->data <= head-> data)
        {
           if(head-> L == NULL)
               head->L = t;
           else
               IAS(head->L, t);
        }
        else
        {
           if(head-> R == NULL)
               head->R = t;
           else
               IAS(head->R, t);
        }
     }
     return head;
}
struct node* create(struct node * head,int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->L = NULL;
    ptr->R = NULL;
   
    return IAS(head,ptr) ;
}

int main()
{
  struct node *head;
  int a[10] = {12,24,5,1,90,34,77,3,56,80};
  for (int i = 0; i <10;i++)
     head = create(head,a[i]);
  display(head);
  printf("\n");
  return 0;
}

