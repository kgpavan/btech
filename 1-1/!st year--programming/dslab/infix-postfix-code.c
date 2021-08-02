#include<stdio.h>
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
main()
{
	int i,count,l;
	char a[100];
	scanf("%s",a);
	i=0;
	while(a[i]!='\0')
	{
		l++;
		i++;
	}
	
	
