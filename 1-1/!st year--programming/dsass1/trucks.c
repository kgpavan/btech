#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
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
		return 0;
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
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int k,j,mine;
		scanf("%d",&k);
		int a[100];
		for(j=0;j<k;j++)
			scanf("%d",&a[j]);
	//	int min=a[0];
	//	for(j=1;j<k;j++)
	//	{
	//		if(a[j]<min)
	//		{
	//			min=a[j];
	//		}
	//	}
	//	for(j=k;j<=40;j++)
	//		a[j]=0;
		int count=1;
		for(j=0;j<k;j++)
		{

			if( count==top(&s) && s!=NULL)
			{
				while(top(&s)==count)
				{
			//	printf("test=%d",a[j]);
				//push(&s,a[j]);
					pop(&s);
					count++;
				}
			}
			  if(count!=a[j])
			 {
				// pop(&s);
			//	count++;
			//	printf("count1=%d\n",count);
				 push(&s,a[j]);
			 }
			 else
			 {
				 count++;
			//	 printf("count2=%d\n",count);
			 }

		}
		mine=top(&s);
	//	printf("top=%d",top(&s));
		while(s!=NULL)
		{
			if(mine==top(&s))
			{
				pop(&s);
				mine++;
			}
			else
			{
				printf("no\n");
				break;
			}
		}
		if(s==NULL)
			printf("yes\n");
		while(s!=NULL)
		{
			pop(&s);
		}

	}
}




