#include<stdio.h>
#include<malloc.h>
typedef struct tree
{
	int item;
	struct tree *left;
	struct tree *right;
}tree;
int count=0;
int b[1000000];
void insert(int val,tree **t)
{
	if((*t)==NULL)
	{
		(*t)=(tree*)malloc(sizeof(tree));
		(*t)->item=val;
	//	printf("%d",val);
		b[count]=val;
		count++;
		(*t)->left=NULL;
		(*t)->right=NULL;
	}
	else if((*t)->item==val)
		return;
	else if((*t)->item>val)
		insert(val,&((*t)->left));
	else if((*t)->item<val)
		insert(val,&((*t)->right));
}
main()
{
	tree *t;
	t=NULL;
	int i,n,a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		insert(a,&t);
	}
	for(i=0;i<count;i++)
		printf("%d ",b[i]);
	printf("\n");
}

