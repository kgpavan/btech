#include<iostream>
using namespace std;

class node{
	public:
	int element;
	node *left,*right;
	node();

};
node::node()
{
	right=NULL;
	left=NULL;
}
class tree {
	public:
	    void insert(int,node**);
	    void del(int,node**);
	    void find(int,node**);
};
class tree T;
void tree::insert(int value,node **t)
{
	if(*t==NULL)
	{	
		node *temp;
	//	temp=(node *)malloc(sizeof(tree));
		temp=new node;
		temp->element=value;
		temp->left=NULL;
		temp->right=NULL;
		*t=temp;
	}
	else if((*t)->element > value)
	{
		insert(value, &((*t)->left));
	}
	else if((*t)->element < value)
	{
		insert(value, &((*t)->right));
	}
}

node *findmin(node *t)
{
	if (t==NULL)
	{
		printf("underflow\n");
		return t;
	}
	else
	{
		node *temp=(t);
		while (temp->left!=NULL)
			temp=temp->left;
		printf("%d\n", temp->element);
		return t;
	}
}

node *findmax(node *t)
{
	if (t==NULL)
	{
		printf("underflow\n");
		return t;
	}
	else
	{
		node *temp=(t);
		while (temp->right!=NULL)
			temp=temp->right;
		printf("%d\n", temp->element);
		return t;
	}
}

void tree::del(int value,node **t)
{
	if((*t)==NULL)
		printf("%d not found in the tree\n",value);
	else if( (*t)->element > value)
	{
		del(value, &((*t)->left));
	}
	else if( (*t)->element < value)
	{
		del(value, &((*t)->right));
	}
	else if((*t)->element==value)
	{
	 if((*t)->left!=NULL && (*t)->right!=NULL)
	 {
		 node *temp;
		 temp=(*t)->right;
		 while(temp!=NULL)
			 temp=temp->left;
		 (*t)->element=temp->element;
		 del(temp->element,&((*t)->right));
	 }
	 if((*t)->left!=NULL && (*t)->right==NULL)
	 {
		 node *temp;
		 temp=(*t)->right;
		 while(temp!=NULL)
			 temp=temp->right;
		 (*t)->element=temp->element;
		 del(temp->element,&((*t)->left));
	 }
	if ((*t)->left==NULL && (*t)->right==NULL);
	{	
	;
	}
	if((*t)->right!=NULL && (*t)->left==NULL)
	{		
		node *temp;
		temp=(*t)->right;
		while(temp!=NULL)
			temp=temp->left;
		(*t)->element=temp->element;
		del(temp->element,&((*t)->right));
	}
	}
}
int hei(node *t)
{
int x,y;
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		x=1+hei(t->left);
		y=1+hei(t->right);
		if(x>y)
			return x;
		return y;
	}
}
	
void tree::find(int value,node **t)
{
	node *temp;
	temp=*t;
	if(temp==NULL)
		printf("not found\n");
	else if(temp->element > value)
	{
		find(value, &(temp->left));
	}
	else if(temp->element < value)
	{
		find(value, &(temp->right));
	}
	else 
		printf ("value found =%d\n",temp->element);
}
void printinorder(node **t)
{
	if((*t))
	{
		printinorder(&((*t)->left));
		printf("%d\n",(*t)->element);
		printinorder(&((*t)->right));
	}

}
void printpostfix(node **t)
{
	if((*t)->left)
		printpostfix(&((*t)->left));
	if((*t)->right)
		printpostfix(&((*t)->right));
	printf("%d\n",(*t)->element);
}
int g=0;
void    storepre(node *root,int a[])
{

	if(root)
	{
		a[g]=root->element;
		g++;

		storepre(root->left,a);
		storepre(root->right,a);
	}
}
int g1=0;
void storein(node *root,int a[])
{
	if(root)
	{
		storein(root->left,a);
		a[g1]=root->element;
		g1++;
		storein(root->right,a);
	}
}
int ji=0;
int arr[100];
void pre(node *t)
{
	if(t!=NULL)
	{
		arr[ji++]=t->element;
		pre(t->left);
		pre(t->right);
	}
}
void kth(node *t,int k)
{
	pre(t);
	ji=0;
	cout<<"Element is "<<arr[k-1];
}
node *insert (int value,node *t)
{
	if(t==NULL)
	{
		t=(node *)malloc(sizeof(node));
		t->element=value;
		t->left=NULL;
		t->right=NULL;
		return t;
	}
	else if(t->element>value)
	{
		t->left=insert(value,t->left);
	}
	else
	{
		t->right=insert(value,t->right);
	}
	return t;
}
void    printpre(node *root)
{
	if(root)
	{
		printf("%d ",root->element);
		printpre(root->left);
		printpre(root->right);
	}
}
void comp(void)
{
	node *t,*r;
	t=NULL;
	int l1,l2,i,n;
	printf("enter no of element\n");
	scanf("%d",&l1);
	for(i=1;i<=l1;i++)
	{
		scanf("%d",&n);
		t=insert(n,t);
	}

	int p1[100],p2[100],i1[100],i2[100];
	storepre(t,p1);
	storein(t,i1);

	t=NULL;
	r=NULL;
	printf("enter no .of emlemnt\n");
	scanf("%d",&l2);
	for(i=1;i<=l2;i++)
	{
		scanf("%d",&n);
		r=insert(n,r);
	}
	printpre(r);
	g=0;g1=0;
	storepre(r,p2);
	storein(r,i2);
	int flag=0;
	for(i=0;i<l1;i++)
	{
		if(p1[i]==p2[i] && i1[i]==i2[i])
			flag=1;
		else {printf("\nno\n");flag=0;break;}
	}
	if(flag==1)
		printf("\nyes\n");

}


main()
{
	node *t=NULL;
	node *r=NULL;
	int x,y;
	do
	{
		printf("1-INSERT 2-DELETE 3-FIND 0-EXIT 4-PRINT POST 5-PRINT IN 6-FIND HEIGHT\n");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1: scanf("%d",&y);
				T.insert(y,&t);
				break;
			case 2: scanf("%d",&y);
				T.del(y,&t);
				break;
			case 3: scanf("%d",&y);
				T.find(y,&t);
				break;
			case 0: break;
			case 4: scanf("%d",&y);
				printpostfix(&t);
				break;
			case 5:	printinorder(&t);
				break;
			case 6:printf("%d\n",hei(t));
			       break;
			case 7:cin>>y;
			       kth(t,y);
			       break;
			case 8:comp();
		}
	}while(x!=0);
}
