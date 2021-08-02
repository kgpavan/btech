#include<stdio.h>
double po(double a,double b)
{
	double pro=1,i;
	for(i=1;i<=b;i++)
	{
		pro=pro*a;
	}
	return pro;
}
 double fac(double x)
{
	double  f=1,i;
	for(i=x;i>=1;i--)
		f=f*i;
	return f;
}
double mysin(double x)
{
	double sum=0,g;
	double k=0;
	while(k<15)
	{
		g=(po(-1,k)*po(x,2*k+1))/fac(2*k+1);
		sum=sum+g;
		k++;
	}
	return sum;
}
double mycos(double x)
{
	double sum=0,g;
	double k=0;
	while(k<15)
	{
		g=(po(-1,k)*po(x,2*k))/fac(2*k);
		sum=sum+g;
		k++;
	}
	return sum;
}
main()
{
	int x;
	scanf("%d",&x);
	double y;
	y =((x*22.0)/(7.0*180.0));
	double a,b,c;
	a=mysin(y);
	b=mycos(y);
	c=a/b;
	printf("%.4lf %0.4lf %0.4lf",a,b,c);
}

