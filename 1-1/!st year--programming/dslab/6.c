#include<stdio.h>
#include<malloc.h>
struct treenode
{
	int item;
	struct treenode *left;
	struct treenode *right;
};
typedef struct treenode *nodeptr;
typedef struct treenode *bst;
nodeptr find(int num,bst t)
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
nodeptr insert(int val,bst t)
{
	if(t==NULL)
	{
		t=(nodeptr)malloc(sizeof(struct treenode));
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
main()
{
	int i,a[10000];
	bst t=NULL;
		for(i=0;i<9;i++)
		{
			scanf("%d",&a[i]);
			insert(a[i],t);
		}
	int b,c;
	scanf("%d",&b);
	scanf("%d",&c);
	int d=t->item;
		while((t->item!=b && t->item!=c) && ((t->item<b && t->item<c) || (t->item>b && t->item>c)))
		{
			d=t->item;
			if(t->item<b && t->item<c)
			{
				t=t->right;
			}
			else
				t=t->left;
		}
	if(t->item==b || t->item==c)
		printf("%d",t->item);
	else
		printf("%d",d);
}
