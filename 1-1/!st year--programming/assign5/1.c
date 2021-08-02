#include<stdio.h>
main()
{
	int m,n,p,i,j,k,l,c;
	scanf("%d %d %d",&m,&n,&p);
	int a[1000][1000],b[1000][1000];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(k=0;k<n;k++)
	{
		for(l=0;l<p;l++)
		{
			scanf("%d",&b[k][l]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(l=0;l<p;l++)
		{
			int sum=0;
			for(j=0;j<n;j++)
			{
				c=(a[i][j]*b[j][l]);
				sum=sum+c;
			}
																			printf("%d ",sum);
		}
	}
}

