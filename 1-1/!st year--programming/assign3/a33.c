#include<stdio.h>
main()
{
	int n,i,j,k,p,r,l,m,t;
	scanf("%d",&n);
	int a[n],b[n];
	for(k=0;k<n;k++)
	{
		scanf("%d",&m);
		for(t=0;t<m-1;t++)
		{
			scanf("%d ",&a[t]);
		}
		for(j=0;j<m-1;j++)
			b[j]=abs((a[t])-(a[t+1]));
		p=1;
		while(p<=n-1)
		{
			r=0;
			for(j=0;j<m;j++)
			{
				if(b[j]==p)
				{
					r++;
					break;
				}

			}

		}
		if(r=n-1)
		{
			printf("Jolly");
/bin/bash: wq: command not found
		else
		{
			printf("Not Jolly");
		}
	}
}

