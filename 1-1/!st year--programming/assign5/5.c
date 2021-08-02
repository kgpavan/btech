#include<stdio.h>
#include<math.h>
main()
{
int n,k,g,d,c,r;
scanf("%d",&n);
while(n>0)
{
k=pow(n,0.5);
g=k*k;
if(g%2==0)
{
	d=n-g;
	if(d==0)
	{
		c=k;
		r=1;
	}
	else if(d<=k+1)
	{
		c=k+1;
		r=d;
	}
	else if(d>k+1)
	{
		r=k+1;
		c=(2*(k+1))-d;
	}
}
if(g%2==1)
{
	d=n-g;
	if(d==0)
	{
		r=k;
		c=1;
	}
	else if(d<=k+1)
	{
		r=k+1;
		c=d;
	}
	else if(d>k+1)
	{
		c=k+1;
		r=(2*(k+1))-d;
	}
}
printf("%d %d\n",c,r);
scanf("%d",&n);
}}
