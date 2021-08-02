#include<stdio.h>
#include<math.h>
main()
{
int n,i,j,c,d,e,sum,l,k,z,y;
float m,q;
scanf("%d",&n);
int a[n],b[n];
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
for(j=0;j<n;j++)
	scanf("%d",&b[j]);
for(i=0,j=0;i<n,j<n;i++,j++)
{
	c=a[i]+b[j];
	 printf("%d ",c);
}
printf("\n");
for(i=0,j=0;i<n,j<n;i++,j++)
{
	d=a[i]-b[j];
	printf("%d ",d);
}
printf("\n");
sum=0;
for(i=0,j=0;i<n,j<n;i++,j++)
{
e=a[i]*b[j];
sum=sum+e;
}
printf("%d\n",sum);
k=0;
for(i=0;i<n;i++)
{
l=(a[i]*a[i]);
k=k+l;
}
m=sqrt(k);
printf("%.3f\n",m);
z=0;
for(j=0;j<n;j++)
{
	y=(b[j]*b[j]);
z=z+y;
}
q=sqrt(z);
printf("%.3f\n",q);
printf("%.3f\n",(sum/(m*q)));
}
