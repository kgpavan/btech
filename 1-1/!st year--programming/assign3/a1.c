#include<stdio.h>
#include<math.h>
main()
{
	float d,sum1=0,sum2=0,y,x,t,v,s,c,q,sum=0,K,h,a,b,n;
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
		t=(k[j]*(pow(a,d-j)));
                sum1=sum1+t;
	}
	for(j=d;j>=0;j--)
	{
		v=(k[j]*(pow(b,d-j)));
		sum2=sum2+v;
	}
	for(K=1;K<n;K++)
	{
		h=((K*(b-a))/n);
		for(j=d;j>=0;j--)
		{
			q=(k[j])*(pow((a+h),d-j));
sum=sum+q;		
	}
	}
	c=sum;
	s=(((b-a)/n)*(((sum1+sum2)/2.00)+c));
	printf("%.2f",s);
}
