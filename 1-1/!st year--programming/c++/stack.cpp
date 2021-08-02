#include<iostream.h>
#include<stdio.h>
#include<malloc.h>
struct node
{
	int item;
	node *next;
};
class stack 
{
	private :
			node *s;	
	public  :
		stack()
		{
			s=NULL;
		}
		void push(int val)
		{
			node *temp=new node;
			temp->item=val;
			temp->next=s;
			s=temp;
		}
		int pop()
		{
			int x=s->item;
			s=s->next;
			return x;
		}
		void display()
		{
			node *temp=s;
			while(temp!=NULL)
			{
				printf("%d ",temp->item);
				temp=temp->next;
			}
		}
};
main()
{
	stack s;
	int in=1;
	while(in!=4)
	{
		printf("\n1 for push\n2 for pop\n3 for display\n4 for exit\n");
		if(in==4)
			break;
		printf("Enter your choice:");
		scanf("%d",&in);
		if(in==1)
		{
			int x;
			scanf("%d",&x);
			s.push(x);	
		}
		else if(in==2)
		{
			int t=s.pop();
			printf("value poped is:%d\n",t);
		}
		else if(in==3)
		{
			s.display();
		}
	}

}
