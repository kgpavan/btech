#include<stdio.h>
#include<malloc.h>
typedef struct treenode
{
	int item;
	struct treenode *left;
	struct treenode *right;
}tree;
//typedef struct treenode *nodeptr;
//typedef struct treenode *bst;
typedef struct queue
{
	struct queue *next,*prev;
	int data;
}queue;
struct  queue *front=NULL,*rear=NULL;
tree * insert(int val,tree *t)
{
	if(t==NULL)
	{
		
		t=(tree*)malloc(sizeof(tree));
		t->item=val;
		t->left = NULL;
		t->right = NULL;
		
	}
	else if(t->item>val)
		t->left=insert(val,t->left);
	else if(t->item<val)
		t->right=insert(val,t->right);
	return t;
}
tree* find(int num,tree *t)
{
	if(t==NULL)
	{
		printf("Invalid \n");
		return t;
	}
	else
	{
		if(t->item>num)
			return find(num,t->left);
		if(t->item<num)
			return find(num,t->right);
		if(t->item==num)
			return t;
	}
}
void enqueue(int n)
{
	 queue *tmp=(queue *)malloc(sizeof (queue));
	
	tmp->data=n;
	tmp->prev=NULL;
	if(rear==NULL)
	{
		front=tmp;
		rear=tmp;
	}
	else
	{
		tmp->next=front;
		front->prev=tmp;
		front=tmp;
	}

}
int  dequeue()
{
	if(rear==NULL || front==NULL)
	{       printf("E ");
		return;
	}
	if(front==rear)
	{
		int yo= front->data;
		front=NULL;
		rear=NULL;
		return yo;
	}
	struct queue *tmp;
	tmp=rear;
	rear=rear->prev;
	if(rear==NULL)
		front=NULL;
	return tmp->data;
}
main()
{
	tree *t;
	t=NULL;
	int a,i;
	char q;
	while(1)
        {	
		scanf("%d",&a);
		t=insert(a,t);
		q=getchar( );
		if(q!=' ')
			break;
	}
	enqueue(t->item);

	struct treenode *temp=t;

	while(front!=NULL)
	{
		int x=dequeue();
		printf("%d ",x);
		temp=find(x,t);
		if(temp->left!=NULL)
		{
		enqueue(temp->left->item);
		}
		if(temp->right!=NULL)
		enqueue(temp->right->item);
		
	}
	printf("\n");
}

