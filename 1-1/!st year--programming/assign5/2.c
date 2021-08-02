#include<stdio.h>
main()
{
	int n,r,s,i,j;
	scanf("%d",&n);
	int c,d,a[n][n],b[n][n],q[n][n];
	scanf("%d",&c);
	for(i=0;i<c;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d",&d);
	for(i=0;i<d;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			q[i][j]=0;
		}
	}
for(i=0;i<c;i++)
{
	for(j=0;j<d;j++)
	{
		if(a[i][1]==b[j][0])
		{
			a[i][0]=r;
			b[j][1]=s;
			q[r][s]=/*(q[r][s]+*/(a[i][2]*b[j][2]);
		}
//	printf("%d %d %d\n",r,s,q[r][s]);
	}
	printf("%d %d %d\n",r,s,q[r][s]);
}
/*for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(q[i][j]!=0)
		{
			printf("%d %d %d\n",i,j,q[i][j]);
		}
	}
}*/
}
