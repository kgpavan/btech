#include<stdio.h>
#include<math.h>
main()
{
	int t;
	scanf("%d",&t);
	int n,count,k,y,a,z,i,j,h;
	for(j=0;j<t;j++)
	{
		count=0;
	scanf("%d",&n);
	h=n;
	while(h<2147483647 && count<1000)
	{
		int x=0;
		int sum=0;
		a=h;
		k=a;
		while(k>0)
		{
			k=k/10;
			x++;
		}
		for(i=x;i>0;i--)
		{
			y=a%10;
			a=a/10;
			z=(pow(10,i-1))*y;
			sum=sum+z;
		}

		if(h+sum==2*h && (h!=n))
			break;
		else
		{
			h=h+sum;
			count++;
		}
	}
	printf("%d %d\n",count,h);
}
}
