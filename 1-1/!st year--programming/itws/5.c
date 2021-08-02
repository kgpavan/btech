//implement a simple binary search
// the array is already sorted 
#include<stdio.h>
main()
{
	int n,flag,i,x;
	    scanf("%d",&n);
	    int a[n];
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
int input;
scanf("%d",&input);
for(i=0;i<n;i++)
{
	if(input==a[i])
	{
		flag=1;
		x=i;
		break;
	}
	else 
	{
		flag=0;
		continue;
	}
}
if(flag==1)
{
	printf("the output is  %d",x+1);
}
else
{
	printf("not found");
}
}

		
