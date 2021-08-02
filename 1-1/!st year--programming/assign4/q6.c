#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
char a[32];
int i,b[32],sum1,c,sum2,sum3,sum4,d,e,f,j,n;
scanf("%d",&n);
for(j=0;j<n;j++)
{
scanf("%s",a);
for(i=0;i<32;i++)
	b[i]=a[i]-48;
sum1=0;
for(i=0;i<8;i++)
{
	c=(b[i]*(pow(2,(7-i))));
	sum1=sum1+c;
}
sum2=0;
for(i=8;i<16;i++)
{

	d=(b[i]*(pow(2,(15-i))));
	sum2=sum2+d;
}
sum3=0;
for(i=16;i<24;i++)
{

	e=(b[i]*(pow(2,(23-i))));
	sum3=sum3+e;
}
sum4=0;
for(i=24;i<32;i++)
{
	f=(b[i]*(pow(2,(31-i))));
	sum4=sum4+f;
}
	
printf("%d.%d.%d.%d\n",sum1,sum2,sum3,sum4);
}
}
