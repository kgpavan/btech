#include<stdio.h>
main()
{
	int n,i,j,k,p,r,l,m,t;
	scanf("%d",&n);
	int a[n],b[n];
	for(k=0;k<n;k++)
	{	
		
		scanf("%d",&m);
		for(t=0;t<m;t++)
		{
			scanf("%d ",&a[t]);
		}
		for(t=0;t<n;t++)
		{	for(j=0;j<m-1;j++)
		
			b[j]=abs((a[t])-(a[t+1]));}
		p=0;
		while(p<=n-1)
		{r=0;
			
			for(j=p;j<m;j++)
			{
				if((b[p]==b[j])||b[p]<n)
				{	printf("Not Jolly");
					r++;
					break;
				}

			}if(r==1)
			break;

		}
		if(r==0)
			printf("Jolly");
		else if(r==1)
			printf("Not Jolly");
	}
}

