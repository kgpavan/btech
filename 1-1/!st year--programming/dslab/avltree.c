#include<stdio.h>
#include<malloc.h>
typedef struct avlnode
{
	int data, height;
	struct avlnode *left, *right;
}AVL_Tree;
void SRWR(AVL_Tree **);
void SRWL(AVL_Tree **);
void DRWR(AVL_Tree **);
void DRWL(AVL_Tree **);
int Height(AVL_Tree *);
void insert(AVL_Tree **, int);
void insert( AVL_Tree **T, int x )
{
	if((*T)==NULL)
	{
		(*T)=malloc(sizeof(AVL_Tree));
		(*T)->data=x;
		(*T)->height=0;
		(*T)->left=(*T)->right=NULL;
	}
	else if(x < (*T)->data)
	{
		insert( &((*T)->left), x );
		if(Height((*T)->left) - Height((*T)->right)==2)
		{
			if(x < (*T)->left->data)
				SRWL( &(*T) );
			else
				DRWL( &(*T) );
		}
	}
	else if(x > (*T)->data)
	{
		insert((&(*T)->right), x );
		if( Height( (*T)->right ) - Height( (*T)->left )==2 )
		{
			if( x > (*T)->right->data )
				SRWR( &(*T) );
			else
				DRWR( &(*T) );
		}
	}
	int n,m;
	n=Height( (*T)->left );
	m=Height( (*T)->right );
	if(n>m)
		(*T)->height=n+1;
	else
		(*T)->height=m+1;
}

void SRWL( AVL_Tree **k2 )
{
	AVL_Tree *k1;
	k1=(*k2)->left;
	(*k2)->left=k1->right;
	k1->right=*k2;
	*k2=k1;
}

void SRWR( AVL_Tree **k2 )
{
	AVL_Tree *k1;
	k1=(*k2)->right;
	(*k2)->right=k1->left;
	k1->left=*k2;
	*k2=k1;
}

void DRWL( AVL_Tree **k3 )
{
	SRWR( &((*k3)->left) );
	SRWL( &(*k3) );
}

void DRWR( AVL_Tree **k3 )
{
         SRWL( &((*k3)->right ));
         SRWR( &(*k3) );
} 

int Height( AVL_Tree *T )
{
	if( T==NULL )
		return -1;
	if( T->left==NULL && T->right==NULL )
		return 0;
	else
	{
		int l=Height(T->left);
		int r=Height(T->right);
		if(l>r)
			return l+1;
		else
			return r+1;
	}
}

void inorder_traversal( AVL_Tree *T )
{
     if(T!=NULL)
     {
                inorder_traversal( T->left );
                printf("%d ",T->data);
                inorder_traversal( T->right );
     }               
}

void preorder_traversal( AVL_Tree *T )
{
	if(T!=NULL)
	{
		printf("%d ",T->data);
		preorder_traversal( T->left );
		preorder_traversal( T->right );
	}
}
void postorder_traversal( AVL_Tree *T )
{
	if(T!=NULL)
	{
		postorder_traversal( T->left );
		postorder_traversal( T->right );
		printf("%d ",T->data);
	}
}		
int main()
{
    int i,j,number_elements,num;
    AVL_Tree *avl_tree=NULL;
    printf("Enter the number of elements to be inserted in the AVL tree :");
    scanf("%d",&number_elements);
    i=0;
    printf("Enter the elements :");
    while( i < number_elements )
    {
           scanf("%d",&num);
           insert( &avl_tree, num );
           i++;
    }
    printf("Inorder Traversal of AVL Tree is :");
    inorder_traversal( avl_tree );
    printf("\n");
    printf("Preorder Traversal of AVL Tree is :");
    preorder_traversal( avl_tree );
    printf("\n");
    printf("Postorder Traversal of AVL Tree is :");
    postorder_traversal( avl_tree );
    printf("\n");
    return 0;
}


