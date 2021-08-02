#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int item;
	struct node *next;
}stack;
stack *s,*m;
void push(int value,stack **s)
{
	stack *temp;
	if ((*s)==NULL)
	{
		*s=(stack*)malloc(sizeof(stack));
		(*s)->item=value;
		(*s)->next=NULL;
	}
	else 
	{
		temp=(stack *)malloc(sizeof(stack));
		temp->item=value;
		temp->next=*s;
		*s=temp;
	}
}
int pop(stack **s)
{
	stack *temp;
	int p;
	if((*s)==NULL)
	{
		printf("underflow");
	}
	else 
	{
		temp=*s;
		*s=(*s)->next;
		free(temp);
	}
}
int top(stack **s)
{
		return (*s)->item;
}
int isEmpty(stack *s)
{
	if(s==NULL)
		return 0;
	return 1;
}
main()
{
	int l=0,val;
	char str[20];
	scanf("%s",str);
	while(strcmp(str,"END")!=0)
	{
	
	
		if(strcmp(str,"POP")==0)
		{
			if(s==NULL)
			{
				printf("underflow\n");
				//continue;
			}
			else
			{
			if(top(&m)==top(&s))
				pop(&m);
			pop(&s);
			l--;
			}
		//	continue;
		}
		if(strcmp(str,"TOP")==0)
		{
			if(s==NULL)
			{
				printf("underflow\n");
		//		continue;
			}
			else
			printf("%d\n",top(&s));
		//	continue;
		}
		if(strcmp(str,"MIN")==0)
		{
			if(m==NULL)
			{
				printf("underflow\n");
		//		continue;
			}
			else
			printf("%d\n",top(&m));
		//	continue;
		}
	//	if(strcmp(str,"END")==0)
	//	{
	//		printf("%d\n",l);
	//		break;
	//	}
		if(strcmp(str,"PUSH")==0)
		{
			scanf("%d",&val);
			push(val,&s);
			if(m==NULL||top(&m)>val)
				push(val,&m);
			l++;
		}
		scanf("%s",str);
	}
	printf("%d\n",l);
}










