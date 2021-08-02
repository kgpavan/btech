#include<stdio.h>
main()
{
	int n,i,j,k,p,r;
	scanf("%d",&n);
	int a[n],b[n];
		for(k=0;k<n;k++)
		scanf("%d ",a[k]);
	for(j=0;j<n;j++)
		b[j]=abs((a[i])-(a[i+1]));
	p=1;
	while(p<n-1)
	{
		for(j=0;j<n;j++)
		{
			r=0;
		if(b[j]==p)
		{
			r++;
			break;
		}

		}
	}
	if(r>0)
	{
		printf("Jolly");
	}
	else
	{
		printf("Not Jolly");
	}
}

