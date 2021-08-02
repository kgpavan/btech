#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct node{
	char a[20];
	struct node *link;
}stack;
stack *x=NULL;
stack *next(stack *y,char b[])
{
	stack *temp;
	temp=malloc(sizeof(stack));
	strcpy(temp->a,b);
	if(x==NULL)
		x=temp;
	else
		y->link=temp;
	y=temp;
	y->link=x;
	return y;
}
stack *del(stack *s,int a)
{
	int i=0;
	stack *y;
	if(a==1)
	{
		y=s->link;
		s->link=(s->link)->link;
	}
	else
	{
		for(i=1;i<a;i++)
			s=s->link;
		y=s->link;
		s->link=(s->link)->link;
	}
	printf("%s ",y->a);
	free(y);
	return s;
}
main()
{
	stack *y;
	int a,n,i,j;
	scanf("%d %d",&a,&n);
	y=NULL;
	for(i=0;i<n;i++)
	{
		char b[20];
		scanf("%s",b);
		y=next(y,b);
	}
	stack *q;
	q=y;
	for(i=0;i<n;i++)
		q=del(q,a);
	printf("\n");
}

