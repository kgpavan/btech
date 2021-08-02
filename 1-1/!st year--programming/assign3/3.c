#include<stdio.h>
main()
{
	int n,i,j,k,p,r,l,m,t;
	scanf("%d",&n);
	int a[n],b[n];
		for(k=0;k<n;k++)
		{
			r=0;
			scanf("%d",&m);
			for(t=0;t<m-1;t++)
			{
		scanf("%d ",&a[t]);
			}
	for(j=0;j<m;j++)
		b[j]=abs((a[t])-(a[t+1]));
	for (j=0;j<n-1;j++)
	p=1;
	while(p<n-1)
	{
			for(j=0;j<m;j++)
			{
		if(b[j]==p)
		{
			r++;
			
		}
		
			}

	}
	if(r==n-1)
	{
		printf("Jolly");
	}
	else
	{
		printf("Not Jolly");
	}
}
}

