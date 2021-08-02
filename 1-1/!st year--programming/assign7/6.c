#include<stdio.h>
main()
{
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int index;
	scanf("%d",&index);
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==index)
		{
			printf("%d ",i);
			flag=1;
		}
	}
	if(flag==0)
		printf("does not occur");
}

