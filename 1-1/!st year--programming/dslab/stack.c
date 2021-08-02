#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct stack
{
	int value;
	struct stack *next;
}stack;
void push(stack1 **s,int val)
{
	stack *temp;
	temp=(stack*)malloc(sizeof(stack));
	temp->value=val;
	temp->next=*s;
	*s=temp;
}
void pop(stack **s)
{
	if(*s==NULL)
		printf("underflow\n");
	else
	{
		stack *temp;
		temp=*s;
		*s=(*s)->next;
		free(temp);
	}
}
int top(stack **s)
{
	if(*s==NULL)
		return 0;
	else
		return((*s)->value);
}
main()
{
	stack *s;
	(s)=NULL;


