#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack{
	int value;
	int sum;
	struct stack *pre;
}node;
void push(node **vivek,int p)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	//if(temp)
	temp->value=p;
	if(*vivek==NULL)
		temp->sum=p;
	else
		temp->sum=(*vivek)->sum+p;
	temp->pre=(*vivek);
	(*vivek)=temp;
}
int pop(node **vivek,int p)
{
	if(((*vivek)->value)==-p)
	{       node *temp;
		temp=(*vivek)->pre;
		if(temp==NULL)
			return 1;
		temp->sum=temp->sum+p;
		free(*vivek);
		(*vivek)=temp;
		if(((*vivek)->sum)<=0)
		{
			return 0;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
node *pop1(node *s)
{
	node *t;
	t=s;
	s=s->pre;
	free(t);
	return s;
}
main()
{
	char a[10000];
	int b[1000],n,l,j,m,f;
	scanf("%d\n",&m);
	if(m==0)
		return 0;
	for(j=0;j<m;j++)
	{
		int x,i,p,t,c=1,flag=1,z=0,y=0;
		gets(a);
		l=strlen(a);
		for (z=0;z<l;z++)
		{
			b[y]=0;
			f=0;
			if(a[z]=='-')
			{
				z++;
				f=1;
			}
			while(a[z]!=' ')
			{
				if(a[z]=='\0')
					break;
				b[y]=b[y]*10+a[z]-48;
				z++;
			}
			if(b[y]==0)
				continue;
			if(f==1)
				b[y]=-b[y];
			y++;
		}
		p=y;
		node *vivek;
		if(p%2==1)
		{
			printf("no\n");
			while(vivek!=NULL)
				vivek=pop1(vivek);
			continue;
		}
		for(i=0;i<p;i++)
		{
			t=b[i];
			if(b[i]>=0)
			{
				push(&vivek,t);
			}
			else
			{
				if(vivek==NULL)
					c=0;
				else
					c=pop(&vivek,t);
			}
			if(c==0)
			{
				printf("no\n");
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("yes\n");
		}
		if(vivek!=NULL)
		{
			while(vivek!=NULL)
				vivek=pop1(vivek);
		}
	}
}

