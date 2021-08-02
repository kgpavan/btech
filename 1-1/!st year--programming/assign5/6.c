#include<stdio.h>
#include<math.h>
main()
{
	int n,i,j,w1,w2,min1,min2;
	    scanf("%d",&n);
	double lat[n],log[n],c[n][n],d;
	for(i=0;i<n;i++)
		scanf("%lf %lf",&lat[i],&log[i]);
	for(i=0;i<n;i++)
	{
		lat[i]=((lat[i]*22)/(7*180));
		log[i]=((log[i]*22)/(7*180));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			d=(acos((sin(lat[i])*sin(lat[j]))+(cos(lat[i])*cos(lat[j])*cos(log[i]-log[j]))))*6371;
			c[i][j]=d;
	printf("%0.3lf",d);
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
min1=1000000;
min2=1000000;
for(j=0;j<n;j++)
{
	if(c[i][j]!=0.000)
	{
		if(c[i][j]<min1)
		{
			w1=j;
			min1=c[i][j];
		}
	}
}
for(j=0;j<n;j++)
{
	if(c[i][j]!=0.000)
	{
		if(c[i][j]<min2 && j!=w1)
		{
			w2=j;
			min2=c[i][j];
		}
	}
}
printf("%d %d\n",w1,w2);
}
}
