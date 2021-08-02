#include<stdio.h>
#include<malloc.h>
typedef struct tree
{
	int item;
	int height;
	struct tree *left;
	struct tree *right;
}tree;
int max=0;
int Height(tree *t)
{
	if((t)==NULL)
		return -1;
	else if(t->left==NULL && t->right==NULL)
		return 0;
	else
	{
		int k=Height(t->left);
		int b=Height(t->right);
		if(k>b)
			return k+1;
		else
			return b+1;
	}
}
void insert(int val,tree **t)
{
	//      printf("val====",val);
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
	int l=Height((*t)->left);
	int m=Height((*t)->right);
	if(l>m)
		(*t)->height=l+1;
	else
		(*t)->height=m+1;
}
void diameter(tree *t)
{
	int k=Height(t->left)+Height(t->right)+3;
	if(k>max)
		max=k;
	 if(t->left!=NULL)
		diameter(t->left);
	 if(t->right!=NULL)
		diameter(t->right);
}

main()
{
	tree *t;
	t=NULL;
	int a;
	char c;
	while(1)
	{
		scanf("%d",&a);
		insert(a,&t);
		c=getchar();
			if(c=='\n')
				break;
	}
	int H=Height(t);
	printf("%d\n",H);
	diameter(t);
	printf("%d\n",max);
}
