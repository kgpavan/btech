#include<stdio.h>
main()
{
	int n,i,j,k,p,r,l,m,t,sum;
	scanf("%d",&n);
	int a[n],b[n];
	for(k=0;k<n;k++)
	{sum=0;	
		
		scanf("%d",&m);
		for(t=0;t<(m-1);t++)
		{
			scanf("%d ",&a[t]);
		}
		for(t=0;t<m;t++)
		{//	for(j=0;j<m-1;j++)
		//	{
		
			b[j]=abs((a[t+1])-(a[t]));
			sum=sum+b[j];
		//	}
			
		}
	
if(sum==((m*(m-1))/2))
	printf("Jolly");
else
	printf("Not Jolly");
}
}
