#include<stdio.h>
#include<malloc.h>
#include "tree.h"
main()
{
	int n,value;
	bst t=NULL,x;
	while(1)
	{	printf("enter 1 to insert any number in the tree\n");
		printf("enter 2 to find any number.\n");
		printf("enter 3 to find minimum\n");
		printf("enter 4 to find maximum\n");
		printf("enter 5 to delete any number\n");
		printf("enter 6 to exit\n ");
		scanf("%d",&n);
		if(n==1)
		{
			printf("Enter the number to insert : ");
			scanf("%d",&value);
			t=insert(value,t);
		//	continue;
		}	
		if(n==2)
		{
			printf("Enter the number to find : ");
			scanf("%d",&value);
			find (value,t);
		}
		if(n==3)
		{//	printf("in min loop\n");
			x=findmin(t);
			if(x!=NULL)
				printf("%d\n",x->item);
		}
		if(n==4)
		{	x=findmax(t);
			if(x!=NULL)
				printf("%d\n",x->item);
		}
		if(n==5)
		{
			int value;
			printf("enter the number to be deleted : ");
			scanf("%d",&value);
			del(value,t);
			printf("the number is deleted\n");
		}
		if(n==6)
			break;
	}
}
