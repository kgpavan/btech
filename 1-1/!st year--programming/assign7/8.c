#include<stdio.h>
#include<math.h>
long int fac(int x)
{
	int f=1;
	int i;
	for(i=x;i>=1;i--)
		f=f*i;
	return f;
}
float mysine(float x)
{
	float a,s1=0,s2=0,b;
	int i=1;
	//while (a>0.000001)
	while(i<50)
	{

		float num=pow(x,i);
        	long int   den=fac(i);
		a=num/den;
		s1=s1+a;
		i=i+4;
	}
	i=3;
	//while (b>0.000001)
	while(i<50)
	{

		float num=pow(x,i);
		long int  den=fac(i);
		b=num/den;
		s2=s2+b;
		i=i+4;
	}
        float k=s1-s2;
	return k;
}
main()
{
	int x;
	float y;
	scanf("%d",&x);
	x=x*22/(7*180);
	y=mysine(x);
	printf("%f",y);
}
	



