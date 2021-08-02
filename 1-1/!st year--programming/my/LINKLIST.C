#include "alloc.h"
struct node
{
	int value;
	struct node *next;
};
void add(struct node **q,int num)
{
	struct node *temp,*temp1;
	if((*q)==NULL)
	{
		temp=malloc(sizeof(struct node));
		temp->value=num;
		temp->next=NULL;
		(*q)=temp;
	}
	else if((*q)-> value > num)
	{
		temp=malloc(sizeof(struct node));
		temp->value=num;
		temp->next=(*q);
		(*q)=temp;
	}
	else
	{
		temp=(*q);
		while(temp!=NULL)
	  {
		if(temp->value<=num && (temp->next->value > num || temp->next==NULL))
		{
		temp1=malloc(sizeof(struct node));
		temp1->value=num;
		temp1->next=temp->next;
		temp->next=temp1;
		return;
		}
		temp=temp->next;
	  }
	}

}
void display(struct node *q)
{
	printf("\n");
	while(q!=NULL)
	{
		printf("%d ",q->value);
		q=q->next;
	}

}
void delete(struct node ** q,int del)
{
	struct node *temp,*temp1;
	temp=*q;
	while(temp->value!=del)
	{
		temp1=temp;
		temp=temp->next;
		if(temp==NULL)
		{
			printf("element not found\n");
			break;
		}
	}
	if(temp!=*q)
	{
		temp1->next=temp->next;
		free(temp);
	}
	else
	{
		*q=temp->next;
		free(temp);
	}
}

void main()
{
struct node *p;
p=NULL;
add(&p,10);
add(&p,20);
add(&p,3);
add(&p,1);
add(&p,25);
display(p);
delete(&p,20);
display(p);
delete(&p,50);
}




