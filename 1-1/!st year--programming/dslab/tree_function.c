#include"tree.h"
#include<malloc.h>
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
nodeptr findmin(bst t)
{
	if(t==NULL)
	{
		printf("Invalid \n");
		return t;
	}
	else
	{
		if(t->left!=NULL)
			return findmin(t->left);
		else
			return t;
	}
}
nodeptr findmax(bst t)
{
	if(t==NULL)
	{
		printf("Invalid \n");
		return t;
	}
	else
	{
		if(t->right!=NULL)
			return findmax(t->right);
		else
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
nodeptr del(int val,bst t)
{
	bst temp;
	if(t==NULL)
		printf("error\n");
	else if(t->item>val)
		t->left=del(val,t->left);
	else if(t->item<val)
		t->right=del(val,t->right);
	else
	{
		if( t->left!=NULL && t->right!=NULL )
		{
			temp=findmin(t->right);
			t->item = temp->item;
			t->right = del(temp->item,t->right);
			free(temp);
		}
		else
		{
			bst z;
			z=t;
			if( t->left==NULL)
			{
				t=t->right;
				free(z);
			}
			else
			{
				t=t->left;
				free(z);
			}
		}
	}
	return t;
}
