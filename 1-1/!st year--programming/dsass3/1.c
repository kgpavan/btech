#include<stdio.h>
#include<malloc.h>
typedef struct tree
{
	int item;
	int height;
	struct tree *left;
	struct tree *right;
}tree;
int count=0;
int a[100000];
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
//	printf("val====",val);
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
/*void print_leaf(tree *t,int temp)
{
	if(t==NULL)
	{
		return ;
	}
	 if(temp==0)
	{
	

		printf("%d ",t->item);
		//count++;
	}
	else
	{
		print_leaf(t->left,temp-1);
		print_leaf(t->right,temp-1);
	}

}*/
void print_leaf(tree *t)
{
	if(t->left!=NULL)
		print_leaf(t->left);
	if(t->left==NULL && t->right==NULL)
	{
		a[count]=t->item;
		count++;
	}
	//	printf("%d",t->item);

	if(t->right!=NULL)
		print_leaf(t->right);
}

main()
{
	tree *t;
	t=NULL;
	int i,q;
	char c;
	while(1)
	{
		scanf("%d",&q);
		insert(q,&t);
		c=getchar();
		if(c=='\n')
			break;
	}

	//for(i=0;i<9;i++)
//	{//
//		scanf("%d",&q);
//	//	printf("%d",q);
//		insert(q,&t);
//	}

		
//int h=Height(t);
//printf("height=%d\n ",h);
print_leaf(t);
int j;
printf("%d ",count);
for(j=0;j<count;j++)
	printf("%d ",a[j]);
printf("\n");
}



