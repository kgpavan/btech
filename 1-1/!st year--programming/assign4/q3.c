#include<stdio.h>
main()
{
	int m,n,l,j,k,max,i,t,o,y;
	scanf("%d",&o);
	for(y=1;y<=o;y++)
	{
	scanf("%d %d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(t=0;t<n;t++)
		{
			scanf("%d",&a[i][t]);
		}
	}
	for(j=0;j<m;j++)
	{
		for(l=0;l<n;l++)
		{
			max=a[j][l];
			for(i=0;i<m;i++)
			{
				if(a[i][l]>max)
				{
					max=a[i][l];
					break;
				}
			}
			if(max==a[j][l])
			{
				for(k=0;k<n;k++)
					printf("%d ",a[j][k]);
				printf("\n");
				break;
			}
		}
	}
}
}
