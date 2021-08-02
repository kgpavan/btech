#include<stdio.h>
main()
{
	int n,k,m,t,b,c,sum;
	    scanf("%d",&n);
	int a[n];
	for(k=0;k<n;k++)
	{
		sum=0;
		scanf("%d",&m);
		for(t=0;t<m;t++)
		{
			scanf("%d",&a[t]);
		}
		for(t=0;t<(m-1);t++)
		{
			b=abs((a[t+1])-(a[t]));
			sum=sum+b;
		}
	c=sum;
	if(c==((m*(m-1))/2))
		printf("Jolly\n");
	else
	printf("Not Jolly\n");
	}
}
