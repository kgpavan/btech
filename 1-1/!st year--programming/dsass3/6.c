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
		insert(val,&((*t)->right));
	else if((*t)->item<val)
		insert(val,&((*t)->left));
}
void inorder_traversal( tree *T )
{
     if(T!=NULL)
     {
                inorder_traversal( T->left );
                printf("%d ",T->item);
                inorder_traversal( T->right );
     }               
}

void preorder_traversal( tree *T )
{
	if(T!=NULL)
	{
		printf("%d ",T->item);
		preorder_traversal( T->left );
		preorder_traversal( T->right );
	}
}
void postorder_traversal( tree *T )
{
	if(T!=NULL)
	{
		postorder_traversal( T->left );
		postorder_traversal( T->right );
		printf("%d ",T->item);
	}
}
int depth(tree *t)
{
	int x=0,y=0;
	if(t)
	{
		x=1+depth(t->left);
		y=1+depth(t->right);
	}
	if(x<y)
	{
		x=y;
	}
	return x;
}
levorder(tree *t,int lev)
{
	if(t==NULL)
		return;
	if(lev==0)
		printf("%d ",t->item);
	else if(lev>0)
	{
		levorder(t->left,lev-1);
		levorder(t->right,lev-1);
	}
}
levelprint(tree*t)
{
	int i;
	for(i=0;i<=depth(t);i++)
		levorder(t,i);
}
main()
{
	tree *t;
	t=NULL;
	int i,q,w,flag;
	char c,d;
	while(1)
	{
		scanf("%d",&q);
		c=getchar();
	//	insert(q,&t1);
		if(c=='\n')
			break;
	}
	while(1)
	{
		scanf("%d",&w);
		d=getchar();
		insert(w,&t);
		if(d=='\n')
			break;
	}
	inorder_traversal(t);
	printf("\n");
	preorder_traversal(t);
	printf("\n");
	postorder_traversal(t);
	printf("\n");
	levelprint(t);
	printf("\n");
}


