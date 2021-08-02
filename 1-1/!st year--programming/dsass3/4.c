#include<stdio.h>
#include<malloc.h>
typedef struct tree
{
	int item;
	struct tree *left;
	struct tree *right;
}tree;
void insert(int val,tree **t)
{
	if((*t)==NULL)
	{
		(*t)=(tree*)malloc(sizeof(tree));
		(*t)->item=val;
		(*t)->left=NULL;
		(*t)->right=NULL;
	}
	else if((*t)->item>val)
		insert(val,&((*t)->left));
	else if((*t)->item<val)
		insert(val,&((*t)->right));
}
int check(tree *t1,tree *t2)
{
	if(t1!=NULL&&t2==NULL)
		return 0;
	else if(t1==NULL&&t2!=NULL)
		return 0;
	else if(t1==NULL&&t2==NULL)
		return 1;
	if(t1!=NULL&&t2!=NULL)
	{
		if(t1->item == t2->item)
		{
			int lr,rr;
			lr=check(t1->left,t2->left);
			rr=check(t1->right,t2->right);
			if(lr==1&&rr==1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
}
main()
{
	tree *t1;
	tree *t2;
	t1=NULL;
	t2=NULL;
	int i,q,w,flag;
	char c,d;
	while(1)
	{
		scanf("%d",&q);
		c=getchar();
		insert(q,&t1);
		if(c=='\n')
			break;
	}
	while(1)
	{
		scanf("%d",&w);
		d=getchar();
		insert(w,&t2);
		if(d=='\n')
			break;
	}
	/*for(i=0;i<9;i++)
	{
		scanf("%d",&q);
		//      printf("%d",q);
		insert(q,&t1);
	}
	for(i=0;i<9;i++)
	{
		scanf("%d",&w);
		insert(w,&t2);
	}*/
	flag=check(t1,t2);
	if(flag==0)
		printf("FALSE\n");
	else
		printf("TRUE\n");

}


