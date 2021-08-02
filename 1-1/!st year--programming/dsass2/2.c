#include<stdio.h>
#include<stdlib.h>
struct queue{
	int item;
	struct queue *next;
	struct queue *prev;
};
struct queue *front;
struct queue *rear;
void insert(int x,int ele)
{
	struct queue *temp;
	temp=(struct queue*)malloc(sizeof(struct queue));
	temp->item=x;
	if (front==NULL)
	{
		rear=temp;
		front=temp;
	}
	else
	{
		temp->next=rear;
		rear->prev=temp;
		rear=temp;
		if(ele==2)
			front->prev=temp;
	}
}
void reverse(int x)
{
	int i,t;
	struct queue *temp,*temp2;
	temp=(struct queue*)malloc(sizeof(struct queue));
	temp2=(struct queue*)malloc(sizeof(struct queue));
	temp=rear;
	temp2=front;
	for(i=0;i<x/2;i++)
	{
		t=temp->item;
		temp->item=temp2->item;
		temp2->item=t;
		temp=temp->next;
		temp2=temp2->prev;
	}
}
int delete()
{
	int temp;

	if(front==rear)
	{
		temp = front->item;
		front=NULL;
		rear=NULL;
		return temp;
	}
	else if(front!=NULL)
	{
		temp=front->item;
		front=front->prev;
		return temp;
	}

}
main()
{
	int g,t=0,j=0,m=0;
	char a,ch;
	while((ch=getchar())!=EOF)
	{
		if(ch=='E')
		{
			a=getchar();
			t++;
			scanf("%d",&g);
			insert(g,t);
		}
		else if(ch=='R')
		{
			reverse(t);
		}
		else if(ch=='D')
		{
			a=getchar();
			m++;
			if(front)
			{
			t--;
			printf("%d ",delete());
			}
			else
				printf("E ");
		}
		j++;
	}
	if(m!=0)
		printf("\n");

}


