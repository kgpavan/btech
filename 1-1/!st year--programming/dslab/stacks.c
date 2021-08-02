#include<stdio.h>
#include<stdlib.h>
typedef struct new{
	int element;
	struct new *link;
}stack;
void push(stack **s,int value);
int pop(stack **s);
int empty(stack *s);
void print(stack *s);
main()
{
	int i,j,k,number,y;
	stack *s;
	s=NULL;
	for(i=0;i<3;i++){
		scanf("%d",&number);
		push(&s,number);
	}
	print(s);
	for(i=0;i<4;i++){
		if(pop(&s)==-10)
			printf("Stack Overflow\n");
		print(s);
	}
}
void push(stack **s,int value)
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->element=value;
	temp->link=*s;
}
int pop(stack **s)
{
	int i;
	if(!empty(*s))
	{
		i=(*s)->element;
		(*s)=(*s)->link;
		return i;
	}
	else
		return -10;
}
int empty(stack *s)
{
	if(s!=NULL)
		return 0;
	else
		return 1;
}
void print(stack *s)
{
	while(s!=NULL){
		printf("%d\n",s->element);
		s=s->link;
	}
}
