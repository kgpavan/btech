#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack{
	int value;
	int sum;
	struct stack *pre;
}node;
struct stack* push(node *s,int p)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->value=p;
	if(s==NULL)
		temp->sum=p;
	else
		temp->sum=(s)->sum+p;
	temp->pre=(s);
	(s)=temp;
	return(s);
}
int pop(node **s,int p)
{
	if(((*s)->value)==-p)
	{       node *temp;
		temp=(*s)->pre;
		if(temp==NULL)
			return 1;
		temp->sum=temp->sum+p;
		free(*s);
		(*s)=temp;
		if(((*s)->sum)<=0)
			return 0;
		return 1;
	}
	else
		return 0;
}
struct stack *pop1(node *s)
{
	node *t;
	t=s;
	s=s->pre;
	free(t);
	return s;
}
main()
{
	char a[40];
	struct stack *s;
	int b[25],n,l,j,m,f;
	scanf("%d\n",&m);
//	if(m==0)
//		return 0;
	for(j=0;j<m;j++)
	{
		(s)=NULL;
		int x,i,p,t;
		int c=1;
		int count=1;
		int z=0;
		int y=0;
		gets(a);
		l=0;
	//	int g;
	//	for(g=0;g<40;g++)
	//	{
			while(a[l]!='\0')
			{
				l++;
			}
		//	if(a[g]=='\0')
		//		break;
	//	}
		//l=strlen(a);
//		printf("%d",l);
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
		node *s;
		if(p%2!=0)
		{
			printf("no\n");
			while(s!=NULL)
				s=pop1(s);
			continue;
		}
		for(i=0;i<p;i++)
		{
			t=b[i];
			if(b[i]>=0)
				s=push(s,t);
			else
				if(s==NULL)
					c=0;
				else
					c=pop(&s,t);
			if(c==0)
			{
				printf("no\n");
				count=0;
				break;
			}
		}
		if(count==1)
			printf("yes\n");
	//	if(s!=NULL)
	//		while(s!=NULL)
	//			s=pop1(s);
	}
}

