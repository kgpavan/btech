#include "alloc.h"
struct node
{
	int item;
	struct node *next;
};
void push(struct node **q,int val)
{
	struct node *temp;
	temp=malloc(sizeof(struct node));
	temp->item=val;
	temp->next=(*q);
	(*q)=temp;
}
pop(struct node **q)
{
	int top;
	struct node *temp;
	if((*q)==NULL)
	{
		printf("stack is empty");
	}
	else
	{
		temp=(*q);
		top=temp->item;
		(*q)=temp->next;
		free(temp);
	}
		return top;
}
void display(struct node *q)
{
	printf("\n");
	while(q!=NULL)
	{
		printf("%d ",q->item);
		q=q->next;
	}
}

void main()
{
	struct node *p;
	p=NULL;
	push(&p,10);
	push(&p,20);
	display(p);
	push(&p,30);
	printf("%d\n",pop(&p));
	printf("%d\n",pop(&p));
	display(p);
	printf("%d\n",pop(&p));
	printf("%d\n",pop(&p));
	printf("%d\n",pop(&p));
}
