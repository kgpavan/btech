#include<stdio.h>
#include<math.h>
main()
{
	float d,sum1=0,sum2=0,a,b,y,x,t,v,s,c,n;
	int i,j,g;
	scanf("%f",&d);
	int k[g];
	for(i=0;i<=d;i++)
	{
		scanf("%d",&k[i]);
	}
	scanf("%f %f %f",&a,&b,&n);
	for(j=d;j>=0;j--)
	{
		t=(k[j]*(pow(a,j)));
                sum1=sum1+t;
	}
	for(j=d;j>=0;j--)
	{
		v=(k[j]*(pow(b,j)));
		sum2=sum2+v;
	}
        for(y=1;y<=(n-1);y++)
	{
		x=(a+((y*(b-a))/n));
	}
	c=x;
	s=(((b-a)/n)*(((sum1+sum2)/2)+c));
	printf("%f",s);
}
