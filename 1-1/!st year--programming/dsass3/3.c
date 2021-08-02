#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct tree
{
	char data[1000];
	struct tree *left;
	struct tree *right;
	int depth;
}tree;
char a[1000];
void insert(char val[],tree **t)
{
	if((*t)==NULL)
	{
		(*t)=(tree*)malloc(sizeof(tree));
		strcpy((*t)->data,val);
//		printf("%s\n",(*t)->data);
	//	strcpy(val,(*t)->data);
		(*t)->depth=0;
		(*t)->left=NULL;
		(*t)->right=NULL;
	}
	else if(strcmp((*t)->data,val)>0)
	{
		insert(val,&((*t)->left));
		((*t)->left)->depth=(*t)->depth +1;
	}

	else if(strcmp((*t)->data,val)<0)
	{
		insert(val,&((*t)->right));
		((*t)->right)->depth=(*t)->depth +1;
	}
}
/*int depth(tree *t)
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
}*/

int inorder(tree *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%s ",t->data);
		printf("%d\n",t->depth);
		inorder(t->right);
	}
}
main()
{
	tree *t;
	t=NULL;
//	char a[1000];
	gets(a);
	int i,j=0;
	char arr[1000];
	int l=strlen(a);
//	for(i=0;i<l;i++)
//		printf("%c\n",a[i]);
//	printf("length=%d",l);
	for(i=0;i<l;i++)
	{
		j=0;
		while(a[i]!=' ' && a[i]!='\0')
		{
			arr[j]=a[i];
			j++;
			i++;
		}
		arr[j]='\0';
		insert(arr,&t);
	//	printf("%s\n",arr);

	//	insert(arr,tree *t);
			

	}
	inorder(t);
//	printf("%s",arr[0]);
//	for(i=0;i<j;i++)
//		printf("%s\n",arr[i]);
}
	
