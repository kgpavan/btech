#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
	int value;
	struct stack *next;

}stack;
void push(stack **s,int val)
{
	stack *temp;
	temp=(stack*)malloc(sizeof(stack));
	temp->value=val;
	temp->next=*s;
	*s=temp;
}
int pop(stack **s)
{
	if(*s==NULL)
	{
		return 0;
	}
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
	{
		return 0;
	}
	else
	{
		return((*s)->value);
	}
}
/*void reduceAt(stack **s,int val)
{
	int i,a[100];
	for(i=0;i<val;i++)
	{
		a[i]=top(s);
		pop(s);
	}
	int q=top(s);
	pop(s);
	int w=top(s);
	if(q<w)
	{
		for(i=val-1;i>=0;i--)
		{
			push(s,a[i]);
		}
	}
	else if(q>w)
	{
		pop(s);
		push(s,q);
		for(i=val-1;i>=0;i--)
			push(s,a[i]);
	}
}*/
int reduceAt(stack **s,int val)
{
	int i;
	stack *temp;
	temp=(*s);
	stack *temp2=(temp->next);
	for (i=0;i<val;i++)
	{
		temp=temp->next;
		temp2=temp2->next;
	}
	
	if ((temp->value)<(temp2->value))
		temp->value=temp2->value;
	temp->next=temp2->next;
}
void printAt(stack **s,int val)
{
	int i;
	stack *temp;
	temp=(*s);
	for(i=0;i<val;i++)
	{
		temp=(temp->next);
	}
	printf("%d\n",temp->value);

}
main()
{
	stack *s;
	
	int n,i;
//	stack *temp;
//	temp=(*s);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		s=NULL;
		char arr[100];
		int k,t,j,c=0,x=0,f;
		scanf("%d",&k);
		int b[k];
		for(j=0;j<k;j++)
			scanf("%d",&b[j]);
		for(j=k-1;j>=0;j--)
		{
			push(&s,b[j]);
		}
		scanf("%d",&t);
		for(f=0;f<t;f++)
		{
			/*stack *temp=s;
			while (temp!=NULL)
			{
				printf("%d ", temp->value);
				temp=temp->next;
			}
			free(temp);*/
			x=0;c=0;
			scanf("%s",arr);
			if(arr[0]=='r')
			{
				for(j=9;arr[j]!=')';j++)
					c=c*10+(arr[j]-48);
				reduceAt(&s,c);
			}
			if(arr[0]=='p')
			{
				for(j=8;arr[j]!=')';j++)
					x=x*10+(arr[j]-48);
				printAt(&s,x);
			}
		}
	}
}






